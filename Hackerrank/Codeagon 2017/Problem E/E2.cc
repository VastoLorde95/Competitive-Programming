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

typedef int F;

#define FINF (1<<29)
#define MAXN 2100
#define MAXE 1000	// Careful!

struct maxFlow{
	struct Edge{ int x, y; F cap, flow;};
	
	int N, visited[MAXN], prev[MAXN];
	vector<Edge> E;
	vector<int> g[MAXN];
	
	maxFlow(int _N) : N(_N){ }
	
	void reset(int n){
		E.clear();
		for(int i = 1; i <= N; i++){
			visited[i] = 0;
			prev[i] = -1;
			g[i].clear();
		}
		N = n;
	}
	
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

maxFlow *mf;

void solve(){
	vector<pii> a;
	vector<pii> b;
	
	int x, y;
	cin >> x >> y;
	
	for(int i = 0; i < x; i++){
		int p, q;
		cin >> p >> q;
		a.pb(mp(p,q));
	}
	
	for(int i = 0; i < y; i++){
		int p, q;
		cin >> p >> q;
		b.pb(mp(p,q));
	}

	
	int S = x + y + 1, T = S + 1;

	mf->reset(x+y+2);

	for(int i = 1; i <= x; i++){
		mf->addEdge(S, i, 1);
	}
	
	for(int i = 1; i <= y; i++){
		mf->addEdge(x + i, T, 1);
	}
	
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= y; j++){
			if(a[i-1].fi == b[j-1].fi){
				mf->addEdge(i, x + j, 1);
			}
			else if(a[i-1].se == b[j-1].se){
				mf->addEdge(i, x + j, 1);
			}
			else if(abs(a[i-1].fi - b[j-1].fi) == abs(a[i-1].se - b[j-1].se)){
				mf->addEdge(i, x + j, 1);
			}
		}
	}
	
	cout << mf->maxflow(S, T) << endl;
	
}

int main(){ _
	int q;
	cin >> q;
	
	mf = new maxFlow(0);
	
	while(q--) solve();
	return 0;
}
