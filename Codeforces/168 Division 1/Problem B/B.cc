#include<iostream>
#include<cmath>
#include<vector>

#define pb(x) push_back(x)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<int> adj[100002];
int val[100002], n, u, v;

long long dfs(int cur, int prev){
	long long mx = 0;
	for(int i = 0; i < adj[cur].size(); i++){
		if(adj[cur][i] != prev)
			mx = max(mx, dfs(adj[cur][i], cur));
	}
	return mx + abs(val[cur] - val[prev]);
}

int main(){ _
	cin >> n;
	
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for(int i = 1; i <= n; i++) cin >> val[i];
	for(int i = 1; i <= n; i++) if(adj[i].size() == 1) adj[i].pb(n+1);
	cout << dfs(1, 1) << "\n";
		
	return 0;
}
