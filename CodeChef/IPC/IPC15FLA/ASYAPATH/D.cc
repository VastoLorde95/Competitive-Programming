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

const int M = 200100;
const int N = 110;
const ll MOD = 1e9 + 7;

ll fast(ll a, ll b){
	ll ret = 1;
	for(; b; b >>= 1, a = a*a % MOD) if((b&1)) ret = ret*a %MOD;
	return ret;
}

ll f[M], invf[M];

void pre(){
	f[0] = 1;
	for(int i = 1; i < M; i++) f[i] = f[i-1] * i % MOD;
	invf[M-1] = fast(f[M-1], MOD-2);
	for(int i = M-2; i >= 0; i--) invf[i] = invf[i+1] * (i+1) % MOD;
}

ll C(int n, int k){ return f[n] * (invf[k] * invf[n-k] % MOD) % MOD; }

int x[N], y[N], id[N];

bool cmp(const int &i, const int &j){
	if(x[i] != x[j]) return x[i] < x[j];
	if(y[i] != y[j]) return y[i] < y[j];
	return i < j;
}

ll get(int i, int j){
	int dx = x[j] - x[i], dy = y[j] - y[i];
	return C(dx+dy, dx);
}

ll dp1[N][N];
ll dp2[N][N];

bool ok(int i, int j){
	return (x[i] <= x[j] and y[i] <= y[j]);
}

void solve(){
	int n, m, d, sz;
	sd3(n,m,d);
	
	sz = d+1;
	x[0] = 1, y[0] = 1, x[sz] = n, y[sz] = m;
	for(int i = 1; i <= d; i++) sd(x[i]);
	for(int i = 1; i <= d; i++) sd(y[i]);
	for(int i = 0; i <= d+1; i++) id[i] = i;
	
	sort(id, id+sz+1, cmp);
	
	memset(dp1, 0, sizeof dp1);
	memset(dp2, 0, sizeof dp2);
	
	for(int i = 0; i <= sz; i++){
		int u = id[i];
		for(int j = i+1; j <= sz; j++){
			int v = id[j];
			if(!ok(u,v)) continue;
			
			dp1[u][v] = get(u,v);
			for(int k = i+1; k < j; k++){
				int w = id[k];
				if(!ok(u,w)  or !ok(w,v)) continue;
				dp1[u][v] -= dp1[u][w] * get(w,v) % MOD; if(dp1[u][v] < 0) dp1[u][v] += MOD;				
			}
		}
	}
	
	dp2[0][0] = 1;
	
	for(int i = 0; i <= d; i++){
		for(int j = 0; j <= sz; j++){
			int u = id[j];
			for(int k = j+1; k <= sz; k++){
				int v = id[k];
				if(v <= u) continue;
				
				dp2[i+1][v] += dp2[i][u] * dp1[u][v] % MOD; if(dp2[i+1][v] >= MOD) dp2[i+1][v] -= MOD;
			}
		}
	}
	
	for(int i = 1; i <= sz; i++) printf("%lld ", dp2[i][sz]);
	puts("");
}

int main(){
	pre();
	int t; sd(t); while(t--) solve();
	return 0;
}
