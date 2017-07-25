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

const int N = 100100;
vector<int> g[N], rev[N], scc[N], res;

int t, n, m, k, order[N], degree[N], label[N], total[N], total2[N], rev_degree[N], v[N], comp, p[N], s[N], ptr, q[N+N], tp, be;;

vector<int> g1[N], g2[N];
int indx1[N], indx2[N];

void dfs(int x){
	if(v[x] == 1) return;
	v[x] = 1;
	for(int i = 0; i < g[x].size(); i++) dfs(g[x][i]);
	s[ptr++] = x;
	return;
}

void dfs2(int x, int comp){
	if(v[x] == 1) return;
	v[x] = 1; scc[comp].pb(x); p[x] = comp;
	for(int i = 0; i < rev[x].size(); i++) dfs2(rev[x][i], comp);
	return;
}

void sccomp(){
	ptr = 0;
	for(int i = 1; i <= n; i++) if(!v[i]) dfs(i);
	int cur;
	for(int i = 1; i <= n; i++) v[i] = 0;
	
	while(ptr-1 >= 0){
		cur = s[--ptr];
		if(v[cur] == 1) continue;
		dfs2(cur, comp++);
	}
	return;
}

stack<pair<int,int> > ss;

void dfs3(int cur, int cnt){
	pair<int,int> p1;
	ss.push(mp(cur,cnt));
	
	while(!ss.empty()){
		p1 = ss.top();
		
		total2[p1.fi] = max(total2[p1.fi], total[p1.fi] + p1.se);
		
		if(rev_degree[p1.fi] > 0) rev_degree[p1.fi]--;
		
		if(rev_degree[p1.fi] == 0 and indx2[p1.fi] < g2[p1.fi].size())
			ss.push(mp(g2[p1.fi][indx2[p1.fi]++], total2[p1.fi]));
		else ss.pop();
	}
}

void init(){
	sd3(n,m,k);
		
	memset(order, 0, sizeof order);
	memset(s, 0, sizeof s);
	memset(q, 0, sizeof q);
	memset(degree, 0, sizeof degree);
	memset(rev_degree, 0, sizeof rev_degree);
	memset(label, 0, sizeof label);
	memset(total, 0, sizeof total);
	memset(total2, 0, sizeof total2);
	memset(v, 0, sizeof v);
	memset(indx1, 0, sizeof indx1);
	memset(indx2, 0, sizeof indx2);
	
	int x, y;
	
	for(int i = 1; i <= k; i++){
		sd(x);
		order[x] = 1;
	}
	for(int i = 0; i <= n; i++){
		g[i].clear(); rev[i].clear(); scc[i].clear(); g1[i].clear(); g2[i].clear();
		p[i] = -1;
	}
	
	for(int i = 0; i < m; i++){
		sd2(x,y);
		g[x].pb(y);
		rev[y].pb(x);
	}
	
	comp = 0;
	sccomp();	
}

int main(){
	sd(t);
	while(t--){
		init();
		
		for(int i = 0; i < comp; i++){
			sort(scc[i].begin(), scc[i].end());
			
			foreach(j, scc[i]){
				int u = *j;
				
//				if(t == 0)
//				tr3(i, "----->", u);
				
				for(int k = 0; k < g[u].size(); k++){
					if(p[g[u][k]] != i){
						g1[i].pb(p[g[u][k]]);
						g2[p[g[u][k]]].pb(i);
					}
				}
			}
		}
		
		for(int i = 0; i < comp; i++){
			sort(g1[i].begin(), g1[i].end());
			g1[i].resize(unique(g1[i].begin(), g1[i].end()) - g1[i].begin());
			
			sort(g2[i].begin(), g2[i].end());
			g2[i].resize(unique(g2[i].begin(), g2[i].end()) - g2[i].begin());
			
			foreach(it, scc[i]){
				if(order[*it]){
					if(label[i] == 0) label[i] = *it;
					total[i]++;
				}
			}
			
			degree[i] = g2[i].size();
			rev_degree[i] = g1[i].size();
		}

		int starts = 0, cur;
		res.clear();
		
		be = 0; tp = 0;
		
		memset(v, 0, sizeof v);
		
		for(int i = 0; i < comp; i++){
			if(degree[i] == 0 and label[i] == 0){
				q[tp++] = i;
			}
		}
		
		while(be < tp){
			cur = q[be++];
			v[cur] = 1;
			foreach(it, g1[cur]){
				degree[*it]--;
				if(label[*it] == 0 and degree[*it] == 0) q[tp++] = *it;
			}
		}
		
		be = 0; tp = 0;
		
		for(int i = 0; i < comp; i++){
			if(!v[i] and rev_degree[i] == 0 and label[i] == 0){
				q[tp++] = i;
			}
		}
		
		while(be < tp){
			cur = q[be++];
			v[cur] = 1;
			foreach(it, g2[cur]){
				rev_degree[*it]--;
				if(label[*it] == 0 and rev_degree[*it] == 0) q[tp++] = *it;
			}
		}
		
		int ends = 0, num, tmp;
		
		priority_queue<pair<int,int> > qq;
		
		for(int i = 0; i < comp; i++){
			if(degree[i] == 0 and label[i] > 0){
				starts++;
				qq.push(mp(-label[i],i));
			}
		}
		
		if(starts == 0 or starts > 1){
			printf("-1\n"); continue;
		}
		
		for(int i = 0; i < comp; i++){
			if(rev_degree[i] == 0 and label[i] > 0){
				ends++;
				tmp = i;
			}
		}
		
		if(ends == 0 or ends > 1){
			printf("-1\n"); continue;
		}
		
		
//		tr2("reversing at", tmp);
//		if(t == 0) tr(tmp);
		dfs3(tmp,0);
		
		bool ok = true;
		
		pair<int,int> pp;
		
		int nodes = k;
		res.clear();
		
		memset(v, 0, sizeof v);
		
//		for(int i = 0; i < comp; i++){
//			tr3(i, "========", total2[i]);
//		}
		
		while(!qq.empty()){
			pp = qq.top(); qq.pop();
			cur = pp.se;
			
			if(v[cur]) continue;
			v[cur] = 1;
			
//			if(t == 0)
//			tr(cur);
			
			foreach(it, scc[cur]){
				if(order[*it]){
					nodes--;
					res.pb(*it);
				}
			}
			
			foreach(it, g1[cur]){
				if(total2[*it] == nodes and !v[*it]) qq.push(mp(-label[*it],*it));
			}
		}
		
		if(nodes > 0){
			printf("-1\n"); continue;
		}
		
		foreach(it, res) printf("%d ", *it);
		printf("\n");
		
	}
	return 0;
}
