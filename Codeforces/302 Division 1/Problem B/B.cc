#include<cstdio>
#include<vector>
#include<utility>
#include<queue>

#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;

vector<int> adj[3001];
int n, m, s1, s2, t1, t2, l1, l2, a, b, ans, di[3001][3001], s, d, v;

void bfs(int u){
	queue<pair<int, int> > q;
	q.push(mp(u,0));
	while(!q.empty()){
		s = q.front().fi, d = q.front().se; q.pop();
		if(di[u][s] != -1) continue;
		di[u][s] = d;
		for(int i = 0; i < adj[s].size(); i++){
			v = adj[s][i]; if(di[u][v] == -1) q.push(mp(v,d+1));
		}
	}
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd2(a,b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	sd3(s1,t1,l1);sd3(s2,t2,l2);
	
	for(int i = 1; i <= n; i++)	for(int j = 1; j <= n; j++) di[i][j] = -1;
	for(int i = 1; i <= n; i++) bfs(i);
	
	if(di[s1][t1] > l1 or di[s2][t2] > l2){
		printf("-1\n");	return 0;
	}
	
	ans = di[s1][t1] + di[s2][t2];
	
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
		if(i != j){
			if(di[s1][i] + di[i][j] + di[j][t1] <= l1 and di[s2][i] + di[i][j] + di[j][t2] <= l2)
				ans = min(ans, di[s1][i] + di[s2][i] + di[i][j] + di[j][t1] + di[j][t2]);
			if(di[t1][i] + di[i][j] + di[j][s1] <= l1 and di[s2][i] + di[i][j] + di[j][t2] <= l2)
				ans = min(ans, di[t1][i] + di[s2][i] + di[i][j] + di[j][s1] + di[j][t2]);
		}
	}
	
	printf("%d\n",m-ans);
	
	return 0;
}
