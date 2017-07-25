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

const ld PI = 3.1415926535897932384626433832795;

const int N = 100100;
const int M = 3;

int n;
ll a[N], mod;
ll dp1[N], dp2[N];

ll m[M][M], ret[M][M], res[M][M];

void mul(ll a[][M], ll b[][M]){
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= 2; j++){
			res[i][j] = 0;			
			for(int k = 1; k <= 2; k++){
				res[i][j] += a[i][k] * b[k][j] % mod;
				if(res[i][j] >= mod) res[i][j] -= mod;
			}
		}
	}
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			a[i][j] = res[i][j];
	return;
}

void fast(ll exponent){
	ret[1][1] = 1, ret[1][2] = 0;
	ret[2][1] = 0, ret[2][2] = 1;
	
	while(exponent > 0){
		if(exponent%2) mul(ret, m);
		mul(m,m);
		exponent >>= 1;
	}
	
	for(int i = 1; i <= 2; i++) for(int j = 1; j <= 2; j++) m[i][j] = ret[i][j];
	return;
}

ll getfib(ll x){
	if(x == -1) return 0;
	if(x <= 1) return 1;
	
	m[1][1] = 1, m[1][2] = 1;
	m[2][1] = 1, m[2][2] = 0;
	
	fast(x);
	
	return m[1][1];
}

int main(){ _ 
	cin >> n >> mod;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	dp1[n] = getfib(a[n]+1);
	dp2[n] = getfib(a[n]);
	
	for(int i = n-1; i > 0; i--){
		
		ll f1 = getfib(a[i]+1);
		ll f2 = getfib(a[i]);
		ll f3 = getfib(a[i]-1);
		ll f4 = getfib(a[i]-2);
		
//		tr(f1, f2, f3, f4);
		
		dp1[i] = (f1 + ((f2 * dp1[i+1] % mod) + (f3 * dp2[i+1] % mod)) % mod) % mod;
		dp2[i] = (f2 + (f3 * dp1[i+1] % mod) + (f4 * dp2[i+1] % mod)) % mod;
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += ((((2ll * dp2[i] % mod) - (n-i+1)) % mod) + mod) % mod;
		if(ans >= mod) ans -= mod;
	}
	
	cout << ans << endl;
	
	
		
	return 0;
}
