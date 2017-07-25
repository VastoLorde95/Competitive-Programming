#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 100100;
int p[N], rank[N], size[N];

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

int n, m, a, b, c, v[N], col[N];
vector<pair<int, pair<int, int> > > edges;
vector<int> g[N];

bool dfs(int cur, int prev, int color){
	if(v[cur] == 1){
		if(col[cur] != color) return false;
		return true;
	}
	v[cur] = 1;
	col[cur] = color;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		if(!dfs(*it, cur, (color == 1)? 2: 1)) return false;
	}
	return true;
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++) create(i);
	
	for(int i = 0; i < m; i++){
		sd3(a,b,c);
		edges.pb(mp(c,mp(a,b)));
		if(c == 1) merge(a,b);
	}
	
	for(int i = 0; i < m; i++){
		if(edges[i].fi == 0){
			a = find(edges[i].se.fi), b = find(edges[i].se.se);
			g[a].pb(b);
			g[b].pb(a);
		}
	}	
	
	for(int i = 1; i <= n; i++){
		if(find(i) == i and v[i] == 0){
			if(!dfs(i,-1,1)){
				cout << 0 << endl; return 0;
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		if(edges[i].fi == 0){
			a = edges[i].se.fi, b = edges[i].se.se;
			merge(a,b);
		}
	}	
	
	set<int> s;
	
	for(int i = 1; i <= n; i++){
		s.insert(find(i));
	}
	
	long long ans = 1;
	for(int i = 1; i < s.size(); i++){
		ans = (ans*2)%1000000007;
	}
	tr(ans);
	
	return 0;
}
