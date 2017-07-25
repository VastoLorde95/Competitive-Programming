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
#define MAXE 1000

struct maxFlow{
	struct Edge{
		int x, y; 
		F cap, flow;
	};
	
	int N;
	maxFlow(int _N) : N(_N){ }
	
	int visited[MAXN], prev[MAXN];
	vector<Edge> E;
	vector<int> g[MAXN];
	
	void addEdge(int x, int y, F cap){
		Edge e1 = {x, y, cap, 0}, e2 = {y, x, 0, 0};
		g[x].pb(E.size()); E.pb(e1);
		g[y].pb(E.size()); E.pb(e2);
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
			for(int i = t; i != s; i = E[prev[i]].x) E[prev[i]].cap -= cap, E[prev[i]^1].cap += cap;
			
			ans += cap;
		}
		return ans;
	}
};

int n, m, a[101], res;
set<int> primes;
int gp[101][101];

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		int tmp = a[i];
		for(int j = 2; j*j <= tmp; j++){
			if(tmp%j == 0){
				primes.insert(j);
				while(tmp%j == 0) tmp /= j;
			}
		}
		if(tmp > 1) primes.insert(tmp);
	}
	
	int S = n+1, T = n+2;
	
	for(int i = 0; i < m; i++){
		int x, y; sd2(x,y);
		gp[x][y] = gp[y][x] = 1;
	}
	
	foreach(pp, primes){
		maxFlow mf(n+2); int p = *pp;
		
		for(int i = 1; i <= n; i++){
			int cnt = 0, tmp = a[i];
			
			while(tmp%p == 0) cnt++, tmp /= p;
			
			if(i%2 == 1) mf.addEdge(S, i, cnt); else mf.addEdge(i, T, cnt);
		}
		
		
		
		for(int i = 1; i <= n; i += 2){
			if(a[i]%p != 0) continue;
			
			int tmp = a[i], cnt2 = 0;
			while(tmp%p == 0) cnt2++, tmp /= p;
			
			for(int j = 2; j <= n; j += 2){
				if(a[j]%p != 0 or !gp[i][j]) continue;
			
				int cnt = 0; tmp = a[j];
				while(tmp%p == 0) cnt++, tmp /= p;
				
				mf.addEdge(i, j, min(cnt,cnt2));
				
			}
		}
		
		res += mf.maxflow(S,T);
	}
	
	printf("%d\n", res);
	
	return 0;
}
