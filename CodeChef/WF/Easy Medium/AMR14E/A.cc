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

// n < 4,759,123,141 				3 :  2, 7, 61
// n < 1,122,004,669,633 			4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383			6 :  pirmes <= 13
// n < 3,825,123,056,546,413,051	9 :  primes <= 23

int testPrimes[] = {2,7,61};

struct MillerRabin{
	ll mult(ll s, ll m, ll mod){
	  if(!m) return 0;
	  ll ret = mult(s, m/2, mod);
	  ret = (ret + ret) % mod;
	  if(m & 1) ret = (ret + s) % mod;
	  return ret;
	}

	ll power(ll x, ll p, ll mod){
		ll s = 1, m = x;
		while(p){
			if(p&1) s = s * m % mod;// mult(s, m, mod);
			p >>= 1;
			m = m * m % mod; //mult(m, m, mod);
		}
		assert(0 <= s and s < mod);
		return s;
	}

	bool witness(ll a,ll n,ll u,int t){
		ll x = power(a, u, n), nx;
		for(int i = 0; i < t; i++){
			nx = x * x % n; //mult(x, x, n);
			if(nx == 1 and x != 1 and x != n-1) return 1;
			x = nx;
		}
		return x != 1;
	}

	bool isPrime(ll n){	// return 1 if prime, 0 otherwise
		if(n < 2) return 0;
		if(!(n&1)) return n == 2;
	
		ll u = n-1; int t = 0;
	
		while(u&1) u >>= 1, t++;	// n-1 = u*2^t

	 	for(int i = 0; i < 3; i++) if(witness(testPrimes[i], n, u, t)) return 0;
		return 1;
	}
};

const int N = 35000;

int p[N];
vector<int> nums;
vector<int> pr;

void pre(){
	for(int i = 2; i < N; i++){
		p[i] = 1;
	}
	
	for(ll i = 2; i < N; i++){
		if(!p[i]) continue;
		for(ll j = i*i; j < N; j += i){
			p[j] = 0;
		}
		pr.pb(i);
	}
	
	for(int i = 2; i < N; i++){
		if(p[i]){
			ll num = i;
			ll lim = 1e9;
			int exp = 1;
			
			while(num <= lim){
				if(p[exp+1]) nums.pb(num);
				num *= i;
				exp++;
			}
		}
	}
	
	sort(nums.begin(), nums.end());
}

MillerRabin m;

const int M = 200100;
int pp[M];

void solve(){
	int a, b;
	sd2(a,b);

	int l1 = upper_bound(nums.begin(), nums.end(), b) - nums.begin();
	int l2 = lower_bound(nums.begin(), nums.end(), a) - nums.begin();
	int cnt = l1 - l2;

	a = max(a, N);
	
	for(int i = a; i <= b; i++){
		pp[i-a] = 1;
	}
	
	for(int i = 0; i < pr.size(); i++){
		int x = pr[i];
		for(int j = ((a+x-1)/x)*x; j <= b; j += x){
			pp[j-a] = 0;
		}
	}
	
	for(int i = a; i <= b; i++){
		if(pp[i-a]){
			cnt++;
		}
	}
	

	printf("%d\n", cnt);
}

int main(){
	pre();
		
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
