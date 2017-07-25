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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 1111;
const int M = 30100;

int n, m;

vector<pii> g[N];
int w[M];
int bad[M], vis[N];

bool dfs1(int x, int y, vector<int> &p){
	if(vis[x]) return false;
	vis[x] = 1;
	if(x == y) return true;
	
	foreach(it, g[x]){
		int nxt = it->fi, id = it->se;
		if(vis[nxt]) continue;
		if(bad[id]) continue;
		
		if(dfs1(nxt, y,p)){
			p.pb(id);
			return true;
		}
	}
	
	return false;
}

int bridge[M], visTime[N], lowVisTime[N], tstamp;

void dfs(int cur, int prev){
	visTime[cur] = lowVisTime[cur] = ++tstamp;
	foreach(it, g[cur]){
		int nxt = it->fi, id = it->se;
		if(bad[id]) continue;
		if(id == prev) continue;
		if(visTime[nxt] != 0){
			lowVisTime[cur] = min(lowVisTime[cur], lowVisTime[nxt]);
			continue;
		}
		
		dfs(nxt, id);
		lowVisTime[cur] = min(lowVisTime[cur], lowVisTime[nxt]);
		
		if(lowVisTime[nxt] > visTime[cur]) bridge[id] = 1;
	}
	
}

int comp[N];

void getComponent(int cur, int prev, int cid){
	if(vis[cur]) return;
	comp[cur] = cid, vis[cur] = 1;
	foreach(it, g[cur]){
		int nxt = it->fi, id = it->se;
		if(bridge[id] or bad[id] or nxt == prev) continue;
		getComponent(nxt, cur, cid);
	}
}

int cid;
vector<pii> bridgeTree[N];

void makeBridgeTree(){
	memset(bridge, 0, sizeof bridge);
	memset(visTime, 0, sizeof visTime);
	memset(lowVisTime, 0, sizeof lowVisTime);
	memset(vis, 0, sizeof vis);
	memset(comp, 0, sizeof comp);
	tstamp = 0;
	cid = 0;
	
	for(int i = 1; i <= n; i++) bridgeTree[i].clear();
	
	for(int i = 1; i <= n; i++){
		if(visTime[i] == 0) dfs(i,-1);
	}
	
	cid = 0;
	for(int i = 1; i <= n; i++)
		if(!vis[i]) getComponent(i,-1, ++cid);
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			if(bad[it->se]) continue;
			if(comp[i] != comp[it->fi]){
				int x = comp[i], y = comp[it->fi];
				bridgeTree[x].pb(mp(y,it->se));
			}
		}
	}
}

ll mcost = 1ll << 40;
vector<int> res;

bool getPath(int cur, int dest, vector<int> &path){
	if(vis[cur]) return false;
	vis[cur] = 1;
	
	if(cur == dest) return true;
	
	foreach(it, bridgeTree[cur]){
		int nxt = it->fi, id = it->se;
		if(vis[nxt]) continue;
		
		if(getPath(nxt, dest, path)){
			path.pb(id);
			return true;
		}
	}
	return false;
}

int main(){
	sd2(n,m);
	int s, t; sd2(s,t);
	for(int i = 1; i <= m; i++){
		int x, y, z; sd3(x,y,z);
		g[x].pb(mp(y,i));
		g[y].pb(mp(x,i));
		w[i] = z;
	}
	
	vector<int> p;
	dfs1(s,t,p);
	if(p.empty()){
		puts("0");
		puts("0");
		return 0;
	}	

	for(int i = 0; i < p.size(); i++){
		if(i > 0) bad[p[i-1]] = 0;
		int id = p[i];
		bad[id] = 1;
		
		memset(vis, 0, sizeof vis);
		vector<int> q;
		if(!dfs1(s,t,q)){
			if(w[id] < mcost){
				mcost = w[id];
				res.clear();
				res.pb(id);
			}
			continue;
		}
		
		makeBridgeTree();
		
		if(comp[s] == comp[t]) continue;

		vector<int> path;
		memset(vis, 0, sizeof vis);
		getPath(comp[s], comp[t],path);
		
		ll minw = 1ll << 40, ans = -1;
		foreach(it, path){
			if(w[*it] < minw){
				minw = w[*it];
				ans = *it;
			}
		}
		if(ans == -1) continue;
		if(minw + w[id] < mcost){
			mcost = minw + w[id];
			res.clear();
			res.pb(id);
			res.pb(ans);
		}
	}
	
	if(mcost == (1ll<<40)){
		puts("-1");
		return 0;
	}
	
	printf("%lld\n", mcost);
	printf("%d\n", (int) res.size());
	foreach(it, res){
		printf("%d ",*it);
	}
	puts("");
	
	return 0;
}
