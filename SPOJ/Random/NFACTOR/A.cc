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

const int N = 1001000;
const int M = 11;

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

int dp[N][M];

int main(){
	getSieve();

	for(int i = 1; i < N; i++){
		int d = 0, j = i;
		while(j > 1){
			int cur = sieve[j]; d++;
			while(cur == sieve[j] and j > 1){
				j /= sieve[j];
			}
		}
		if(d < M)
			dp[i][d]++;
	}
	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < M; j++){
			dp[i][j] += dp[i-1][j];
		}
	}
	
	int t; sd(t);
	while(t--){
		int a, b, n; sd3(a,b,n);
		printf("%d\n", dp[b][n] - dp[a-1][n]);
	}	
	return 0;
}
