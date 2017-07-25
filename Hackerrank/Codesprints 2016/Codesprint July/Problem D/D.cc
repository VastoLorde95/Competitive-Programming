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

const int N = 500100;

ll f[N], inv[N];
ll p1[N], p2[N];

void solve(){
	int n, m; sd2(m,n);
	ll ans = 0;
	
	p1[0] = p2[0] = 1;
	for(int i = 1; i <= m; i++){
		p1[i] = (p1[i-1] * (n-1)) % MOD;
		p2[i] = (p2[i-1] * n) % MOD;
	}
	
	for(int i = n; i <= m; i++){
		ans += ((p1[i-n] * p2[m-i] % MOD) * ((f[i-1] * inv[n-1] % MOD) * inv[i-n] % MOD)) % MOD;
		if(ans >= MOD) ans -= MOD;
	}
	printf("%lld\n", ans);
	
	
}

int main(){
	f[0] = 1;
	for(int i = 1; i < N; i++){
		f[i] = (f[i-1] * i) % MOD;
	}
	inv[N-1] = fast(f[N-1], MOD-2);
	for(int i = N-2; i >= 0; i--){
		inv[i] = (inv[i+1] * (i+1)) % MOD;
	}
	
	int p; sd(p);
	while(p--) solve();
	return 0;
}
