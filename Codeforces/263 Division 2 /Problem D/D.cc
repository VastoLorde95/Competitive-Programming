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

int n, p, color[100100];
long long MOD = 1e9 + 7, dp[100100][2];
vector<int> g[100100];

void dfs(int cur, int prev){
	dp[cur][0] = 1-color[cur], dp[cur][1] = color[cur];
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur);
		
		long long t1 = dp[cur][0], t2 = dp[cur][1];
		
		dp[cur][0] = (((t1*dp[*it][1])%MOD) + ((t1*dp[*it][0])%MOD))%MOD;
		dp[cur][1] = (((t2*dp[*it][1])%MOD) + ((t2*dp[*it][0])%MOD) + ((t1*dp[*it][1])%MOD))%MOD;		
	}
	return;
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		sd(p);
		g[p].pb(i), g[i].pb(p);
	}
	for(int i = 0; i < n; i++) sd(color[i]);
	
	dfs(0, -1);
	printf("%d\n", (int) dp[0][1]);
	return 0;
}
