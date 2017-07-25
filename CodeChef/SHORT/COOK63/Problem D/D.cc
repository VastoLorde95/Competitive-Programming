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

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

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

const ll N = 1<<19;

ll MOD = 1e9 + 7, inf = -1e9;

struct node{
	ll mx, cnt1, cnt2;
	
	node(){
		mx = -1;
		cnt1 = 0;
		cnt2 = 0;
	}
	
	void assign(){
		mx = -1;
		cnt1 = 0;
		cnt2 = 0;
	}
	
	void update(ll mxm, ll val1, ll val2){
		if(mxm == mx){
			cnt1 += val1;
			cnt2 += val2;
		}
		else if(mxm == mx+1){
			mx = mxm;
			cnt2 = val2 + cnt1;
			cnt1 = val1;			
		}
		else{
			mx = mxm;
			cnt1 = val1;
			cnt2 = val2;
		}
	}
	
	void combine(node &left, node &right){
		if(left.mx == right.mx){
			mx = left.mx;
			cnt1 = (left.cnt1 + right.cnt1)%MOD;
			cnt2 = (left.cnt2 + right.cnt2)%MOD;
		}
		else if(left.mx < right.mx){
			mx = right.mx;
			cnt1 = right.cnt1;
			cnt2 = right.cnt2;
			if(left.mx == right.mx-1) cnt2 = (cnt2 + left.cnt1)%MOD;	
		}
		else{
			mx = left.mx;
			cnt1 = left.cnt1;
			cnt2 = left.cnt2;
			if(left.mx-1 == right.mx) cnt2 = (cnt2 + right.cnt1)%MOD;	
		}
	}
};

ll t, n, a[N];
node tree[2*N];

void build(ll id = 1, ll l = 0, ll r = n+1){
	tree[id].assign(); 
	if(l+1 == r) return;
	ll left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	return;
}

void update(ll index, ll mxm, ll val, ll val2, ll id = 1, ll l = 0, ll r = n+1){
	if(l+1 == r){
		tree[id].update(mxm, val, val2);
		return;
	}
	ll left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, mxm, val, val2, left, l, mid);
	else update(index, mxm, val, val2, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

node query(ll x, ll y, ll id = 1, ll l = 0, ll r = n+1){
	if(x >= r or l >= y){
		node ret;
		return ret;
	}
	if(x <= l && r <= y) return tree[id];
	
	ll left = id<<1, right = left+1, mid = (l+r)>>1;
	
	node ret, ll = query(x, y, left, l, mid), rr = query(x, y, right, mid, r);
	ret.combine(ll, rr);
	return ret;
}

set<ll> compressor;
map<ll, ll> f;

int main(){
	sd(t);
	while(t--){
		sd(n);
		compressor.clear();
		f.clear();
		for(ll i = 0; i < n; i++){
			sd(a[i]);
			compressor.insert(a[i]);
		}
		
		ll cnt = 0;
		foreach(it, compressor) f[*it] = ++cnt;
		for(ll i = 0; i < n; i++){
			a[i] = f[a[i]];
		}
		
		build();LIS wala bhi o
		update(0, 0, 1, 0);
		for(ll i = 0; i < n; i++){
			node cur = query(0, a[i]);
			update(a[i], cur.mx+1, cur.cnt1, cur.cnt2);
			
		}	
		
		node res = query(0, cnt+1);
		
		assert(res.cnt2 > 0 and res.cnt2 < MOD);
		printf("%lld\n", res.cnt2);
			
				
	}
	return 0;
}
