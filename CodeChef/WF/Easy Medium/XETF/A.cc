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

/*
1. First Bernoulli number B_m(0) % p can be computed in O(m log p) time given that B_0, B_1, ... B_{m-1} are already known
2. \sum i^k modulo p for i = 1 to n can be computed in O(k log p) time

Subtask 1:
	N can have at most 4 distinct prime factors and hence at most 16 square free divisors.
	For each divisor d, we can compute it's contribution in the inclusion exclusion sum in O(n/d log k) time
	
	<= 16 * 10^4 * 13 * 128 <= 3 * 10^8 
	
Subtask 2, 3 and 4:
	Pre compute Bernoulli numbers B_0, B_1, \dots, B_256 = 256 * 256 * log p time
	Factorize number in O(primes) time where primes ~ 79000
	N can have at most 11 distinct prime divisors and hence at most 2048 square free divisors
	
	For a square free divisor d, its contribution in the inclusion exclusion sum can be computed in O(k) time
	
	Thus total running time = 
	
	128 * 2048 * 256 
*/

const ll MOD = 1e9 + 7;
const int N = 256 + 10;

ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

inline void add(ll &x, ll y){
	x += y;
	if(x >= MOD) x -= MOD;
}

ll C[N][N];
ll B[N];

const int M = 1000001 + 10;
int sieve[M], primes[M], pcnt;

void pre(){
	for(int i = 2; i < M; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] < M; j++) sieve[i*primes[j]] = primes[j];
	}
	
	C[0][0] = 1;
	for(int i = 1; i < N; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if(C[i][j] >= MOD) C[i][j] -= MOD;
		}
	}
	
	B[0] = 1;
	for(int i = 1; i < N; i++){
		if(i > 1 and (i&1)) continue;
		for(int j = 0; j < i; j++){
			ll term = (C[i][j] * B[j] % MOD) * fast(i - j + 1, MOD-2) % MOD;
			add(B[i], MOD - term);
		}
	}
	
}

vector<ll> getPrimes(ll n){
	vector<ll> p;
	
	for(int i = 0; 1ll * primes[i] * primes[i] <= n; i++){
		int pr = primes[i];
		if(n % pr == 0){
			p.pb(pr);
			while(n % pr == 0) n /= pr;
		}
	}
	
	if(n > 1) p.pb(n);
	
	return p;
}

ll get1(ll n, ll k){
	vector<ll> p = getPrimes(n);
	
	int sz = p.size();
	
	ll res = 0;
	for(int i = 0; i < (1 << sz); i++){
		ll pro = 1;
		int par = 0;
		for(int j = 0; j < sz; j++){
			if(i & (1 << j)){
				pro *= p[j];
				par ^= 1;
			}
		}
		
		ll sum = 0;
		
		for(ll j = pro; j <= n; j += pro){
			add(sum, fast(j, k));
		}
			
		if(par)
			add(res, MOD - sum);
		else
			add(res, sum);
	}
	
	assert(0 <= res and res < MOD);
	
	return res;
}


ll get2(ll n, ll k){
	vector<ll> p = getPrimes(n);
	
	int sz = p.size();
	
	ll res = 0;
	for(int i = 0; i < (1 << sz); i++){
		ll pro = 1;
		int par = 0;
		for(int j = 0; j < sz; j++){
			if(i & (1 << j)){
				pro *= p[j];
				par ^= 1;
			}
		}
		
		//
		ll sum = 0;
		ll lim = n / pro;		
		
		lim %= MOD;
		
		vector<ll> pwrs(k+2);
		pwrs[0] = 1;
		for(int j = 1; j <= k+1; j++) pwrs[j] = pwrs[j-1] * lim % MOD;
		
		for(int j = 0; j <= k; j++){
			if(j&1){
				add(sum, MOD - ((C[k+1][j] * B[j] % MOD) * pwrs[k+1-j] % MOD));
			}
			else{
				add(sum, ((C[k+1][j] * B[j] % MOD) * pwrs[k+1-j] % MOD));
			}
		}
		
		sum = sum * fast(pro % MOD, k) % MOD;
		sum = sum * fast(k+1, MOD-2) % MOD;
		
		//		
		
		if(par){
			add(res, MOD - sum);
		}
		else{
			add(res, sum);
		}
	}
	
	assert(0 <= res and res < MOD);
	
	return res;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	
	if(k > 256){
		cout << get1(n, k) << '\n';
	}
	else{
		cout << get2(n, k) << '\n';
	}
}

int main(){ _
	pre();
	
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
