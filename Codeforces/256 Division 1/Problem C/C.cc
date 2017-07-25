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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 1<<19;
int MOD = 1e9 + 9;

struct node{
	int sum;
	void assign(int value){
		sum = value;
	}
	void combine(node &left, node &right){
		sum = left.sum + right.sum;
		if(sum >= MOD) sum -= MOD;
	}
};

int n, m, a[N], t1[N], t2[N], f[N], sum[N];
node tree[2*N];

// [l, r)
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

// range update and  utility functions
void upd(int id, int l, int r, int x){ //	update the current node and its index in the lazy array
	int temp = sum[r-x]-sum[l-x];
	if(temp < 0) temp += MOD;
	tree[id].sum += temp;
	if(tree[id].sum >= MOD) tree[id].sum -= MOD;
	
	t1[id] += f[l-x+1]; if(t1[id] >= MOD) t1[id] -= MOD;
	t2[id] += f[l-x]; if(t2[id] >= MOD) t2[id] -= MOD;
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(t1[id] > 0 or t2[id] > 0){
		int left = id*2, right = left+1, mid = (l+r)/2;
		
		int tot = ((1ll*t1[id])*sum[mid-l])%MOD + ((1ll*t2[id])*sum[mid-l-1])%MOD;
		if(tot >= MOD) tot -= MOD;
	
		tree[left].sum += tot;
		if(tree[left].sum >= MOD) tree[left].sum -= MOD;
		t1[left] += t1[id]; if(t1[left] >= MOD) t1[left] -= MOD;
		t2[left] += t2[id]; if(t2[left] >= MOD) t2[left] -= MOD;
		
		int to1 = ((1ll*t1[id])*f[mid-l+1])%MOD + ((1ll*t2[id])*f[mid-l])%MOD;
		if(to1 >= MOD) to1 -= MOD;
		int to2 = ((1ll*t1[id])*f[mid-l])%MOD + ((1ll*t2[id])*f[mid-l-1])%MOD;
		if(to2 >= MOD) to2 -= MOD;
		
		t1[id] = to1, t2[id] = to2;
		
		tot = ((1ll*t1[id])*sum[r-mid])%MOD + ((1ll*t2[id])*sum[r-mid-1])%MOD;
		if(tot >= MOD) tot -= MOD;
		
		tree[right].sum += tot;
		if(tree[right].sum >= MOD) tree[right].sum -= MOD;
		t1[right] += t1[id]; if(t1[right] >= MOD) t1[right] -= MOD;
		t2[right] += t2[id]; if(t2[right] >= MOD) t2[right] -= MOD;
		
		t1[id] = t2[id] = 0;
	}
}

// range update -> update(x, y, val);
void update(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].sum;
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	int ret = query(x, y, left, l, mid) + query(x, y, right, mid, r);
	if(ret >= MOD) ret -= MOD;
	return ret;
}


int main(){
	f[1] = 1;
	for(int i = 2; i < N; i++){
		f[i] = f[i-1] + f[i-2];
		if(f[i] >= MOD) f[i] -= MOD;
	}
	
	for(int i = 1; i < N; i++){
		sum[i] = sum[i-1] + f[i];
		if(sum[i] >= MOD) sum[i] -= MOD;
	}
	
	sd2(n, m);
	
	for(int i = 0; i < n; i++) sd(a[i]);
	
	build();
	
	int type, l, r;
	while(m--){
		sd3(type, l, r);
		l--, r--;
		if(type == 1)
			update(l, r+1, l);
		else
			printf("%d\n", query(l, r+1));
	}
	
	return 0;
}
