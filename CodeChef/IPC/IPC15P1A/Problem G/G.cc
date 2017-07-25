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

const int N = 1 << 20;

long long fast(long long a, long long b, ll MOD){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll MOD;
ll f[N], invf[N];

ll C(int n, int k){
	return ((f[n] * invf[k] % MOD) * invf[n-k]) % MOD;
}

ll x(int n){
	if(n == 1) return 1;
	return (x(n/2) * x(n/2) % MOD) * C(n-1, n/2) % MOD;
}

ll y(int n){
	if(n == 0) return 1;
	return (((y(n/2 - 1) * x(n/2) % MOD) * 2 % MOD) * C(n-1, n/2) % MOD);
}

int main(){ _
	int n;
	cin >> n >> MOD;
	
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = f[i-1] * i % MOD;
	}
	invf[n] = fast(f[n], MOD-2, MOD);
	for(int i = n-1; i >= 0; i--){
		invf[i] = invf[i+1] * (i+1) % MOD;
	}

	printf("%lld\n", ((n&(n+1)) == 0)? x(n) : y(n));
	
	
	return 0;
}
