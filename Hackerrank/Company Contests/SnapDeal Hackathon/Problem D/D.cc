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

const ll N = 200100;

ll n;
ll a[N], sum[N][21];
ll k1, k2;
ll ans;

ll f(ll x, ll y){
	ll t1 = 0, t2 = 0;
	ll s = 0, t = 0;
	for(ll i = 0; i <= 20; i++){
		if(x > 0)
			s = sum[y][i] - sum[x-1][i];
		else
			s = sum[y][i];
		t = (y-x+1) - s;
		
		t1 += (1ll<<i) * s * t;
		t1 += (1ll<<i) * (s*(s-1))/2;
		t2 += (1ll<<i) * s * t;
		if(t1 > k1 and t2 > k2) return 1;
	}
	
	return 0;
}

int main(){ _
	cin >> n >> k1 >> k2;	
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	for(ll i = 0; i <= 20; i++){
		sum[0][i] = ((a[0]&(1<<i)) > 0);
	}
	
	for(ll i = 1; i < n; i++){
		for(ll j = 0; j <= 20; j++){
			sum[i][j] = sum[i-1][j] + ((a[i]&(1<<j)) > 0);
		}
	}

	for(ll i = 0; i < n; i++){
		ll lo = i, hi = n, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			if(f(i, mid)) hi = mid;
			else lo = mid+1;
		}
		ans += n-hi;
	}
	
	cout << ans << '\n';

	return 0;
}
