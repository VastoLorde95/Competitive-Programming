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

const int N = 102;
const ll MOD = 1e6 + 3;

ll m[N][N], ret[N][N], res[N][N], n;

ll pw(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

void mul(ll a[][N], ll b[][N]){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			res[i][j] = 0;			
			for(int k = 1; k <= n; k++){
				res[i][j] += a[i][k]*b[k][j] % MOD;
				if(res[i][j] >= MOD) res[i][j] -= MOD;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = res[i][j];
	return;
}

void fast(int exponent){
	for(int i = 1; i <= n; i++) ret[i][i] = 1;
	
	while(exponent > 0){
		if(exponent%2) mul(ret, m);
		mul(m,m);
		exponent >>= 1;
	}
	
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) m[i][j] = ret[i][j];
	return;
}

ll dp[N];

int main(){
	int c, w, h;
	sd3(c,w,h);
	
	dp[0] = 1;
	for(int i = 1; i <= w; i++){
		dp[i] = dp[i-1];
		for(int j = 1; j < i; j++){
			dp[i] += dp[i-j-1] * pw(h, j) % MOD;
			if(dp[i] >= MOD) dp[i] -= MOD;
		}
		dp[i] += pw(h,i);
		if(dp[i] >= MOD) dp[i] -= MOD;
	}
	
	if(c <= w){
		cout << dp[c] << endl;
		return 0;
	}
	
	n = w+1;
	m[1][1] = 1;
	for(int i = 1; i <= w; i++){
		m[1][i+1] = pw(h,i);
	}
	
	for(int i = 2; i <= w+1; i++){
		m[i][i-1] = 1;
	}
	
	fast(c-w);
	
	ll res = 0;
	
	for(int i = 1; i <= w+1; i++){
		res += m[1][i] * dp[w+1-i] % MOD;
		if(res >= MOD) res -= MOD;
	}
	
	cout << res << endl;
		
	return 0;
}
