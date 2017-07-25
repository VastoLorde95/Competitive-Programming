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

int par[N], level[N], sz[N], erased[N], depth[N], total[N];
int jump[LOGN][N];
long long dis[LOGN][N];
vector<pair<int, int> > g[N];
vector<int> cg[N];

int st[N], tp;

int n, t;

void dfs(int u){
	jump[0][u] = u, level[u] = 0, tp = 0;
	dis[0][u] = 0;
	st[tp++] = u;
	
	while(tp-1 >= 0){
		u = st[--tp];
		foreach(it, g[u]){
			if(it->fi == jump[0][u]) continue;
			
			jump[0][it->fi] = u;
			level[it->fi] = level[u] + 1;
			st[tp++] = it->fi;
		}
	}
	return;
}

int totalNodes;
void getSize(int u, int prev){
	sz[u] = 1, ++totalNodes;
	foreach(it, g[u]){
		if(it->fi == prev or erased[it->fi]) continue;
		
		getSize(it->fi, u);
		sz[u] += sz[it->fi];
	}
	return;
}

int getCentroid(int u, int prev){
	foreach(it, g[u])
		if(!erased[it->fi] and it->fi != prev and sz[it->fi] > totalNodes/2) return getCentroid(it->fi, u);
	return u;
}

void getDistance(int u, int prev, long long len, int depth){
	dis[depth][u] = len;
	foreach(it, g[u]){
		if(!erased[it->fi] and it->fi != prev){
			getDistance(it->fi, u, len + it->se, depth);
		}
	}	
}

void decompose(int root, int prev){
	totalNodes = 0;
	getSize(root, root);
	int centroid = getCentroid(root, root);
	
	if(prev == -1){
		par[centroid] = centroid;
		depth[centroid] = 0;
	}
	else{
		depth[centroid] = depth[prev] + 1;
		par[centroid] = prev;
		cg[prev].pb(centroid);
	}
	erased[centroid] = 1;
	getDistance(centroid, centroid, 0, depth[centroid]);
	
	foreach(it, g[centroid]) if(!erased[it->fi]) decompose(it->fi, centroid);
	return;
}

void preprocess(int u){
	dfs(u);
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= n; j++){
			jump[i][j] = jump[i-1][jump[i-1][j]];
		}
	}
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

int dist(int u, int v){
	return level[u] + level[v] - 2*level[lca(u,v)];
}

int ppl[1001000];
int cnt_ppl[100100];

void update(int x, int val){
	int y = x;
	while(true){
		total[y] += val;
		if(y == par[y]) break;
		y = par[y];
	}
}

int main(){
	sd2(n,t);
	
	for(int i = 1; i < n; i++){
		int a, b, c; sd3(a,b,c);
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	
	preprocess(1);
	decompose(1, -1);
	
	while(t--){
		int k; sd(k);
		for(int i = 0; i < k; i++){
			sd(ppl[i]);
			update(ppl[i], 1);
			cnt_ppl[ppl[i]]++;
		}
		
		long long ans = 0;
		
		for(int i = 0; i < k; i++){
			int y = ppl[i], up = 0, sub = cnt_ppl[ppl[i]];
			while(true){
				ans += (1ll * dis[depth[ppl[i]]-up][ppl[i]]) * (total[y]-sub);
				sub += total[y] - sub;
				up++;
				if(par[y] == y) break;
				y = par[y];
			}
		}
		
		for(int i = 0; i < k; i++){
			update(ppl[i], -1);
			cnt_ppl[ppl[i]]--;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
