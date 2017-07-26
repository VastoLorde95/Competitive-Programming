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

// n < 4,759,123,141 				3 :  2, 7, 61
// n < 1,122,004,669,633 			4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383			6 :  pirmes <= 13
// n < 3,825,123,056,546,413,051	9 :  primes <= 23

int testPrimes[] = {2,3,5,7,11,13,17,19,23};

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
			if(p&1) s = mult(s, m, mod);
			p >>= 1;
			m = mult(m, m, mod);
		}
		return s;
	}

	bool witness(ll a,ll n,ll u,int t){
		ll x = power(a, u, n), nx;
		for(int i = 0; i < t; i++){
			nx = mult(x, x, n);
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

	 	for(int i = 0; i < 9; i++) if(witness(testPrimes[i], n, u, t)) return 0;
		return 1;
	}
};

int main(){
	
	return 0;
}
