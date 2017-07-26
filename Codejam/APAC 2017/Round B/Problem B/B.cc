#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

long long fast(long long a, long long b, long long MOD){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

const int N = 100100;
const ll MOD = 1e9 + 7;

ll dp1[N], dp2[N];

ll solve(){
	ll a, b, n, k;
	cin >> a >> b >> n >> k;
	
	if(k == 1){
		n %= MOD;
		cout << ((n) * ((n-1+MOD)%MOD)) % MOD << endl;
		return;
	}
	
	ll lim = min(n,k);
	
	for(int i = 0; i <= k; i++) dp1[i] = dp2[i] = 0;
	
	for(int i = 1; i <= lim; i++){
		ll val = fast(i, a, k);
		dp1[val] += (max((n-i)/k, 0ll) + 1) % MOD;
		if(dp1[val] >= MOD) dp1[val] -= MOD;
	}
	
	for(int i = 1; i <= lim; i++){
		ll val = fast(i, b, k);
		dp2[val] += (max((n-i)/k, 0ll) + 1) % MOD;
		if(dp2[val] >= MOD) dp2[val] -= MOD;
	}
	
	ll ans = 0;
	
	for(int i = 0; i < k; i++){
		ans += (dp1[i] * dp2[(k-i)%k]) % MOD;
		if(ans >= MOD) ans -= MOD;
	}
	
	for(int i = 1; i <= lim; i++){
		if((fast(i, a, k) + fast(i, b, k)) % k == 0){
			ans -= (max((n-i)/k, 0ll) + 1)% MOD;
			if(ans < 0) ans += MOD;
		}
	}
	
	return ans;
}

int main(){ _
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #"<< i << ": " << solve() << '\n';
	}
	return 0;
}
