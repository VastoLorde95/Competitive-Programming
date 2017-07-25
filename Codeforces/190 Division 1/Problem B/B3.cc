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

const int MAXN = 250;
Cost INF = 1e7; // ***Warning check type of infinity
Cap CINF = 1e7; // ***Warning check type of infinity

struct minCostMaxFlow{
    struct Edge{int x, y; Cap cap; Cost cost;};
    
    int N, prev[MAXN];
    
    Cost dist[MAXN], phi[MAXN];
    
    vector<Edge> E;
    vector<int> g[MAXN];
    
    minCostMaxFlow(int _N) : N(_N){
    }
    
    void addEdge(int x, int y, Cap cap, Cost cost){
        Edge e1 = {x, y, cap, cost}, e2 = {y, x, 0, -cost};
        g[x].pb(E.size()); E.pb(e1);
        g[y].pb(E.size()); E.pb(e2);
    }
    
    bool dijkstra(int s, int t, bool maxflow){
        int x, y;
        for(int i = 0; i < N; i++){
            prev[i] = -1, dist[i] = INF;
        }
        
        dist[s] = 0; prev[s] = s;
    
        set<pair<Cost, int> > q;
        q.insert(mp(dist[s], s));
        
        while(!q.empty()){
            x = q.begin()->se; q.erase(q.begin());
            
            foreach(it, g[x]){
                Edge &e = E[*it];
                y = e.y;    
                    
                if(e.cap <= 0) continue;
                
                Cost ncost = e.cost + phi[x] - phi[y];
                
                if(dist[x] + ncost < dist[y]){
                    q.erase(mp(dist[y], y));
                    dist[y] = dist[x] + ncost;  // New distance to node
                    prev[y] = *it;              // The edge from which you arrive here
                    q.insert(mp(dist[y], y));
                }   
            }
        }
        
        if(maxflow){
            if(prev[t] == -1) return false;
        }
        else{
            if((dist[t] - phi[s] + phi[t]) >= 0) return false;
        }
        return true;
    }
    
    pair<Cap, Cost> mcmf(int s, int t, bool maxflow){   // returns (flow, cost)
        Cap flow = 0; Cost cost = 0;
        
        memset(phi, 0, sizeof(phi));
        
        while(true){
            if(!dijkstra(s,t,maxflow)) break;
            
            Cap z = CINF;
            
            for(int i = t; i != s; i = E[prev[i]].x) z = min(z, E[prev[i]].cap);
            for(int i = t; i != s; i = E[prev[i]].x){
                E[prev[i]].cap -= z, E[prev[i]^1].cap += z;
            }
            
            flow += z;
            cost += z * (dist[t] - phi[s] + phi[t]);
            
            for(int i = 0; i < N; i++){
                if(prev[i] != -1){
                    phi[i] += dist[i];      
                }
                
            }
        }
        
        return mp(flow, cost);
    }   
};

int n, m, aa, dd, x;
vector<int> a, d, c;
string str;

int notall(){
    minCostMaxFlow *net = new minCostMaxFlow(m+aa+2);   
    int s = m+aa, t = s+1;
    
    for(int i = 0; i < aa; i++){
        net->addEdge(s, i, 1, 0);
    }
        
    for(int i = 0; i < m; i++){
        net->addEdge(aa+i, t, 1, 0);
    }
    
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < aa; j++){
            if(c[i] > a[j]){
                net->addEdge(j, aa+i, 1, -(c[i]-a[j]));
//              tr2(j,aa+i);
            }
        }
    }
    
    return -(net->mcmf(s,t,false).se);
}


int all(){
    minCostMaxFlow *net = new minCostMaxFlow(m+m+2);    
    int s = m+m, t = s+1;
    
    for(int i = 0; i < m; i++){
        net->addEdge(n+i, t, 1, 0);
    }
    
    for(int i = 0; i < aa; i++){
        net->addEdge(s, i, 1, 0);
    }
    
    for(int i = 0; i < dd; i++){
        net->addEdge(s, aa+i, 1, 0);
    }
    
    for(int i = m+n; i < m+m; i++){
        net->addEdge(s,i,1,0);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < aa; j++){
            if(c[i] >= a[j]){
                net->addEdge(j, n+i, 1, -(c[i]-a[j]));
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < dd; j++){
            if(c[i] > d[j]){
                net->addEdge(aa + j, n+i, 1, 0);
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = m+n; j < m+m; j++)
            net->addEdge(j, n+i, 1, -c[i]);
    }
    
    pair<int, int> ret = net->mcmf(s,t,true);
    if (ret.fi == m)
        return -ret.se;
    return 0;
}

int main(){ _
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> str >> x;
        if(str[0] == 'A') a.pb(x); else d.pb(x);
    }
    
    aa = a.size(); 
    dd = d.size();
        
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
