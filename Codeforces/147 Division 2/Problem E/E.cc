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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef int Cap;
typedef int Cost;

using namespace std;

const int MAXN = 250;
Cap CINF = 1e6;	// Warning check type of infinity
Cost INF = 1e6;	// Warning check type of infinity	

struct minCostMaxFlow{
	struct Edge{int x, y; Cap cap; Cost cost;};
	
	int N, prev[MAXN];
	
	Cost dist[MAXN], phi[MAXN];
	
	vector<Edge> E;
	vector<int> g[MAXN];
	
	minCostMaxFlow(int _N) : N(_N){ }
	
	void addEdge(int x, int y, Cap cap, Cost cost){
		Edge e1 = {x, y, cap, cost}, e2 = {y, x, 0, -cost};
		g[x].pb(E.size()); E.pb(e1);
		g[y].pb(E.size()); E.pb(e2);
	}
	
	// Note: In SSSP, the distance from the source 's' to 'v' is dist[v] + phi[v] - phi[x]
	bool augment(int s, int t){
		int x, y;
		for(int i = 0; i < N; i++) prev[i] = -1, dist[i] = INF;
		dist[s] = prev[s] = 0;
		
		set<pair<Cost, int> > q;
		q.insert(mp(dist[s], s));
		
		while(!q.empty()){
			x = q.begin()->se; q.erase(q.begin());
			
			foreach(it, g[x]){
				Edge &e = E[*it];
				if(e.cap <= 0) continue;
				
				y = e.y;
				Cost ncost = e.cost + phi[x] - phi[y];
				
				if(dist[x] + ncost < dist[y]){
					q.erase(mp(dist[y], y));
					dist[y] = dist[x] + ncost;	// New distance to node
					prev[y] = *it;				// The edge from which you arrive here
					q.insert(mp(dist[y], y));
				}
			}
		}
		
		if(prev[t] == -1) return false; else return true;
	}
	
	pair<Cap, Cost> mcmf(int s, int t){	// returns (flow, cost)
		Cap flow = 0; Cost cost = 0;
		for(int i = 0; i <= N; i++) phi[i] = 0;
		
		while(true){
			if(!augment(s, t)) break;
			
			Cap z = CINF;
			
			for(int i = t; i != s; i = E[prev[i]].x) z = min(z, E[prev[i]].cap);
			for(int i = t; i != s; i = E[prev[i]].x){
				E[prev[i]].cap -= z, E[prev[i]^1].cap += z;
			}
			
			flow += z;
			cost += z * (dist[t] - phi[s] + phi[t]);

			for(int i = 0; i < N; i++) if(prev[i] != -1) phi[i] += dist[i];
		}
		return mp(flow, cost);
	}	
};

string t;
int n, a[MAXN];
string s[MAXN];

int main(){ _
	cin >> t;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i] >> a[i];
	}
	
	minCostMaxFlow *mf = new minCostMaxFlow(n+52+2);
	
	int S = 52+n, T = S+1;	
	for(int i = 0; i < 26; i++){
		char c = 'a'+i;
		int cnt = 0;
		
		for(int j = 0; j < t.length(); j++) if(t[j] == c) cnt++;
		mf->addEdge(S, i, cnt, 0);
		
		for(int j = 0; j < n; j++){
			cnt = 0;
			for(int k = 0; k < s[j].length(); k++) if(s[j][k] == c) cnt++;
			mf->addEdge(26+i, 52+j, cnt, 0);
		}
		
		mf->addEdge(i, 26+i, CINF, 0);
	}
	
	for(int j = 0; j < n; j++){
		mf->addEdge(52+j, T, a[j], j+1);
	}
	
	pair<int,int> p = mf->mcmf(S,T);
	if(p.fi != t.length()){
		cout << -1 << endl;
	}
	else{
		cout << p.se << endl;
	}
	
	return 0;
}
