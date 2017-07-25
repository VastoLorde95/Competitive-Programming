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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, u, v, c, t, kk, ti, d[100001], inf = 2e9;
vector<pair<int, int> > g[100001];
vector<int> k[100001];

void solve(){
	priority_queue<pair<int, int> > q;
	q.push(mp(0, 1));
	while(!q.empty()){
		u = q.top().se, t = -q.top().fi; q.pop();
		
		if(d[u] != inf) continue;
		
		d[u] = t;
		
		if(u == n) break;
		
		for(int i = 0; i < k[u].size(); i++){
			if(k[u][i] == d[u]){
				d[u]++;
			}
		}
		
		for(int i = 0; i < g[u].size(); i++){
			v = g[u][i].fi, c = g[u][i].se;
			if(d[v] == inf){
				q.push(mp(-(d[u]+c), v));
			}
		}	
	}
	return;	
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd3(u,v,c);
		g[u].pb(mp(v,c));
		g[v].pb(mp(u,c));
	}
	
	for(int i = 1; i <= n; i++){
		sd(kk);
		d[i] = inf;
		for(int j = 0; j < kk; j++){
			sd(ti);
			k[i].pb(ti);
		}
	}
	
	solve();
	
	printf("%d\n", (d[n] == inf)? -1: d[n]);
		
	return 0;
}
