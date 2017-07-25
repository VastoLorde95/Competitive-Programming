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

const int N = 1000001;
int sieve[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] < N; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}

int main(){
	getSieve();

	ll n;
	cin >> n;
	
	vector<pii> f;
	
	ll x = n;
	
	for(int i = 0; i < pcnt; i++){
		int p = primes[i];
		if(p * p > x) break;
		if(x % p == 0){
			int cnt = 0;
			while(x % p == 0){
				x /= p;
				cnt++;
			}
			f.pb(mp(p, cnt));
		}
	}
	
	if(x > 1){
		f.pb(mp(x, 1));
	}
	
	ll tot1 = 1;
	ll tot2 = 1;
	
	foreach(it, f){
		tot1 *= (it->se + 1);
		tot2 *= (2*it->se + 1);
	}	
	
	tot1--;
	tot2 = (tot2-1)/2;
	
	cout << tot2 - tot1 << endl;
	
	return 0;
}
