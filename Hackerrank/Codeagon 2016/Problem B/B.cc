#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;

const int N = 16;

int n;
int a[N];

const int M = 1000001;
int sieve[M], primes[M], pcnt;

void getSieve(){
	for(int i = 2; i < M; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] < M; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}

long long l[M];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	getSieve();
	
	l[1] = 0;
	for(int i = 2; i < M; i++){
		l[i] = l[i/sieve[i]]+1;
	}
	
	for(int i = 2; i < M; i++){
		l[i] += l[i-1];
	}

	long long res = 0;	
	for(int i = 1; i < (1<<n); i++){
		ll cnt = 0;
		ll tot = 0;
		for(int j = 0; j < n; j++){
			if((i&(1<<j)) > 0){
				cnt ^= ((l[a[j]])%2);
				tot += l[a[j]];
			}
		}
		
		if(!cnt){
			res += tot;
		}
	}
	
	cout << res << endl;
	
	
	return 0;
}
