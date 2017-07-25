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

const int N = 1010;
const ll MOD = 1e9 + 7;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll dp[N];
ll c[N][N];

void solve(){
	ll n, k;
	scanf("%lld%lld",&n, &k);
	n %= MOD;
	
	dp[0] = n;
	for(int i = 1; i <= k; i++){
		dp[i] = (fast((n+1)%MOD, i+1) - 1 + MOD) % MOD;
		for(int j = 0; j < i; j++){
			dp[i] -= c[i+1][j] * dp[j] % MOD;
			if(dp[i] < 0) dp[i] += MOD;
		}
		dp[i] = dp[i] * fast(i+1, MOD-2) % MOD;
	}
	
	cout << dp[k] << endl;
	
}

int main(){
	c[0][0] = 1;
	for(int i = 1; i < N; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = c[i-1][j] + c[i-1][j-1];
			if(c[i][j] >= MOD) c[i][j] -= MOD;
		}
	}
	
	int t; sd(t);
	while(t--) solve();
	return 0;
}
