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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

typedef int Cap;
typedef int Cost;

using namespace std;

const int MAXN = 500;
Cost INF = ~0U >> 1; // ***Warning check type of infinity
Cap CINF = ~0U >> 1; // ***Warning check type of infinity

struct minCostMaxFlow{
    struct Edge{int x, y; Cap cap; Cost cost;};
    
    int N, prev[MAXN];
    
    Cost dist[MAXN];
    
    vector<Edge> E;
    vector<int> g[MAXN];
    
    minCostMaxFlow(int _N) : N(_N){
    }
    
    void addEdge(int x, int y, Cap cap, Cost cost){
        Edge e1 = {x, y, cap, cost}, e2 = {y, x, 0, -cost};
        g[x].pb(E.size()); E.pb(e1);
        g[y].pb(E.size()); E.pb(e2);
    }
    
    pair<Cap, Cost> mcmf(int s, int t, bool maxflow){   // returns (flow, cost)
        Cap flow = 0; Cost cost = 0;
        
        while(true){
        	const Cap MAX_FLOW = ~0U >> 1;
        	
        	vector<Cost> dist(N, INF);
			vector<Cap> am(N, 0);
			vector<int> prev(N);
			vector<bool> inQ(N, false);
			queue<int> que;
		
			dist[s] = 0;
			am[s] = MAX_FLOW;
			que.push(s);
			inQ[s] = true;
		
			while(!que.empty()){
				int u = que.front();
				
				Cost c = dist[u];
				que.pop();
				inQ[u] = false;
			
				foreach(it, g[u]){
					Edge e = E[*it];
					if(e.cap > 0){
						Cost nc = c + e.cost;
						if(nc < dist[e.y]){
							dist[e.y] = nc;
							prev[e.y] = *it;
							am[e.y] = min(am[u], e.cap);
							if(!inQ[e.y]){
								que.push(e.y);
								inQ[e.y] = true;
							}
						}
					}
				}
			}
			
			if (maxflow) {
				if (dist[t] == INF)
					break;
			} else {
				if (dist[t] >= 0)
					break;
			}
            
            Cap z = am[t];
            
            flow += z;
            cost += z * dist[t];
            
            for(int i = t; i != s; i = E[prev[i]].x){
                E[prev[i]].cap -= z, E[prev[i]^1].cap += z;
            }
        }
        
        return mp(flow, cost);
    }   
};

int n, m, aa, dd, x;
vector<int> a, c;
string how[101];

int notall(){
    minCostMaxFlow *net = new minCostMaxFlow(m+n+2);   
    int s = 0, t = 1;
    
    for(int i = 0; i < n; i++){
        net->addEdge(s, i+2, 1, 0);
    }
    
//    tr("here");
    
    for(int i = 0; i < m; i++){
        net->addEdge(n+2+i, t, 1, 0);
    }
    
//    tr("here");
    
    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (c[j] > a[i] && how[i] == "ATK") {
				net->addEdge(i+2, n+2+j, 1, -(c[j] - a[i]));
			}
		}
	}
    
//    tr("here4");
    
    return -net->mcmf(s,t,false).se;
}


int all(){
    minCostMaxFlow *net = new minCostMaxFlow(m+m+2);    
    int s = 0, t = 1;
    
    for(int i = 0; i < m; i++){
        net->addEdge(s, i+2, 1, 0);
    }
    
    for(int i = 0; i < m; i++){
        net->addEdge(m+2+i, t, 1, 0);
    }
    
    for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i < n) {
				if (how[i] == "ATK") {
					if (c[j] >= a[i])
						net->addEdge(i+2, m+2+j, 1, -(c[j] - a[i]));
				} else {
					if (c[j] > a[i])
						net->addEdge(i+2, m+2+j, 1, 0);
				}
			} else {
				net->addEdge(i+2, m+2+j, 1, -c[j]);
			}
		}
	}
    
    
    pair<int, int> ret = net->mcmf(s,t,true);
    if (ret.fi == m)
        return -ret.se;
    return 0;
}

int main(){ _
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> how[i] >> x;
        a.pb(x);
    }
        
    for(int i = 0; i < m; i++){
        cin >> x;
        c.pb(x);
    }
    
    int res = notall(); 
    
    if(m > n){
        res = max(res, all());
    }
    
    cout << res << "\n";
    
    return 0;
}
