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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 2011;

int n, d[N][N];
int p[N], rank[N], size[N];
vector<pair<int, pair<int, int> > > e;
vector<pair<int, int> > g[N];

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
	if(rank[px] > rank[py]) p[py] = px;
	else p[px] = py;
	if(rank[px] == rank[py]) rank[py] = rank[py] + 1;
	return;
}

bool dfs(int c, int p, int start, long long dis){
	if(d[start][c] != dis) return false;
	
	foreach(it, g[c]){
		if(it->fi == p) continue;
		
		if(!dfs(it->fi, c, start, dis + it->se)) return false;
	}
	return true;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		create(i);
		for(int j = 1; j <= n; j++){
			sd(d[i][j]);
			if(i == j){
				if(d[i][j] > 0){
					puts("NO"); return 0;
				}
			}
			else e.pb(mp(d[i][j], mp(i,j)));
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(d[i][j] != d[j][i]){
				puts("NO"); return 0;
			}
		}
	}
	
	
	sort(e.begin(), e.end());
	
	int sz = e.size();
	
	for(int i = 0; i < sz; i++){
		int u = e[i].se.fi, v = e[i].se.se, w = e[i].fi;
		if(w == 0){
			puts("NO"); return 0;
		}
		if(find(u) != find(v)){
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));
			merge(u, v);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!dfs(i, -1, i, 0)){
			puts("NO"); return 0;
		}
	}
	
	puts("YES");
	return 0;
}
