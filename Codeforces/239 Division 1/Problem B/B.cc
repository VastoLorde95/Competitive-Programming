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

int dp[1001][2], n, p[1001], MOD = 1000000007;

int main(){
	sd(n);
	for(int i = 1; i <= n; i++) sd(p[i]);
	
	dp[1][0] = 0;
	dp[1][1] = 1;
	
	for(int i = 2; i <= n; i++){
		dp[i][0] = (dp[i-1][1] + 1)%MOD;
		dp[i][1] = (((dp[i][0] + 2)%MOD + dp[i-1][1])%MOD - dp[p[i]][0] + MOD)%MOD;
	}
	
	printf("%d\n", (dp[n][1]+1)%MOD);
	
	return 0;
}
