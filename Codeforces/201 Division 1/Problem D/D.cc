#include <bits/stdc++.h>

#define sd2(x,y) scanf("%d%d",&x,&y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

using namespace std;

int n, m, u, v, dp[1001000], deg[1001000], inf = 1e9, s, t, vis[1001000], cur;
vector<int> g[1001000];
deque<int> q;

// the front of the deque have the smallest value of dp[v] amongst all unvisted vertices and are arranged in ascending order
int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd2(u,v);
		g[v].push_back(u);
		deg[u]++;
	}
	
	sd2(s,t);
	
	for(int i = 1; i <= n; i++) dp[i] = inf;
	dp[t] = 0;
	
	q.push_front(t);
	while(!q.empty()){
		cur = q.front(); q.pop_front();
		
		if(cur == s) break;
		if(vis[cur]) continue;
		
		vis[cur] = 1;
		foreach(it, g[cur]){
			if(--deg[*it] == 0){
				if(dp[*it] > dp[cur]){
					dp[*it] = dp[cur];
					q.push_front(*it);
				}
			}
			else if(dp[*it] > dp[cur]+1){
				dp[*it] = dp[cur]+1;
				q.push_back(*it);
			}
		}
	}
	
	printf("%d\n", (dp[s] == inf)? -1: dp[s]);
	
	return 0;
}
