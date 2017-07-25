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

const int N = 300100;

vector<pii> e;
vector<int> g[N];
int p[N];

int closest[N];
int dis[N];

void dfs(int x, int pp){
	if(p[x]){
		dis[x] = 0;
		closest[x] = x;
	}
	else{
		dis[x] = 1e9;
		closest[x] = -1;
	}
	
	foreach(it, g[x]){
		if(*it == pp) continue;
		
		dfs(*it, x);
		if(dis[*it] + 1 < dis[x]){
			dis[x] = dis[*it] + 1;
			closest[x] = closest[*it];
		}
	}
}

void dfs2(int x, int p, int d, int n){
	if(d < dis[x]){
		dis[x] = d;
		closest[x] = n;
	}
	
	foreach(it, g[x]){
		if(*it == p) continue;
		
		dfs2(*it, x, dis[x] + 1, closest[x]);
	}
}

int main(){ _
	int n, k, d;
	cin >> n >> k >> d;
	
	for(int i = 1; i <= k; i++){
		int x;
		cin >> x;
		p[x] = 1;
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		e.pb(mp(u,v));
	}
	
	dfs(1, -1);
	dfs2(1, -1, 1e9, -1);
	
	vector<int> to_remove;
	for(int i = 0; i < n-1; i++){
		int u = e[i].fi, v = e[i].se;
		if(closest[u] != closest[v]){
			to_remove.pb(i);
		}
	}
	
	cout << to_remove.size() << endl;
	
	for(int ed : to_remove) Ccout << ed+1 << ' ';
	cout << endl;
	
	return 0;
}
