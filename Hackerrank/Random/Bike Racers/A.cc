#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" /"<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef int F;

#define FINF (1<<29)
#define MAXN 550
#define MAXE 300*300	// Careful!

struct maxFlow{
	struct Edge{ int x, y; F cap, flow;};
	
	int N, visited[MAXN], prev[MAXN];
	vector<Edge> E;
	vector<int> g[MAXN];
	queue<int> q;
    
	maxFlow(int _N) : N(_N){ }
	
	void addEdge(int x, int y, F cap){
		Edge e1 = {x, y, cap, 0}, e2 = {y, x, 0, 0};
		g[x].pb(E.size()); E.pb(e1); g[y].pb(E.size()); E.pb(e2);
	}
	
	bool bfs(int s, int t){
		int x, y;
		for(int i = 1; i <= N; i++) visited[i] = prev[i] = -1;
		q.push(s);
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
};

const int N = 300;

int n, m, k;
long long d[N][N];
set<long long> s;
vector<long long> t;


int main() {
    int x1[N], y1[N];
    int x2[N], y2[N];
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> x1[i] >> y1[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> x2[i] >> y2[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] = (1ll*(x1[i]-x2[j]))*(x1[i]-x2[j]) + (1ll*(y1[i]-y2[j]))*(y1[i]-y2[j]);
            s.insert(d[i][j]);
        }
    }
    
    foreach(it, s){
        t.pb(*it);
    }
    
    s.clear();
    
    int up = t.size();
    int lo = 0, hi = up-1, mid;
    int S = n+m+1, T = S+1, SS = T+1;
    while(lo < hi){
        mid = (lo+hi)>>1;
        long long ti = t[mid];
        maxFlow *mf = new maxFlow(n+m+3);
        mf->addEdge(S, SS, k);
        for(int i = 1; i <= n; i++){
            mf->addEdge(SS, i, 1);
        }
        for(int i = 1; i <= m; i++){
            mf->addEdge(n+i, T, 1);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(d[i][j] <= ti){
                    mf->addEdge(i, n+j, 1);
                }
            }
        }
        
        int flow = mf->maxflow(S, T);
        if(flow < k) lo = mid+1;
        else hi = mid;
        
    }
    
    printf("%lld\n", t[hi]);
    
    return 0;
}

