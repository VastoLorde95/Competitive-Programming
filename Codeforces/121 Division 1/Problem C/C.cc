#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int LOGN = 17;
const int N = 1<<LOGN;

int n, cnt[N], val[N], p[LOGN][N], l[N], v[N];
vector<pair<int, int> > g[N];
vector<int> levels[N];
int mxl;

void dfs(int cur, int prev){
	p[0][cur] = prev;
	l[cur] = l[prev]+1;
	mxl = max(mxl, l[cur]);
	levels[l[cur]].pb(cur);
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		dfs(it->fi, cur);
	}
}

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}



int main(){
	sd(n);
	int a, b;
	for(int i = 1; i < n; i++){
		sd2(a,b);
		g[a].pb(mp(b,i));
		g[b].pb(mp(a,i));
	}
	
	l[1] = -1;
	dfs(1, 1);
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}

	int k;
	sd(k);
	
	while(k--){
		sd2(a,b);
		int lca = LCA(a,b);
//		tr3(a,b,lca);
		cnt[lca] -= 2;
		cnt[a] += 1;
		cnt[b] += 1;
	}
	
	for(int i = mxl; i >= 0; i--){
		foreach(tmp, levels[i]){
			int u = *tmp;
			v[u] = 1;
//			tr3(u, cnt[u], i);
			foreach(it, g[u]){
				if(v[it->fi]) continue;
				val[it->se] = cnt[u];
				cnt[it->fi] += cnt[u];
			}
		}
	}
	
	for(int i = 1; i < n; i++) printf("%d ", val[i]); puts("");
	
	return 0;
}
