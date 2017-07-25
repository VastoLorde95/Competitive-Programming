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

using namespace std;

int n, p, a, b, d, in[1001], out[1001], type[1001];
vector<pair<int, int> > adj[1001];
vector<pair<int, pair<int, int> > > res;

void dfs(int node, int di, int head){
	if(type[node] == 1){
//		tr3("this?",node, head);
		res.pb(mp(head, mp(node, di)));
		return;
	}
	for(int i = 0; i < adj[node].size(); i++){
		dfs(adj[node][i].fi, min(di, adj[node][i].se), head);
	}
	return;
}

int main(){
	sd2(n,p);
	
	for(int i = 0; i < p; i++){
		sd3(a,b,d);
		out[a]++, in[b]++;
		adj[a].pb(mp(b,d));		
	}
	
	for(int i = 1; i <= n; i++){
		if(in[i] == 1 and out[i] == 0) type[i] = 1;
		else if(in[i] == 0 and out[i] == 1) type[i] = 2;
	}
	
	for(int i = 1; i <= n; i++){
		if(type[i] == 2){
//			tr2(1,i);
			for(int j = 0; j < adj[i].size(); j++){
				dfs(adj[i][j].fi, adj[i][j].se, i);
			}
		}
	}
	
	printf("%d\n", (int) res.size());
	
	sort(res.begin(), res.end());
	
	for(int i = 0; i < res.size(); i++){
		printf("%d %d %d\n", res[i].fi, res[i].se.fi, res[i].se.se);
	}
	
	return 0;
}
