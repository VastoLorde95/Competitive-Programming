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

const int N = 1<<18;

typedef long long ll;

ll MOD = 1e9 + 7;

struct node{
	ll hsh;
	void assign(ll value){
		hsh = value;
	}
	void combine(node &left, node &right){
		hsh = (left.hsh + right.hsh)%MOD;
	}
};

int n, m, k, base = 29, lazy[N];
ll a[N], p[N], sum[N];
node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	lazy[id] = -1;
	if(l+1 == r){
		tree[id].assign(0ll);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd(int id,int l,int r,int x){
	lazy[id] = x;	
	tree[id].assign((((sum[r]-sum[l]+MOD)%MOD)*x)%MOD);
}

void shift(int id,int l,int r){
	if(lazy[id] != -1){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = -1;
	}
}

// range update -> update(x, y, val);
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

ll query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].hsh;
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return (query(x, y, left, l, mid) + query(x, y, right, mid, r))%MOD;
}


char s[N];

int main(){
	sd3(n,m,k);
	scanf("%s", s);
	
	p[0] = 1;
	sum[0] = 1;
	
	build();
	
	for(int i = 1; i <= n; i++){
		p[i] = (p[i-1]*base)%MOD;
		sum[i] = (sum[i-1] + p[i])%MOD;
//		tr3(i, p[i], sum[i]);
	}
	
	for(int i = 0; i < n; i++) update(i,i+1,s[i]-'0');
	
	int q = m+k, t, l, r, c;
	while(q--){
		sd2(t,l); sd2(r,c);
		if(t == 1){
			l--;
			update(l,r,c);
		}
		else{
			if(c == r-l+1){
				puts("YES"); continue;
			}
			
			l--;
			if((query(l,r-c)*p[c])%MOD == query(l+c,r)) puts("YES"); else puts("NO");
		}
	}
	
	return 0;
}
