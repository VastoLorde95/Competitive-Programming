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

const ll MOD = 1e9 + 7;
const int N = 100100;

vector<int> g[N];
int c[N];
ll dp[N];
ll ans;

void add(ll &x, ll y){
	x += y; if(x >= MOD) x -= MOD;
}

void dfs(int cur, int prev){
	dp[cur] = 1;
	ll t = 0;
	
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur);
		
		if(c[*it] != c[cur]){
			add(ans, dp[*it] * t % MOD);
			add(t, dp[*it]);			
			add(dp[cur], dp[*it]);
		}
	}
	
	add(ans, dp[cur]);
}

int main(){
	int n; sd(n);
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}	
	
	for(int i = 1; i <= n; i++){
		char col; scanf(" %c", &col);
		c[i] = (col == 'W') ? 1 : 0;
	}
	
	dfs(1,-1);
	
	printf("%lld\n", ans);
	
	return 0;
}
