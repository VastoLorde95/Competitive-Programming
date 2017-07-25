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

ll MOD;

const int N = 20;
ll C[N][N];

const int M = 1000001 + 10;
int sieve[M], primes[M], pcnt;

void pre(){
	for(int i = 2; i < M; i++){
		if(sieve[i] == 0) sieve[i] = i, primes[pcnt++] = i;
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] < M; j++) sieve[i*primes[j]] = primes[j];
	}
	
	C[0][0] = 1 % MOD;
	for(int i = 1; i < N; i++){
		C[i][0] = C[i][i] = 1 % MOD;
		for(int j = 1; j < i; j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if(C[i][j] >= MOD) C[i][j] -= MOD;
		}
	}
}

inline void add(ll &x, ll y){
	x += y;
	if(x >= MOD) x -= MOD;
}

inline ll mul2(ll a, ll b){
	ll ret = 0;
	a %= MOD;
	b %= MOD;
	assert(0 <= a and a < MOD);
	assert(0 <= b and b < MOD);
	while(b){
		if(b&1) add(ret, a);
		add(a, a);
		b >>= 1;
	}
	return ret;
}

ll fast(ll a, ll b){
	ll ret = 1 % MOD;
	a %= MOD;
	while(b){
		if((b&1)) ret = mul2(ret,a);
		a = mul2(a,a);
		b >>= 1;
	}
	return ret;
}

void mul(vector<vector<ll> > &a, vector<vector<ll> > &b){
	int n = a.size();
	vector<vector<ll> > res(n, vector<ll>(n, 0));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				add(res[i][j], mul2(a[i][k], b[k][j]));
			}
		}
	}
	
	a = res;
}

vector<vector<ll> > mfast(vector<vector<ll> > mtx, ll p){
	int n = mtx.size();
	vector<vector<ll> > ret(n, vector<ll>(n, 0));
	for(int i = 0; i < n; i++) ret[i][i] = 1;
	
	while(p){
		if(p&1) mul(ret, mtx);
		mul(mtx, mtx);
		p >>= 1;
	}
	
	return ret;
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

ll solve(ll n, ll k){
	vector<ll> p = getPrimes(n);
	
	int sz = p.size();
	int lim = 1 << sz;

	vector<vector<ll> > mtx(k+2, vector<ll>(k+2, 0));
	
	for(int j = 0; j < k+2; j++){
		if(j < k + 1) for(int i = 0; i <= j; i++) mtx[i][j] = C[j][i];
		else{
			for(int i = 0; i < j; i++) mtx[i][j] = mtx[i][j-1];
			mtx[j][j] = 1;
		}
	}
	
	vector<vector<ll> > pom[41];
	
	for(int i = 0; i <= 40; i++) 
	pom[i] = mfast(mtx, (1ll << i));
	
	ll res = 0;
	for(int i = 0; i < lim; i++){
		ll pro = 1;
		int par = 0;
		for(int j = 0; j < sz; j++){
			if(i & (1 << j))
				pro *= p[j], par ^= 1;
		}
		
		
		vector<ll> vv(k+2, 1);
		ll lim = n / pro;
		lim--;
		
		int pwr = 0;
		while(lim){
			if(lim&1){
				vector<ll> newv(k+2, 0);
				for(int x = 0; x < k+2; x++){
					for(int y = 0; y < k+2; y++){
						add(newv[x], mul2(vv[y], pom[pwr][y][x]));
					}
				}
				
				vv = newv;
				
			}
			lim >>= 1;
			pwr++;
		}
		
		ll sum = vv.back();
		sum = mul2(sum, fast(pro, k));
		
		if(par)
			add(res, MOD - sum);
		else
			add(res, sum);
	}
	
	assert(0 <= res and res < MOD);
	
	return res;
}

int main(){ _
	ll n, k;
	cin >> n >> k >> MOD;
	
	pre();
	
	cout << solve(n, k) << '\n';
	return 0;
}
