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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef int F;

#define FINF (1<<29)
#define MAXN 1000
#define MAXE 1000	// Careful!

struct maxFlow{
	struct Edge{ int x, y; F cap, flow;};
	
	int N, visited[MAXN], prev[MAXN];
	vector<Edge> E;
	vector<int> g[MAXN];
	
	maxFlow(int _N) : N(_N){ }
	
	int res[300][300];
	
	void addEdge(int x, int y, F cap){
		Edge e1 = {x, y, cap, 0}, e2 = {y, x, 0, 0};
		g[x].pb(E.size()); E.pb(e1); g[y].pb(E.size()); E.pb(e2);
	}
	
	bool bfs(int s, int t){
		int x, y;
		for(int i = 1; i <= N; i++) visited[i] = prev[i] = -1;
		queue<int> q; q.push(s);
		while(!q.empty()){
			x = q.front(); q.pop();
			
			visited[x] = 1;
			
			foreach(it, g[x]){
				Edge &e = E[*it]; y = e.y;
				
				if(e.cap == 0 or visited[y] == 1) continue;
				
				visited[y] = 1, prev[y] = *it;
				q.push(y);
			}
		}
		
		return (visited[t] == 1);
	}
	
	F maxflow(int s, int t){
		int ans = 0;
		while(bfs(s,t)){
			F cap = FINF;
			
			for(int i = t; i != s; i = E[prev[i]].x) cap = min(cap, E[prev[i]].cap);
			for(int i = t; i != s; i = E[prev[i]].x){
				E[prev[i]].cap -= cap, E[prev[i]^1].cap += cap;
				E[prev[i]].flow += cap; if(E[prev[i]^1].flow > 0) E[prev[i]^1].flow -= cap;
			}
			
			ans += cap;
		}
		return ans;
	}
	
	void print(int n){
		for(int i = 1; i <= n; i++){
			foreach(it, g[i]){
				Edge &e = E[*it]; int j = e.y;
				res[i][j-n] = e.flow;
			}
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				printf("%d ", res[i][j]);
			}
			printf("\n");
		}
	}
	
};

int n, m, a[101], b[101], tot;

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		sd(a[i]); tot += a[i];
	}
	for(int i = 1; i <= n; i++){
		sd(b[i]); tot -= b[i];
	}
	
	if(tot != 0){
		puts("NO"); return 0;
	}
	
	int S = n+n+1, T = n+n+2;
	
	maxFlow mf(n+n+2);
	
	for(int i = 1; i <= n; i++){
		mf.addEdge(S, i, a[i]);
		mf.addEdge(n+i, T, b[i]);
		mf.addEdge(i, n+i, 100);
		tot += a[i];
	}
	
	for(int i = 1; i <= m; i++){
		int p,q; sd2(p,q);
		mf.addEdge(p,q+n,100);
		mf.addEdge(q,p+n,100);
	}
	
	if(mf.maxflow(S,T) != tot) puts("NO"); 
	else{
		puts("YES");
		mf.print(n);
	}
	
	
	return 0;
}
