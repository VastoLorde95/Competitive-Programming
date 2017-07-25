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

using namespace std;

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int LOGN = 17, N = 100100;

int n, m;
vector<pair<int, int> > g[N];
int bridge[N];
int visTime[N], lowVisTime[N], tstamp;

void dfs(int cur, int prev){
	visTime[cur] = lowVisTime[cur] = ++tstamp;
	foreach(it, g[cur]){
		int nxt = it->fi, id = it->se;
		if(nxt == prev) continue;
		if(visTime[nxt] != 0){
			lowVisTime[cur] = min(lowVisTime[cur], lowVisTime[nxt]);
			continue;
		}
		
		dfs(nxt, cur);
		lowVisTime[cur] = min(lowVisTime[cur], lowVisTime[nxt]);
		
		if(lowVisTime[nxt] > visTime[cur]) bridge[id] = 1;
	}
	
}

int vis[N];
int comp[N];

void getComponent(int cur, int prev, int cid){
	if(vis[cur]) return;
	comp[cur] = cid, vis[cur] = 1;
	foreach(it, g[cur]){
		int nxt = it->fi, id = it->se;
		if(bridge[id] or nxt == prev) continue;
		getComponent(nxt, cur, cid);
	}
}

int cid;
vector<int> bridgeTree[N];

void makeBridgeTree(){
	dfs(1,-1);
	
	cid = 0;
	for(int i = 1; i <= n; i++)
		if(!vis[i]) getComponent(i,-1, ++cid);
	
	for(int i = 1; i <= n; i++)
		foreach(it, g[i])
			if(comp[i] != comp[it->fi]){
				int x = comp[i], y = comp[it->fi];
				bridgeTree[x].pb(y);
			}
}

int p[LOGN][1<<LOGN], l[1<<LOGN];

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);

	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;

	for(int i = tmp; i >= 0; i--) if(l[x] - (1<<i) >= l[y]) x = p[i][x];

	if(x == y) return y;
	for(int i = tmp; i >= 0; i--) if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];
	return p[0][x];
}

void bridgeTreeDfs(int cur, int prev){
	p[0][cur] = prev;
	foreach(it, bridgeTree[cur]){
		if(*it == prev) continue;
		l[*it] = l[cur] + 1;
		bridgeTreeDfs(*it, cur);
	}
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= m; i++){
		int a, b; sd2(a,b);
		g[a].pb(mp(b,i));
		g[b].pb(mp(a,i));
	}
	
	makeBridgeTree();
	
	bridgeTreeDfs(1,1);
	
	for(int i = 1; i < LOGN; i++) for(int j = 1; j <= cid; j++) p[i][j] = p[i-1][p[i-1][j]];
	
	int k; sd(k);
	while(k--){
		int x, y, z; sd2(x,y);
		x = comp[x], y = comp[y];
		z = LCA(x,y);
		printf("%d\n", l[x] - l[z] + l[y] - l[z]);
	}
	
	return 0;
}
