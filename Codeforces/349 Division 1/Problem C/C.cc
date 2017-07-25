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

const int N = 100002;
const int M = 502;
const ll MOD = 1e9 + 7;

char s[N];

int dp[M][N];
int p[N];
int f[N];
int invf[N];

int id[N], cur;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

void compute(int l){
	if(!id[l]) id[l] = ++cur;
	else return;
		
	int j = id[l];
	int x, t1, t2;
	for(int i = l; i < N; i++){
		x = (1ll * f[i-1] * invf[l-1] % MOD) * 1ll * invf[i-l] % MOD;
		t1 = 1ll * x * p[i-l] % MOD;
		t2 = 1ll * dp[j][i-1] * 26 % MOD;
		dp[j][i] = (t1 + t2) % MOD;
	}
	
}

int main(){
	p[0] = 1;
	for(int i = 1; i < N; i++) p[i] = (25ll * p[i-1]) % MOD;
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = 1ll * i * f[i-1] % MOD;
	invf[N-1] = fast(f[N-1], MOD-2);
	for(int i = N-2; i >= 0; i--){
		invf[i] = 1ll * invf[i+1] * (i+1) % MOD;
	}
	
	int m;
	sd(m);
	scanf("%s", s);
	
	int l = strlen(s);
	compute(l);
	
	for(int i = 0; i < m; i++){
		int t; sd(t);
		if(t == 1){
			scanf("%s", s);
			l = strlen(s);
			compute(l);
		}
		else{
			int n;
			sd(n);
			int j = id[l];
			
			printf("%d\n", dp[j][n]);
		}
	}
	return 0;
}
