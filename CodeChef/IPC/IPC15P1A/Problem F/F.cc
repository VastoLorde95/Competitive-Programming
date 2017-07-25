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

const int N = 301;
const int M = 100100;
const int MOD = 1e9 + 7;

ll dp[N][M];
ll f[N];

void pre(){
	dp[0][0] = 1;
	for(int i = 1; i < N; i++){
		dp[i][0] = 1;
		for(int j = 1; j < M; j++){
			dp[i][j] =  (dp[i-1][j] + ((j - i >= 0)? dp[i][j-i] : 0)) % MOD;
		}
	}
	
	f[0] = 1;
	for(int i = 1; i < N; i++){
		f[i] = (f[i-1] * i) % MOD;
	}
}

int main(){
	pre();	
	
	int t; sd(t);
	while(t--){
		int n, m;
		sd2(n,m);
		m -= (n*(n+1))/2;
		if(m < 0)
			printf("0\n");
		else
			printf("%lld\n", dp[n][m] * f[n] % MOD);		
	}
	
	return 0;
}
