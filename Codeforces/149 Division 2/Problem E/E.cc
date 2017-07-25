#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int N = 1<<17;
const int M = 20;

struct node{
	int cnt[M+1];
	
	node(){
		memset(cnt, 0, sizeof cnt);
	}
	
	void assign(int value){
		for(int i = 0; i <= M; i++){
			if((value&(1<<i)) > 0) cnt[i]++;
		}
	}
	
	void combine(node &left, node &right){
		for(int i = 0; i <= M; i++) cnt[i] = left.cnt[i] + right.cnt[i];
	}
	
	long long val(){
		long long ret = 0;
		for(int i = 0; i <= M; i++) ret += (1ll*cnt[i])*(1<<i);
		return ret;
	}
};

int n, m, a[N], lazy[N];
node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd(int id,int l,int r,int x){
	lazy[id] ^= x;
	for(int i = 0; i <= M; i++)
		if((x&(1<<i)) > 0) tree[id].cnt[i] = (r-l)-tree[id].cnt[i];
}

void shift(int id,int l,int r){
	if(lazy[id]){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0;
	}
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

long long query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].val();
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return query(x, y, left, l, mid) + query(x, y, right, mid, r);
}


int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	build();
	
	int t, l, r, x;
	cin >> m;
	while(m--){
		cin >> t >> l >> r;
		l--;
		if(t == 1){
			cout << query(l, r) << '\n';
		}
		else{
			cin >> x;
			update(l, r, x);
		}
	}
		
	return 0;
}
