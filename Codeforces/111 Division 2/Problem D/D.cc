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

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef pair<int,int> pii;

const int N = 100100;
int p[N], rank[N], size[N], ans[N], used[N];

int disc[N], low[N], pa[N], t[N], visited[N], tme;

int n, m;

vector<pair<pii, pii> > e;
vector<pii> g[N];
set<pii> bridge;

void create(int x){
	p[x] = x;
	rank[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rank[px] > rank[py]) p[py] = px;
	else p[px] = py;
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

void dfs(int cur){
	visited[cur] = 1;
	disc[cur] = low[cur] = tme++;
	foreach(it, g[cur]){
		if(used[it->se]) continue;
		used[it->se] = 1;
		
		if(!visited[it->fi]){
			pa[it->fi] = cur;
			dfs(it->fi);
			low[cur] = min(low[cur], low[it->fi]); 
			
			if(disc[cur] < low[it->fi]){
				bridge.insert(mp(cur, it->fi));
				bridge.insert(mp(it->fi, cur));
			}
		}
		else{
			low[cur] = min(low[cur], disc[it->fi]);
		}
	}
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++) create(i);
	for(int i = 0; i < m; i++){
		int a, b, w; sd3(a,b,w);
		e.pb(mp(mp(w,i),mp(a,b)));
	}
	
	sort(e.begin(), e.end());
	
	for(int i = 0; i < m; i++){
		int w = e[i].fi.fi;
		vector<int> to_visit;
		for(int j = i; j < m and e[j].fi.fi == w; j++){
			int x = find(e[j].se.fi), y = find(e[j].se.se), id = e[j].fi.se;
			if(x == y) continue;
			
			g[x].pb(mp(y,id));
			g[y].pb(mp(x,id));
			
			to_visit.pb(x);
			to_visit.pb(y);
		}
		
		// find bridge edges
		bridge.clear();		
		for(int j = 0; j < to_visit.size(); j++){
			if(!visited[to_visit[j]]){
				int start = to_visit[j];
				pa[start] = -1, tme = 0;
				dfs(start);
			}
		}

		for(int j = i; j < m and e[j].fi.fi == w; j++){
			int x = find(e[j].se.fi), y = find(e[j].se.se);
			if(x == y) continue;
			
			if(bridge.count(mp(x,y))) ans[e[j].fi.se] = 1; else ans[e[j].fi.se] = 2;
		}
		
		while(i < m and e[i].fi.fi == w){
			int x = find(e[i].se.fi), y = find(e[i].se.se);
			g[x].clear(); g[y].clear();
		
			low[x] = low[y] = N;
			t[x] = t[y] = N;
			visited[x] = visited[y] = 0;
			merge(x, y);
			i++;
		}
		i--;
		
	}
	
	for(int i = 0; i < m; i++){
		if(ans[i] == 0) puts("none");
		else if(ans[i] == 1) puts("any");
		else puts("at least one");
	}
	
	return 0;
}
