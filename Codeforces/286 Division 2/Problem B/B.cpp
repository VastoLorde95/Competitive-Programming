#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;
int n, m, a, b, c, q, u, v, res, visited[101], flag;
vector<pair<int, int> > adj[101];
set<int> done;
int g[101][101][101];
void bfs(int U, int V, int C){
	if(V == U){
		if(flag == 0)
			res++;
		flag = 1;
		return;
	}
	visited[U] = 1;
	for(int i = 1; i <= n; i++){
		if(g[U][i][C] == 1 and visited[i] == 0){
			bfs(i, V, C);	
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	
	for(int i = 0; i < m; i++){
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
		g[a][b][c] = 1;
		g[b][a][c] = 1;
	}
	
	cin>>q;
	for(int i = 0; i < q; i++){
		res = 0;
		done.clear();
		cin>>u>>v;
		for(int j = 0; j < adj[u].size(); j++){

			memset(visited, 0, sizeof visited);
			
			visited[u] = 1;
			if(done.find(adj[u][j].second) == done.end()){
				flag = 0;
				bfs(adj[u][j].first, v, adj[u][j].second);
				if(flag == 1) done.insert(adj[u][j].second);
			}
		}
		cout<<res<<endl;
	}
	
	return 0;
}
