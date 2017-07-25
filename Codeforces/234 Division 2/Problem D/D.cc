#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 100100;

int n, m, k, c[511], vi[N], last, u, v, x;
int type[N];
long long g[511][511], INF = 2e9;
vector<int> adj[N];

int dfs(int cur, int t){
	if(vi[cur] == t) return 0;
	
	int cnt = 0;
	
	if(type[cur] == t) cnt++;
	
	vi[cur] = t;
	
	for(int i = 0; i < adj[cur].size(); i++){
		cnt += dfs(adj[cur][i], t);
	}
	return cnt;
}

int main(){
	sd3(n,m,k);
	
	for(int i = 1; i <= k; i++){
		sd(c[i]);
		for(int j = last+1; j <= last + c[i]; j++){
			type[j] = i;
		}
		last += c[i];
	}
	
	
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			g[i][j] = INF;
		}
		if(c[i] == 1) g[i][i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		sd3(u,v,x);
		
		if(x == 0){
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		u = type[u]; v = type[v];
		g[u][v] = min((int)g[u][v], x);
		g[v][u] = min((int)g[v][u], x);
	}
	
	last = 0;	
	for(int i = 1; i <= n; i++){
		if(type[i] != last){
			last++;
			if(dfs(i, last) != c[last]){
				puts("No");
				return 0;
			}
		}
	}
	
	for(int K = 1; K <= k; K++){
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= k; j++){
				g[i][j] = min(g[i][j], g[i][K] + g[K][j]);
			}
		}
	}
	
	for(int i = 1; i <= k; i++){
		if(g[i][i] != 0){
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			printf("%d ", (g[i][j] == INF)? -1:(int) g[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
