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

typedef ll F;

#define FINF (1ll << 60)
#define MAXN 1000
#define MAXE 1000	// Careful!

struct maxFlow{
	struct Edge{ int x, y; F cap, flow;};
	
	int N, visited[MAXN], prev[MAXN];
	vector<Edge> E;
	vector<int> g[MAXN];
	
	maxFlow(int _N) : N(_N){ }
	
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
};

const int N = 51;

vector<pii> g[N];
int n, m, x;

bool good(long double w){
	if(w == 0) return true;
	
	maxFlow *mf = new maxFlow(n);
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			int j = it->fi, c = it->se;
			mf->addEdge(i, j, ll(floor((long double) c / w)));
		}
	}
	
	int flow = mf->maxflow(1, n);
	
	delete mf;
	
	return flow >= x;
}

int main(){
	sd3(n,m,x);
	
	int a, b, c;
	for(int i = 0; i < m; i++){
		sd3(a,b,c);
		g[a].pb(mp(b,c));
	}
	
	long double lo = 0, hi = 1000001, mid;
	for(int iter = 0; iter < 200; iter++){
		mid = (lo + hi) / 2;
		
		if(good(mid)) lo = mid;
		else hi = mid;
	}
	
	printf("%.11lf\n", (double) lo * x);	
	
	return 0;
}
