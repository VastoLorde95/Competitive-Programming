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

typedef long long ll;

int t, n, k, d, m;
long long a[5001], dp[5001][2][2], inf = 1e18;

const int N = 5001;

struct node{
	long long mx;
	void assign(ll value){
		mx = value;
	}
	void update(ll value){
		mx += value;
	}
	void combine(node &left, node &right){
		mx = max(left.mx, right.mx);
	}
};

long long lazy[5001][N];
node tree[5001][2*N];

// [l, r)
void build(int j, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[j][id].assign(0);
		return;
	}
	lazy[j][id] = 0;
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(j, left, l, mid); build(j, right, mid, r);
	
	tree[j][id].combine(tree[j][left], tree[j][right]);
	return;
}

void upd(int j, int id,int l,int r,ll x){
	lazy[j][id] += x;
	tree[j][id].update(x);
}

void shift(int j, int id,int l,int r){
	if(lazy[j][id] > 0){
		int mid = (l+r)/2;
		upd(j, id * 2, l, mid, lazy[j][id]);
		upd(j, id * 2 + 1, mid, r, lazy[j][id]);
		lazy[j][id] = 0;
	}
}

void update(int j, int x, int y, ll val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(j, id, l, r, val);
		return;
	}
	
	shift(j, id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(j, x, y, val, left, l, mid);
	update(j, x, y, val, right, mid, r);
	
	tree[j][id].combine(tree[j][left], tree[j][right]);
	return;
}

ll query(int j, int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[j][id].mx;
	
	shift(j, id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return max(query(j, x, y, left, l, mid), query(j, x, y, right, mid, r));
}


int main(){
	sd(t);
	while(t--){
		sd2(n,k); sd2(d,m);
		
		for(int i = 0; i < n; i++){
			scanf("%lld", a+i);
			dp[i][0][0] = dp[i][1][0] = 0;
			dp[i][0][1] = dp[i][1][1] = 0;
		}
		
		
		for(int i = 1; i <= k; i++){
			build(i);
		}
		
		dp[0][0][0] = a[0];
		
		for(int i = 1; i < n; i++){
			dp[i][0][0] = dp[i-1][0][0] + a[i];
		}
		
		for(int j = 1; j <= k; j++){
			int id = j&1;
			for(int i = j; i < n; i++){
				if(i-d <= 0){
					update(j, 0, i, a[i]*m);
				}
				else{
					update(j, i-d, i, a[i]*m);
					update(j, 0, i-d, a[i]);
				}
				dp[i][id][0] = query(j,0,i);
				dp[i][id][1] = max(dp[i-1][1-id][0], dp[i-1][1-id][1]);
				update(j,i,i+1,dp[i][id][1]);
			}
		}
		
		printf("%lld\n", max(dp[n-1][k%2][0], dp[n-1][k%2][1]));
		
	}
	return 0;
}
