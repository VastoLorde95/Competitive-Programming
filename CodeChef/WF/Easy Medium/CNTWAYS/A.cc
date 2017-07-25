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

const int N = 800100;
const ll MOD = 1e9 + 7;

ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll f[N];
ll invf[N];

ll C(int n, int k){
	return (f[n] * invf[k] % MOD) * invf[n-k] % MOD;
}

void pre(){
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i-1] * i % MOD;
	
	invf[N-1] = fast(f[N-1], MOD-2);
	for(int i = N-2; i >= 0; i--) invf[i] = invf[i+1] * (i+1) % MOD;
}

inline void sub(ll &x, ll y){
	x -= y;
	if(x < 0) x += MOD;
}

void solve(){
	int n, m, a, b;
	sd2(n,m);
	sd2(a,b);
	
	a--, b--;
	
	ll ans = C(n+m, n);
	
	sub(ans, C(b + n-a, b) * C(m-b + a, a) % MOD);
	
	for(int i = b-1; i >= 0; i--){
		sub(ans, C(i + n-a, i) * (C(m-i + a, a) - C(m-i-1 + a, a) + MOD) % MOD);
	}
	printf("%d\n", (int) ans);
}

int main(){
	pre();
	int t;
	sd(t);
	while(t--) solve();		
	return 0;
}
