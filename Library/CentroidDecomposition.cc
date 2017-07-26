#include <bits/stdc++.h>

using namespace std;

/*
* par[i] = parent of i in the centroid tree
* level[i] = depth of the i'th node in the original tree
* sz[i] = sz of the subtree rooted at i
* erased[i] = if i has already been chosen as the centroid in the past, it is erased
* jump[i][j] = 2^ith ancestor of j
* g[i] = original adjacency list of i
* cg[i] = centroid tree adjacency list
* st, tp = stack and pointer to the top
*/

const int LOGN = 17;
const int N = 1<<LOGN;

int par[N], level[N], sz[N], erased[N];
int jump[LOGN][N];
vector<int> g[N];
vector<int> cg[N];

int st[N], tp;

void dfs(int u){
	jump[0][u] = u, level[u] = 0, tp = 0;
	st[tp++] = u;
	
	while(tp-1 >= 0){
		u = st[--tp];
		foreach(it, g[u]){
			if(*it == dp[0][u]) continue;
			
			dp[0][*it] = u;
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
	
	if(prev == -1) par[centroid] = centroid;
	else{
		par[centroid] = prev;
		cg[prev].pb(centroid);
	}
	
	erased[centroid] = 1;
	foreach(it, g[centroid]) if(!erased[*it]) decompose(*it, centroid);
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

int dist(int u, int v){
	return level[u] + level[v] - 2*level[lca(u,v)];
}

int main(){
	// TODO - 1 is the root, -1 is the prev
	preprocess(1);
	decompose(1, -1);
	return 0;
}
