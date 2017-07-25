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

const int N = 200100;
const int M = 1001000;
const ll MOD = 1e9 + 7;


int n, k, q;
ll f[N], invf[N];
int d[M], p[M];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll C(int n, int k){
	if(k < 0 or k > n) return 0;
	ll tmp = (invf[k] * invf[n-k]) % MOD;
	return (f[n] * tmp) % MOD;
}

ll ans;

void update(int x){
	ans -= (C(d[x], k) * p[x]) % MOD;
	if(ans < 0) ans += MOD;
	d[x]++;
	ans += (C(d[x], k) * p[x]) % MOD;
	if(ans >= MOD) ans -= MOD;
}

int main(){
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (f[i-1] * i) % MOD;
	
	invf[N-1] = fast(f[N-1], MOD-2);
	for(int i = N-2; i >= 0; i--) invf[i] = (invf[i+1] * (i+1)) % MOD;
	
	for(int i = 1; i < M; i++) p[i] = i;
	
	for(int i = 1; i < M; i++)
		for(int j = i+i; j < M; j += i)
			p[j] -= p[i];
	
	sd3(n,k,q);

	int x, y;	
	for(int i = 1; i <= n; i++){
		sd(x);
		for(int j = 1; j*j <= x; j++){
			if(x%j == 0){
				update(j);
				y = x / j;
				if(y != j) update(y);	
			}
		}
	}
	
	for(int i = 1; i <= q; i++){
		sd(x);
		for(int j = 1; j*j <= x; j++){
			if(x%j == 0){
				update(j);
				y = x / j;
				if(y != j) update(y);	
			}
		}
		
		printf("%I64d\n", ans);
	}
				
	
	return 0;
}
