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

const int N = 10000010;
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

ll phi(ll n){
	ll phi = n;
	ll tmp = n;
	for(int i = 0; i < pcnt; i++){
		if(primes[i] > tmp) break;
		if(tmp % primes[i] == 0){
			phi -= phi / primes[i];
			while(tmp % primes[i] == 0){
				tmp /= primes[i];
			}
		}
	}
	
	if(tmp > 1) phi -= phi / tmp;
	
	return phi;
}

int main(){
	getSieve();
	ll n, k;
	cin >> n >> k;
	
	ll i = 1;
	
	while(i <= k and n > 1){
		n = phi(n);
		i += 2;
	}
	
	ll mod = 1e9 + 7;
	n %= mod;
	
	cout << n << endl;
	
	
	return 0;
}
