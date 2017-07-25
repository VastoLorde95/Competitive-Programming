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
const int N = 1 << LOGN;

int n, m;
vector<int> g[N];
int p[LOGN][N], l[N];
int sz[N];
ll allPaths[N];
ll allPathsR[N];

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

void dfs(int cur, int prev){
	sz[cur] = 1;
	foreach(it, g[cur]){
		int v = *it;
		if(v == prev) continue;
		
		p[0][v] = cur;
		l[v] = l[cur] + 1;
		
		dfs(v, cur);
		
		sz[cur] += sz[v];
		allPaths[cur] += allPaths[v] + sz[v];
	}
}

void dfs2(int cur, int prev){
	foreach(it, g[cur]){
		int v = *it;
		if(v == prev) continue;
		
		allPathsR[v] = allPathsR[cur] + allPaths[cur] - allPaths[v] - sz[v] + (n - sz[v]);
		
		dfs2(v, cur);
	}
}

int getAncestor(int x, int h){
	if(l[x] == h) return x;
	
	int del = l[x] - h, tmp = 0;
	while((1 << tmp) <= del) tmp++;
	tmp--;
	while(true){
		if(l[x] == h) return x;
		
		if(l[p[tmp][x]] >= h) x = p[tmp][x];
		tmp--;
	}
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i < n; i++){
		int a, b; sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);		
	}

	for(int i = 1; i <= n; i++){
		if(g[i].size() == 1){
			dfs(i,-1);
			dfs2(i,-1);
			break;
		}
	}
	
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
	
	int u, v, lca;
	for(int i = 1; i <= m; i++){
		u, v; sd2(u,v);
		lca = LCA(u,v);
		
		if(lca != u and lca != v){
			int len = (l[u] + l[v] - 2*l[lca]) + 1;
			
			double ans = 0, factor = 1;
			factor /= sz[u];
			factor /= sz[v];
			
			ans += factor * allPaths[u] * sz[v];
			ans += factor * allPaths[v] * sz[u];
			
			printf("%.9lf\n", ans + len);
			
		}
		else{
			if(lca == v) swap(u,v);
			
			int len = (l[v] - l[u]) + 1;
			int specialChild = getAncestor(v, l[u]+1);
			
			ll m_allPathsR = allPaths[u] + allPathsR[u] - allPaths[specialChild] - sz[specialChild];
			
			long double ans = 0, factor = 1;
			factor /= sz[v];
			factor /= (n - sz[specialChild]);
			
			ans += factor * m_allPathsR * sz[v];
			ans += factor * allPaths[v] * (n - sz[specialChild]);
			
			printf("%.9lf\n", (double) ans + len);
		}
	}
	
	return 0;
}
