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

int n, m, ans, cnt[3001], u, v;
vector<int> adj[3001];

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd2(u,v);
		adj[u].pb(v);
	}
	
	for(int i = 1; i <= n; i++){
		memset(cnt, 0, sizeof cnt);
		for(int j = 0; j < adj[i].size(); j++){
			v = adj[i][j];
			for(int k = 0; k < adj[v].size(); k++){
				if(adj[v][k] != i){
					ans += cnt[adj[v][k]];
					cnt[adj[v][k]]++;
				}
			}
		}
	}
	
	tr(ans);
	
	return 0;
}
