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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef long long ll;

const int N = 1<<18;

ll dp[2][501], nxt[1001], inf = 1e17, tot;
int t, n, m, k, a[100100], v[100100], lazy[N];

struct node{
	ll mn;
	void assign(){
		mn = inf;
	}
	void update(ll val){
		mn = min(mn,val);
	}
	void combine(node &left, node &right){
		mn = min(left.mn, right.mn);
	}
};

node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	lazy[id] = inf;
	if(l+1 == r){
		tree[id].assign();
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd(int id,int l,int r,int x){
	lazy[id] = min(lazy[id], x);
	tree[id].update(x);
}

void shift(int id,int l,int r){
	int mid = (l+r)/2;
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = inf;
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

int query(int index, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		return tree[id].mn;
	}
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) return query(index, left, l, mid); else return query(index, right, mid, r);
}

int main(){
	sd(t);
	while(t--){
		sd3(n,k,m);
		tot = 0;
		for(int i = 0; i <= k; i++) dp[0][i] = -inf;
		for(int i = 0; i < n; i++){
			sd(a[i]);
			tot += a[i];
		}
		dp[0][0] = tot;
		ll ans = tot;
		
		build();
		
		int l, r, c; 
		for(int i = 0; i < m; i++){
			sd3(l,r,c);
			update(l-1, r, c);
		}
		
		for(int i = 0; i < n; i++){
			v[i] = query(i);
		}
		
		vector<int> dishes;
		
		for(int i = 0; i < n; i++){
			if(v[i] <= k and a[i] < 0){
				dishes.pb(i);
			}
		}
		
		int indx = 0;
		
		foreach(it, dishes){
			indx = 1-indx;
			for(int i = 0; i <= k; i++){
				dp[indx][i] = dp[1-indx][i];
				if(i >= v[*it]){
					dp[indx][i] = max(dp[indx][i], dp[1-indx][i-v[*it]] - a[*it]);
					ans = max(ans, dp[indx][i]);
				}
			}
		}
		
		printf("%lld\n", ans);
		
	}
	
	return 0;
}
