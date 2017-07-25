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

const int N = 250;

set<int> used;
vector<pair<pii, int> > g[N];
vector<pii> res;
int ptr[N];
int vis[N];

void dfs(int x){
	vis[x] = 1;
	if(g[x].empty()) return;
	
	while(ptr[x] < g[x].size()){
		pii nxt = g[x][ptr[x]].fi;
		int id = g[x][ptr[x]].se;
		ptr[x]++;
		
		if(used.count(id)) continue;
		used.insert(id);
		
		if(nxt.se == 1) res.pb(mp(x,nxt.fi));
	
		dfs(nxt.fi);
	}
}

void solve(){
	int n, m;
	sd2(n,m);
	
	used.clear();
	res.clear();
	
	for(int i = 1; i <= n; i++){
		g[i].clear();
		ptr[i] = 0;
		vis[i] = 0;
	}
	
	for(int i = 1; i <= m; i++){
		int u, v; sd2(u,v);
		g[u].pb(mp(mp(v,1),i));
		g[v].pb(mp(mp(u,1),i));
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(g[i].size()%2 == 0) ans++;
	}
	
	int cnt = m;
	for(int i = 1; i <= n; i++){
		if(g[i].size()%2 == 0) continue;
		for(int j = i+1; j <= n; j++){
			if(g[j].size()%2 == 0) continue;
			++cnt;
			g[i].pb(mp(mp(j,2),cnt));
			g[j].pb(mp(mp(i,2),cnt));
			break;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);		
		}
	}
	
	assert(res.size() == m);
	
	printf("%d\n", ans);
	for(int i = 0; i < res.size(); i++){
		printf("%d %d\n", res[i].fi, res[i].se);
	}
	
}

int main(){
	int t; sd(t);
	while(t--) solve();
	return 0;
}
