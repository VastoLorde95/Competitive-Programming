#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 1<<19;
long long MOD = 1e9 + 7;

struct node{
	long long x, y, z, sum;
	void assign(long long ind){
		x = (ind*ind)%MOD, y = (ind)%MOD, z = 1, sum = 0;
	}
	void update(long long a0, long long b0, long long c0){
		sum = (sum + a0*x + b0*y + c0*z)%MOD;
	}
	void combine(node &left, node &right){
		x = (left.x + right.x)%MOD;
		y = (left.y + right.y)%MOD;
		z = (left.z + right.z)%MOD;
		sum = (left.sum + right.sum)%MOD;
	}
};

int n, q, a[N], lazy1[N], lazy2[N], lazy3[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(l+1);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(int id,int l,int r, long long a, long long b, long long c){ //	update the current node and its index in the lazy array
	(lazy1[id] += a) %= MOD; (lazy2[id] += b) %= MOD; (lazy3[id] += c) %= MOD;
	tree[id].update(a, b, c);
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(lazy1[id] == 0 and lazy2[id] == 0 and lazy3[id] == 0) return;
	int mid = (l+r)/2;
	upd(id * 2, l, mid, lazy1[id], lazy2[id], lazy3[id]);
	upd(id * 2 + 1, mid, r, lazy1[id], lazy2[id], lazy3[id]);
	lazy1[id] = lazy2[id] = lazy3[id] = 0; // passing is done, reset the index in the lazy array
}

// range update -> update(x, y, val);
void update(int x, int y, long long a, long long b, long long c, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, a, b, c);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, a, b, c, left, l, mid);
	update(x, y, a, b, c, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
long long query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].sum;
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return (query(x, y, left, l, mid) + query(x, y, right, mid, r))%MOD;
}

int main(){
	sd2(n,q);
	build();
	while(q--){
		int t;
		sd(t);
		if(t == 1){
			long long x, y; scanf("%lld%lld",&x,&y);
			update(x-1, y, 1LL, (3LL-(2LL*x)+MOD)%MOD, (((x-1)*(x-2))+MOD)%MOD);
		}
		else{
			int x, y; sd2(x,y);
			printf("%lld\n", query(x-1,y));
		}
	}
	return 0;
}
