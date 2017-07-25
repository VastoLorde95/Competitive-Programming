#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;
const ll MOD = 1e9 + 7;

int a[N];
ll s[N];

ll getAtZ(ll x, ll y, ll z, ll vx, ll vy, int cur, int m){
	int jump = m - cur;
	if(x << jump == z) return vx;
	if(y << jump == z) return vy;
	
	jump--;	
	x <<= 1;
	y <<= 1;
	ll mid = x+1;	
	
	ll vm = (vx + vy) % MOD;
	
	if(z <= (mid << jump))
		return getAtZ(x, mid, z, vx, vm, cur+1, m);
	else
		return getAtZ(mid, y, z, vm, vy, cur+1, m);
}

ll getSum(ll l, ll r, int cnt, ll px, ll py, ll vx, ll vy){
	if(cnt == 0){
//		tr(meta, l, r, cnt, px, py, vx, vy);
		if(l) return (s[r] - s[l-1] + MOD) % MOD;
		return s[r];
	}
	
	ll ret = 0;
	if(r % 2){
		ll v1 = getAtZ(px, py, l, vx, vy, 0, cnt);
		ll v2 = getAtZ(px, py, r-1, vx, vy, 0, cnt);
		ll v3 = getAtZ(px, py, r, vx, vy, 0, cnt);
		
		ret = getSum(l/2, r/2, cnt-1, px, py, vx, vy) * 3 % MOD;
		ret = (ret - v1 + MOD) % MOD;
		ret = (ret - v2 + MOD) % MOD;
		ret = (ret + v3) % MOD;
	}
	else{
		ll v1 = getAtZ(px, py, l, vx, vy, 0, cnt);
		ll v2 = getAtZ(px, py, r, vx, vy, 0, cnt);
		
		ret =  getSum(l/2, r/2, cnt-1, px, py, vx, vy) * 3 % MOD;
		ret = (ret - v1 + MOD) % MOD;
		ret = (ret - v2 + MOD) % MOD;
	}
//	tr(meta, l, r, cnt, px, py, vx, vy, "returning", ret);
	return ret;
}

int n, m;

ll get(ll x){
	if(x < 0) return 0;
	
	ll lo = 0, hi = n, mid;
	while(lo+1 < hi){
		mid = (lo + hi) >> 1;
		ll pos = mid << m;
		if(pos <= x) lo = mid;
		else hi = mid;
	}
	
	ll l = lo, r = lo+1;
	
	ll sm = s[l];
	for(int i = 0; i < m; i++){
		sm = ((sm * 3) % MOD - a[0] - a[l] + MOD) % MOD;
	}
	ll ret = sm;

	if((l << m) == x) return ret;
//	tr(meta, x, l, l << m, ret);
	
	ret = ret + getSum((l << m), x, m, l, r, a[l], a[r]) % MOD;
	ret = (ret - a[l] + MOD) % MOD;
	
	assert(ret >= 0 and ret < MOD);
	
	return ret;
}

void solve(){
	ll x, y;
	scanf("%d%d%lld%lld", &n, &m, &x, &y);
	x--, y--;
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	s[0] = a[0];
	for(int i = 1; i < n; i++){
		s[i] = s[i-1] + a[i] % MOD;
	}
	
	ll ans = (get(y) - get(x-1) + MOD) % MOD;
	
	printf("%lld\n", ans);
	
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
