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

const int N = 201000;
const int M = 201;
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

void add(ll &x, ll y){
	x += y;
	if(x >= MOD) x -= MOD;
}

ll cat[N];
ll dp[M][M];
ll f[N];

ll C(int n, int k){
	return f[n] * fast(f[k], MOD-2) % MOD * fast(f[n-k], MOD-2) % MOD;
}

int n, m, t;

int main(){
	cat[0] = 1;
	for(int i = 1; i < N; i++){
		cat[i] = ((((2*(i-1) + 1) * (cat[i-1] * 2) % MOD) % MOD) * fast(i+1, MOD-2)) % MOD;
	}
	
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (f[i-1] * i) % MOD;
	
	dp[0][0] = 1;
	for(int i = 1; i < M; i++){
		for(int j = 1; j <= i; j++){
			for(int k = 1; k <= i; k++){
				add(dp[i][j], dp[i-k][j-1] * cat[k-1] % MOD);
			}
		}
	}
	
	ll ans;
	
	sd(t);
	while(t--){
		sd2(n,m);
		ans = 0;
		int l = 2*n;
		for(int i = 1; i <= m; i++){
			add(ans, dp[m][i] * C(l+i,i) % MOD);
		}
		
		ans = ans * f[n] % MOD * f[m] % MOD * cat[n] % MOD;
		printf("%lld\n", ans);
		
	}	
	
	return 0;
}
