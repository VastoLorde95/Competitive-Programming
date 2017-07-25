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

const int LOGN = 17;
const int N = 1 << LOGN;
const int INF = 1e9;

vector<pii> g[N];
vector<pii> cache[N][4];

map<ll, ll> rem[N][4];
map<ll, ll> rrem[N][4];

int sz[N];
int minValue, center, totNodes;

ll p10[N];

int dfs(int x, int p, ll d, ll d2, int n, int h, bool flag = false, int depth = -1){
	if(flag){
		rem[depth][0][d]++;
		rrem[depth][0][d2]++;
	}
	
	sz[x] = 1;
	int mx = 0, cnt = 0;
	foreach(it, g[cur]){
		if(it->fi == p) continue;
		
		ll nd = (d * 10 + it->se) % m;
		ll nd2 = ((w * p10[h] % m) + d2) % m;
		
		int t = dfs(it->fi, x, nd, nd2, n, h+1, flag, depth);
		sz[x] += sz[it->fi];
		cnt += t;
		mx = max(mx, sz[it->fi]);
	}
	mx = max(mx, n-1-cnt);
	if(n > 0 and mx < minValue){
		center = x;
		minValue = mx;
	}
}

int find(int root, int depth){
	int n = dfs(root, -1, 0, 0, 0, 0 true, depth);
	minValue = INF;
	totNodes = dfs(root, -1, 0, 0, n, 0 false, depth);
	dfs(center, -1, 0, 0, n, 0, false, depth);
	return center;
	
}

ll ans;

void solve(int root, int depth){
	rem[depth][0].clear();
	rem[depth][1].clear();
	rem[depth][2].clear();
	rem[depth][3].clear();
	
	rrem[depth][0].clear();
	rrem[depth][1].clear();
	rrem[depth][2].clear();
	rrem[depth][3].clear();
	
	int centroid = find(root, depth);
	int totalNodes = sz[centroid];
	
	if(totalNodes == 1){
		ans += rem[depth][0][0];
		return;
	}
	
	cache[depth][0] = g[centroid];
	cache[depth][1].clear();cache[depth][2].clear();cache[depth][3].clear();
	
	int cnt = 1;
	
	foreach(it, g[centroid]){
		int before = cnt;
		int after = cnt + sz[it->fi];
		cnt = after;
		if(after <= totalNodes/2){
			cache[depth][1].pb(it->fi);
		}	
		else if(before <= totalNodes/2){
			cache[depth][2].pb(it->fi);
		}
		else
			cache[depth][3].pb(it->fi);
	}
	
	g[centroid] = cache[depth][1];
	solve(centroid, depth+1);
	rem[depth][1] = rem[depth+1][0];
	rrem[depth][1] = rrem[depth+1][0];
	
	g[centroid] = cache[depth][2];
	solve(centroid, depth+1);
	rem[depth][2] = rem[depth+1][0];
	rrem[depth][2] = rrem[depth+1][0];
	
	g[centroid] = cache[depth][3];
	solve(centroid, depth+1);
	rem[depth][3] = rem[depth+1][0];
	rrem[depth][3] = rrem[depth+1][0];
	
	
	
	g[centroid] = cache[depth][0];
	
	
}

int main(){
	int n, m;
	sd2(n,m);
	for(int i = 1; i < n; i++){
		int u, v, w; sd3(u,v,w);
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	
	p10[0] = 1;
	for(int i = 0; i <= n; i++){
		p10[i] = p10[i-1] * 10 % m;
	}
	
	solve(0, 0);
	
	return 0;
}
