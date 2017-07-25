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

const int N = 100100;
const int M = 210;

int n, m, a[N], b[M];
ll pairs[N+N];
ll MOD = 1234567891ll, ans;


ll eval(ll x){
	ll ret = b[0];
	ll v = x;
	for(int i = 1; i < m; i++){
		ret += (MOD+((b[i]*x)%MOD))%MOD;
		ret %= MOD;
		x = (x*v)%MOD;
	}
	return ret%MOD;
}

map<int, ll> cnt;

ll rem;

int main(){
	sd2(n,m);
	m++;
	rem = ((1ll*n)*(n-1))/2;
	int mx = 0;
	for(int i = 0; i < n; i++){
		int x; sd(x); a[x]++;
		mx = max(mx, x);
	}
	for(int i = 0; i < m; i++){
		sd(b[i]);
	}
	
	for(int i = 1; i <= mx; i++){
		create(i);
		size[i] = a[i];
	}
	
	for(int i = mx; i > 1; i--){
		ll x = 0, y = 0;
		for(int j = i; j <= mx; j += i){
			y += pairs[j];
			pairs[i] += a[j];
		}
		pairs[i] = (pairs[i]*(pairs[i]-1))/2;
		pairs[i] -= y;
		cnt[i] = pairs[i];
		rem -= pairs[i];
	}
	
	rem %= MOD;
	ans = (eval(1)*rem)%MOD;
	foreach(it, cnt){
		ans += (MOD + (eval(it->fi) * (it->se%MOD))%MOD)%MOD;
		if(ans >= MOD) ans -= MOD;
	}
	
	cout << ans << endl;
		
	return 0;
}
