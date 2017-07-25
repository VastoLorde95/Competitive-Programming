#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int LOGN = 17;
const int N = 1<<LOGN;

int n, m;
vector<int> g[N], t[N];
int cycle[N], v[N], ccnt, ok[N], MOD = 1e9 + 7;

int p[LOGN][N], l[N], cnt[N];

pair<int, int> dfs(int cur, int prev){
	if(v[cur]){
		if(cycle[cur] > 0 and ok[cycle[cur]]) return mp(-1,-1);
		ok[++ccnt] = 1;
		cycle[cur] = ccnt;
		return mp(ccnt, cur);
	}
	
	v[cur] = 1;
	
	pair<int,int> ret = mp(-1,-1);
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		pair<int,int> p = dfs(*it, cur);
		if(p != mp(-1,-1)) ret = p;
	}
	
	if(ret == mp(-1,-1)) cycle[cur] = ++ccnt;
	else if(ret.se == cur) ret = mp(-1,-1);
	else cycle[cur] = ret.fi;
	
	return ret;
}

void dfs2(int cur, int prev){
	if(v[cur]) return;
	v[cur] = 1;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		if(cycle[cur] != cycle[*it]){
			int u = cycle[cur], v = cycle[*it];
			t[u].pb(v); t[v].pb(u);
		}
		dfs2(*it, cur);	
	}
}

void dfs3(int cur, int prev, int lvl){
	if(ok[cur]) cnt[cur]++;
	p[0][cur] = prev;
	l[cur] = lvl;
	foreach(it, t[cur]){
		if(*it == prev) continue;
		cnt[*it] += cnt[cur];
		dfs3(*it, cur, lvl+1);
	}
}

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);

	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;

	for(int i = tmp; i >= 0; i--) if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
		
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}

int p2[N];

int main(){
	sd2(n,m);
	int a, b;
	for(int i = 0; i < m; i++){
		sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	dfs(1,-1);
	memset(v, 0, sizeof v);
	dfs2(1,-1);
	dfs3(1,1,1);
	
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= ccnt; j++){
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
	
	p2[0] = 1;
	for(int i = 1; i < N; i++){
		p2[i] = p2[i-1]*2;
		if(p2[i] >= MOD) p2[i] -= MOD;
	}
	
	int k, x, y, lca; sd(k);
	while(k--){
		sd2(x,y);
		x = cycle[x], y = cycle[y];
		if(x == y){
			printf("2\n");
			continue;
		}
		lca = LCA(x,y);
		printf("%d\n", p2[cnt[x] + cnt[y] - 2*cnt[lca] + ok[lca]]);
	}
	
	return 0;
}
