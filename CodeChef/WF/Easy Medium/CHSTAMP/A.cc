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

const int N = 200100;
const int M = 50100;

int a[N];
int best[M];

map<int, vector<int> > g[M];
set<int> vis, gis;

void dfs(int x, int t, int &mx){
	vis.insert(x);
	
	mx = max(mx, best[x]);
	
	foreach(it, g[t][x]){
		if(vis.count(*it)) continue;
		
		dfs(*it, t, mx);
	}
}

void setmax(int x, int t, int &mx){
	gis.insert(x);
	
	best[x] = mx;
	
	foreach(it, g[t][x]){
		if(gis.count(*it)) continue;
		
		setmax(*it, t, mx);
	}
}

void solve(){
	int n, m;
	sd2(n,m);
	
	for(int i = 1; i < M; i++){
		best[i] = i;
		g[i].clear();
	}
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	for(int i = 0; i < m; i++){
		int t, a, b;
		sd3(t, a, b);
		g[t][a].pb(b);
		g[t][b].pb(a);
	}
	
	for(int i = M-1; i > 0; i--){
		if(g[i].empty()) continue;
		
		vis.clear();
		gis.clear();
		
		foreach(it, g[i]){
			
			if(vis.count(it->fi)) continue;
			
			int mx = 0;
			dfs(it->fi, i, mx);
			setmax(it->fi, i, mx);
		}	
	}
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += best[a[i]];
	}
	
	printf("%lld\n", ans);
	
}

int main(){
	int t;
	sd(t);
	while(t--) solve();	
	return 0;
}
