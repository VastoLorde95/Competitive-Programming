#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

typedef int Cap;
typedef int Cost;

using namespace std;

const int MAXN = 55;
Cap CINF = 1e7;	// Warning check type of infinity
Cost INF = 1e7;	// Warning check type of infinity	

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
	
	Cap mcmf(int s, int t, int k){	// returns (flow, cost)
		Cap flow = 0; Cost cost = 0;
		for(int i = 0; i <= N; i++) phi[i] = 0;
		
		while(true){
			if(!augment(s, t)) break;
			
			Cap z = CINF;
			
			for(int i = t; i != s; i = E[prev[i]].x) z = min(z, E[prev[i]].cap);
			for(int i = t; i != s; i = E[prev[i]].x) E[prev[i]].cap -= z, E[prev[i]^1].cap += z;

			if(cost + z * (dist[t] - phi[s] + phi[t]) >= k and (dist[t] - phi[s] + phi[t]) != 0){
				z = (k - cost) / (dist[t] - phi[s] + phi[t]);
				flow += z;
				return flow;
			}
			
			flow += z;
			cost += z * (dist[t] - phi[s] + phi[t]);
			
			for(int i = 0; i < N; i++) if(prev[i] != -1) phi[i] += dist[i];
		}
		return flow;
	}
};

int n, k;

int main(){
	sd2(n,k);
	
	minCostMaxFlow *mf = new minCostMaxFlow(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x; sd(x);
			if(x > 0){
				mf->addEdge(i, j, x, 0);
				mf->addEdge(i, j, CINF, 1);	
			}
		}
	}
	
	printf("%d\n", mf->mcmf(0,n-1,k));
	
	return 0;
}
