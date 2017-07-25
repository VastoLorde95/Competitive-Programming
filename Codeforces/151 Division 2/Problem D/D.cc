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

int n, m, col[100001], u, v, mx, cmx, ans = 1000000;
vector<int> c[100001], adj[100001];

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		sd(col[i]);
		c[col[i]].pb(i);
		cmx = max(cmx, col[i]);
		ans = min(ans,col[i]);
	}
	
	for(int i = 0; i < m; i++){
		sd2(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	set<int> s;
	
	for(int i = 1; i <= cmx; i++){
		s.clear();
		for(int j = 0; j < c[i].size(); j++){
			u = c[i][j];
			for(int k = 0; k < adj[u].size(); k++){
				if(col[adj[u][k]] != i)
					s.insert(col[adj[u][k]]);
			}
		}
		if(s.size() > mx){
			mx = s.size();
			ans = i;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
