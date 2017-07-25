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

int t, n, d[500100], a[500100], dp[500100][2], v[500100], root;
vector<int> g[500100];

void dfs(int cur, int prev){
	foreach(it, g[cur]){
		if(*it == prev) continue;
		dfs(*it,cur);
		
		dp[cur][1] += min(dp[*it][0], dp[*it][1]);
		dp[cur][0] += dp[*it][1];
	}
	
	if(a[cur] == 1){
		dp[cur][0] = dp[cur][1] = min(dp[cur][1],dp[cur][0]);
	}
	else{
		dp[cur][1]++;		
	}
	return;
}

int main(){
	sd(t);
	while(t--){
		sd(n);
		for(int i = 1; i <= n; i++){
			g[i].clear();
			d[i] = 0, dp[i][0] = dp[i][1] = 0, v[i] = 0;
			sd(a[i]);
		}
		int x, y;
		for(int i = 1; i < n; i++){
			sd2(x,y);
			g[x].pb(y);
			g[y].pb(x);
		}
		
		dfs(1,-1);
		
		printf("%d\n", min(dp[1][0],dp[1][1]));
		
	}
	return 0;
}
