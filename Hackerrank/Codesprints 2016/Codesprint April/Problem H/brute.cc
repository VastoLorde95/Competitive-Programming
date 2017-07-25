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

const int LOGN = 17;
const ll MOD = 1e9 + 7;
const int N = 1 << LOGN;
vector<int> g[N];

ll f[10*N];

int p[LOGN][N], l[N];

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}

void dfs(int cur){
	foreach(it, g[cur]){
		l[*it] = l[cur] + 1;
		dfs(*it);
	}
}

ll cost[N];

void update(int cur, ll k){
	cost[cur] += f[k];
	if(cost[cur] >= MOD) cost[cur] -= MOD;
	
	foreach(it, g[cur]){
		update(*it, k+1);
	}
}

int main(){
	f[1] = f[2] = 1;
	for(int i = 3; i < 10*N; i++){
		f[i] = (f[i-1] + f[i-2]);
		if(f[i] >= MOD) f[i] -= MOD;
	}

	int n, m;
	sd2(n,m);
	for(int i = 1; i < n; i++){
		int pr; sd(pr);
		g[pr].pb(i+1);
		p[0][i+1] = pr;
	}
	
	dfs(1);
	
	for(int i = 1; i < LOGN; i++)
		for(int j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
	
	char c;
	ll x, y;
	for(int i = 1; i <= m; i++){
		scanf(" %c %lld %lld", &c, &x, &y);
		if(c == 'U'){
			update(x, y);
		}
		else{
			int lca = LCA(x,y);
			ll ans = 0;
			while(true){
				ans += cost[x];
				if(ans >= MOD) ans -= MOD;
				if(x == lca) break;
				x = p[0][x];
			}
			while(true){
				ans += cost[y];
				if(ans >= MOD) ans -= MOD;
				if(y == lca) break;
				y = p[0][y];
			}
			ans -= cost[lca];
			ans += MOD;
			if(ans >= MOD) ans -= MOD;
			printf("%lld\n", ans);
		}
	}
	
	
	return 0;
}
