#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int n, m, x, y, z, repair = 0, INF = 1000000;
vector<pair<int, int> > adj[100001];
set<pair<int, int> > path;
int visited[100001], dist[100001], bad[100001], prev[100001][2], cur = 1, next, cnt = 0; priority_queue<pair<int, int> > q;
pair<int, int> p;

void shortest_path(){
	for(int i = 1; i <= n; i++){
		visited[i] = 0; bad[i] = 0, dist[i] = INF;
	}
	
	q.push(make_pair(0, 1));
	dist[1] = 0, bad[1] = 0, prev[1][0] = -1;
	while(cnt < n){
		p = q.top(); q.pop(); cur = p.se;
		while(visited[cur] == 1){
			p = q.top(); q.pop(); cur = p.se;
		}
		visited[cur] = 1;

		cnt++;
		for(int i = 0; i < adj[cur].size(); i++){
			if(visited[adj[cur][i].fi] == 0){
				
				if(dist[cur] + 1 < dist[adj[cur][i].fi]){
					dist[adj[cur][i].fi] = dist[cur] + 1;

					q.push(make_pair(-dist[adj[cur][i].fi], adj[cur][i].fi));
					prev[adj[cur][i].fi][0] = cur;
					
					if(adj[cur][i].se == 0){
						bad[adj[cur][i].fi] = bad[cur] + 1;
						prev[adj[cur][i].fi][1] = 1;	// to be repaired
					}
					else{
						bad[adj[cur][i].fi] = bad[cur];
						prev[adj[cur][i].fi][1] = 0;	// not to be repaired
					}					
				}
				
				else if(dist[cur] + 1 == dist[adj[cur][i].fi]){
				
					if(adj[cur][i].se == 0 and bad[cur] + 1 < bad[adj[cur][i].fi]){
						bad[adj[cur][i].fi] = bad[cur] + 1;
						
						prev[adj[cur][i].fi][0] = cur;
						prev[adj[cur][i].fi][1] = 1;	// to be repaired
					}
					else if(adj[cur][i].se == 1 and bad[cur] < bad[adj[cur][i].fi]){
						bad[adj[cur][i].fi] = bad[cur];
						
						prev[adj[cur][i].fi][0] = cur;
						prev[adj[cur][i].fi][1] = 0;	//not to be repaired
					}
				}
			}
		}
		cur = next;
	}

	cout<<(m-dist[n]-repair+(2*bad[n]))<<endl;

	cur = n;
	while(prev[cur][0] != -1){
		path.insert(make_pair(cur, prev[cur][0]));
		path.insert(make_pair(prev[cur][0], cur));
		if(prev[cur][1] == 1){
			printf("%d %d 1\n",cur, prev[cur][0]);
		}
		cur = prev[cur][0];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < adj[i].size(); j++){
			if(adj[i][j].se == 1){
				if(path.find(make_pair(i, adj[i][j].fi)) == path.end()){
					printf("%d %d 0\n",i, adj[i][j].fi);
					path.insert(make_pair(adj[i][j].fi, i));
				}
			}
		}
	}
	return;
}


int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd3(x,y,z);
		adj[x].push_back(make_pair(y,z));
		adj[y].push_back(make_pair(x,z));
		if(z == 0) repair++;
	}
	
	shortest_path();
	return 0;
}
