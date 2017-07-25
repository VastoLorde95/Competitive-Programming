#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

// for unit capacities, running time is O(min(V^{2/3}, E^{1/2}) * E), otherwise running time is O(V^2 * E)
// This results in O(\sqrt(V) * E) for bipartite matching problem = Hopcroft Karp Algorithm
 
const int inf = 1e9;

struct edge {
    int x, y, cap, flow;
};
 
struct DinicFlow {
    vector <edge> e;
    vector <int> cur, d;
    vector < vector <int> > adj;
    int source, sink, n;
 
    DinicFlow() {}
 
    DinicFlow(int v, int s, int t) {
        n = v, source = s, sink = t;
        cur = vector <int> (n + 1);
        d = vector <int> (n + 1);
        adj = vector < vector <int> > (n + 1);
    }
 
    void addEdge(int from, int to, int cap) {
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0};
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }
 
    int bfs() {
        queue <int> q;
        for(int i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while(!q.empty() and d[sink] < 0) {
            int x = q.front(); q.pop();
            for(int i = 0; i < (int)adj[x].size(); ++i) {
                int id = adj[x][i], y = e[id].y;
                if(d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }
 
    int dfs(int x, int flow) {
        if(!flow) return 0;
        if(x == sink) return flow;
        for(;cur[x] < (int)adj[x].size(); ++cur[x]) {
            int id = adj[x][cur[x]], y = e[id].y;
            if(d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
 
    int maxFlow() {
        int flow = 0;
        while(bfs()) {
            for(int i = 0; i <= n; ++i) cur[i] = 0;
            while(int pushed = dfs(source, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

const int N = 110;
vector<int> g[N];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	
	if(k > g[1].size()){
		cout << -1 << endl;
		return;
	}
	
	int lo = 0, hi = n+1, mid;
	
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		int S = n * (mid + 1) + 1, T = S + 1;
		DinicFlow *f = new DinicFlow(T, S, T);
		
		for(int k = 0; k < mid; k++){
			for(int i = 1; i <= n; i++){
				for(int x : g[i]){
					f->addEdge(k * n + i, (k+1) * n + x, 1);
				}
			}
		}
		
		f->addEdge(S, 1, k);
		for(int k = 1; k <= mid; k++){
			f->addEdge(k * n + n, T, k);
		}
		
		int res = f->maxFlow();
		
		if(res < k) lo = mid;
		else hi = mid;
	}
	
	if(lo >= n) cout << -1 << endl;
	else cout << hi << endl;
}



int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
