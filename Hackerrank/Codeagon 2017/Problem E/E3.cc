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

const int MAXN = 2100;
const int INF = 1000000000;
 
struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, (n+1) * sizeof d[0]);
	
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		
		for (int i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
				
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		
		if (d[to] != d[v] + 1)  continue;
		
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		
		memset (ptr, 0, (n+1) * sizeof ptr[0]);
		while (true){
			int pushed = dfs (s, INF);
			flow += pushed;
			if(!pushed) break;
		}
	}
	return flow;
}

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

	s = x + y + 1;
	t = s + 1;
	n = x + y + 2;
	
	for(int i = 1; i <= x; i++){
		add_edge(s, i, 1);
	}
	
	for(int i = 1; i <= y; i++){
		add_edge(x+i, t, 1);
	}

	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= y; j++){
			if(a[i-1].fi == b[j-1].fi){
				add_edge(i, x + j, 1);
			}
			else if(a[i-1].se == b[j-1].se){
				add_edge(i, x + j, 1);
			}
			else if(abs(a[i-1].fi - b[j-1].fi) == abs(a[i-1].se - b[j-1].se)){
				add_edge(i, x + j, 1);
			}
		}
	}
	
	cout << dinic() << endl;
	
	e.clear();
	for(int i = 0; i <= n; i++){
		g[i].clear();
		d[i] = -1;
		ptr[i] = 0;
		q[i] = -1;
	}
	
}

int main(){ _
	int q;
	cin >> q;
	
	while(q--) solve();
	return 0;
}
