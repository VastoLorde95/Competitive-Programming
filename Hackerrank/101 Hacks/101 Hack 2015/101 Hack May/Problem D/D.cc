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

int t, n, k, u, v, w;
long long d[51] , st[51], inf = 1e17;
vector<pair<int,int> > adj[51];
double ans, p[51][51];

void bfs(int x, int prev, long long l){
	d[x] = l;
	for(int i = 0; i < adj[x].size(); i++){
		if(adj[x][i].fi != prev){
			bfs(adj[x][i].fi, x, l+adj[x][i].se);
		}
	}
	return;
}

int main(){
	sd(t);
	while(t--){
		sd2(n,k);
		
		for(int i = 0; i <= n; i++){
			adj[i].clear();
			d[i] = inf;
		}
		
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				p[i][j] = 0;
			}
		}
		
		for(int i = 1; i < n; i++){
			sd3(u,v,w);
			adj[u].pb(mp(v,w));
			adj[v].pb(mp(u,w));
		}
		
		ans = 0;
		p[0][1] = 1;
		bfs(1, -1, 0);
		
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				for(int m = 0; m < adj[j].size(); m++){
					v = adj[j][m].fi;
					if(p[i-1][v] != 0){
						p[i][j] += ((double)(p[i-1][v]) / (double) adj[v].size());
					}
				}
			}
		}
		
		for(int i = 1; i <= n; i++){
			if(p[k][i] > 0){
				ans += (double)(d[i]*p[k][i]);
			}
		}
		
		printf("%.9lf\n", ans);
	}
	return 0;
}
