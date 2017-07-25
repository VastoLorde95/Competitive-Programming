#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int LOGN = 17;
const int N = 1<<LOGN;

int par[N], level[N], sz[N], erased[N];
int jump[LOGN][N];
vector<int> g[N];
vector<int> cg[N];

int st[N], tp;

int n, ans[N], inf = 1e9;

void dfs(int u){
	jump[0][u] = u, level[u] = 0, tp = 0;
	st[tp++] = u;
	
	while(tp-1 >= 0){
		u = st[--tp];
		foreach(it, g[u]){
			if(*it == jump[0][u]) continue;
			
			jump[0][*it] = u;
			level[*it] = level[u] + 1;
			st[tp++] = *it;
		}
	}
	return;
}

int totalNodes;
void getSize(int u, int prev){
	sz[u] = 1, ++totalNodes;
	foreach(it, g[u]){
		if(*it == prev or erased[*it]) continue;
		
		getSize(*it, u);
		sz[u] += sz[*it];
	}
	return;
}

int getCentroid(int u, int prev){
	foreach(it, g[u])
		if(!erased[*it] and *it != prev and sz[*it] > totalNodes/2) return getCentroid(*it, u);
	return u;
}

void decompose(int root, int prev){
	totalNodes = 0;
	getSize(root, root);
	int centroid = getCentroid(root, root);
	
	if(prev == -1){
		par[centroid] = centroid;
	}
	else{
		par[centroid] = prev;
		cg[prev].pb(centroid);
	}
	
	erased[centroid] = 1;
	foreach(it, g[centroid]){
		if(!erased[*it]) decompose(*it, centroid);
	}
	return;
}

void preprocess(int u){
	dfs(u);
	for(int i = 1; i < LOGN; i++)
		for(int j = 1; j <= n; j++)
			jump[i][j] = jump[i-1][jump[i-1][j]];
	return;
}

int lca(int u, int v){
	if(level[u] > level[v]) swap(u,v);
	int diff = level[v]-level[u];
	for(int i = 0; i < LOGN; i++) if((diff&(1<<i))) v =  jump[i][v];
	
	if(u == v) return u;
	
	for(int i = LOGN-1; i >= 0; i--)
		if(jump[i][u] != jump[i][v])
			u = jump[i][u], v = jump[i][v];
			
	return jump[0][u];
}

void update(int node){
	int cur = node;
	while(true){
		ans[cur] = min(ans[cur], level[cur] + level[node] - 2*level[lca(cur,node)]);
		if(cur == par[cur]) break;
		cur = par[cur];
	}	
}

int query(int node){
	int cur = node, res = ans[node];
	while(true){
		res = min(res, level[cur] + level[node] - 2*level[lca(node,cur)] + ans[cur]);
		if(cur == par[cur]) break;
		cur = par[cur];
	}
	return res;
}

int main(){
	int m; sd2(n,m);
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	preprocess(1);
	decompose(1,-1);
	
	for(int i = 1; i <= n; i++) ans[i] = inf;
	update(1); // The root is colored red initially
	
	int t, v;
	while(m--){
		sd2(t,v);
		if(t == 1) update(v);
		else printf("%d\n", query(v));
	}
	
	return 0;
}
