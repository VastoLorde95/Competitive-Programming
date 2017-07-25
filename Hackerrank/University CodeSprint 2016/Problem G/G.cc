#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int N = 3001;

ll MOD;

inline void add(ll &x, ll y){
	x += y;
	if(x >= MOD) x -= MOD;
}

inline ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

inline ll inv(ll x){
	return fast(x, MOD-2);
}

int n;

ll C[N][N];
ll MC[N][N];
ll dp[N][N];
ll f[N];
ll invf[N];

int main(){ _
	cin >> n >> MOD;
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = f[i-1] * i % MOD;
	}
	
	invf[n] = inv(f[n]);
	for(int i = n-1; i >= 0; i--) invf[i] = invf[i+1] * (i+1) % MOD;
	
	C[0][0] = 1;
	for(int i = 1; i <= n; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			add(C[i][j], C[i-1][j] + C[i-1][j-1]);
		}
	}
	
	MC[0][0] = 1;
	for(int i = 1; i <= n; i++){
		MC[i][1] = 1;
		for(int j = 2*i, k = 2; j <= n; j += i, k++){
			MC[j][k] = (((MC[j-i][k-1] * C[j][i] % MOD) * f[k-1] % MOD) * invf[k] % MOD);
		}
	}

	int lim = (n+1)/2-1;
	
	for(int i = 0; i <= lim; i++) dp[0][i] = 1;
	for(int i = 1; i <= lim; i++) dp[1][i] = 1;
	
	ll a, b;
	for(int i = 2; i < n; i++){
		dp[i][1] = 1;
		int up = min(i, lim+1);
		for(int x = 3; x < up; x++){
			a = dp[x][x] - dp[x][x-1];
			if(a < 0) a += MOD;
			b = 1;
			for(int j = x, k = 1; j <= i; j += x, k++){
				b = b * a % MOD;
				add(dp[i][x], ((dp[i-j][x-1] * b % MOD) * C[i][j] % MOD) * MC[j][k] % MOD);
			}
		}
		
		if(i <= lim){
			add(dp[i][i], (dp[i-1][(i+1)/2-1] * i % MOD) * i % MOD);
		}
		
		for(int j = 1; j <= lim; j++) add(dp[i][j], dp[i][j-1]);
	}	
	
	ll res = dp[n-1][lim] * n % MOD;
	
	cout << res << endl;


	return 0;
}
