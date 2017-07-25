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

using namespace std;

int n, m, c[100000], visited[100000], u, v, comp;
vector<int> adj[100000], rev[100000], scc[100000];
long long MOD = 1000000007, cost, res = 1;
stack<int> s;

void dfs(int x){
	if(visited[x] == 1) return;
	visited[x] = 1;
	
	for(int i = 0; i < adj[x].size(); i++){
		dfs(adj[x][i]);
	}
	
	s.push(x);
	
	return;
}

void dfs2(int x, int comp){
	if(visited[x] == 1) return;
	visited[x] = 1; scc[comp].pb(x);
	
//	cout << "check " << x << " " << comp << endl;
	
	for(int i = 0; i < rev[x].size(); i++){
		dfs2(rev[x][i], comp);
	}
	
	return;
	
}

void sccomp(){
	for(int i = 0; i < n; i++)
		if(!visited[i]) dfs(i);

	int cur;
	
	for(int i = 0; i < n; i++) visited[i] = 0;
	
	while(!s.empty()){
		cur = s.top(); s.pop();
		
		if(visited[cur] == 1) continue;
		
//		cout << cur << endl;
		
		dfs2(cur, comp);
		comp++;
		
	}
	
	return;
}

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(c[i]);
	}
	
	sd(m);
	
	for(int i = 0; i < m; i++){
		sd2(u,v);
		u--, v--;
		adj[u].pb(v);
		rev[v].pb(u);
	}
	
	sccomp();
	
	for(int i = 0; i < comp; i++){
		int mn = 1000000001;
		long long cnt = 1;
		
		for(int j = 0; j < scc[i].size(); j++){
			if(c[scc[i][j]] < mn){
				mn = c[scc[i][j]];
				cnt = 1;
			}
			else if(c[scc[i][j]] == mn){
				cnt++;
			}
		}	
		
//		cout << mn << " " << cnt << endl;
			
		cost += mn;
		
		res = (res*cnt)%MOD;
	}
	
	cout << cost << " " << res << endl;
	
	return 0;
}
