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

int n, m, k, w, cnt, mn, tot, done[1001];
string levels[1001], l;
vector<pair<int, pair<int, int> > > edges;
vector<int> g[1001];
vector<pair<int, int> > res;

const int N = 1001;
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

void dfs(int cur, int prev){
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		cout << *it << " " << cur << "\n";
		dfs(*it, cur);
	}
	return;
}
int main(){ _
	cin >> n >> m >> k >> w;
	
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cin >> l;
			levels[i] += l;
		}
		create(i);
	}
	
	for(int i = 1; i <= k; i++){
		edges.pb(mp(n*m,mp(i,0)));
		for(int j = 1; j <= k; j++){
			if(i == j) continue;
			
			cnt = 0;
			
			for(int ii = 0; ii < n*m; ii++){
				if(levels[i][ii] != levels[j][ii]) cnt += w;
			}
			
			edges.pb(mp(cnt, mp(i,j)));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	foreach(it, edges){
		int u = it->se.fi, v = it->se.se, c = it->fi;
		
		if(find(u) != find(v)){
			tot += it->fi;
			merge(u,v);
			g[v].pb(u);
			g[u].pb(v);
		}
	}
	
	cout << tot << endl;
	
	dfs(0, -1);
	
	return 0;
}
