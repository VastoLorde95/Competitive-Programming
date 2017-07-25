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

int n, u, v, c[100000], g[100000], visited[100000], cnt;
vector<int> adj[100000], res;

void bfs(int x, int a, int b, int d){
	if(visited[x]) return;
	
	int p = a, q = b;
	
	if(d%2 == 0){
		if(a%2 == 0){
			if(c[x] == g[x]){
				p = a, q = b;				
			}
			else{
				p++; cnt++;
				res.pb(x+1);
			}
		}
		else{
			if(c[x] == g[x]){
				p++; cnt++;
				res.pb(x+1);
			}
			else{
				p = a, q = b;
			}
		}
	}
	else{
		if(b%2 == 0){
			if(c[x] == g[x]){
				p = a, q = b;				
			}
			else{
				q++; cnt++;
				res.pb(x+1);
			}
		}
		else{
			if(c[x] == g[x]){
				q++; cnt++;	
				res.pb(x+1);
			}
			else{
				p = a, q = b;
			}
		}
	}
	
	visited[x] = 1;
	
	for(int i = 0; i < adj[x].size(); i++){
		bfs(adj[x][i], p, q, d+1);
	}
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		sd2(u,v);
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for(int i = 0; i < n; i++) sd(c[i]);
	for(int i = 0; i < n; i++) sd(g[i]);
	
	bfs(0, 0, 0, 0);

	printf("%d\n", cnt);
	
	for(int i = 0; i < cnt; i++){
		printf("%d\n", res[i]);
	}

	return 0;
}
