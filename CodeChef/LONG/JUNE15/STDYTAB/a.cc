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

int t, n, m;
long long c[4001][4001], dp[2001][2001], MOD = 1e9;

int main(){
	
	for(int i = 0; i <= 4000; i++){
		c[i][0] = c[i][i] = 1;
	}
	
	for(int i = 0; i <= 4000; i++){
		for(int j = 1; j < i; j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
		}
	}
	
	sd(t);
	
	for(int i = 1; i <= 2000; i++){
		dp[i][0] = 1;
	}
	
	while(t--){
		sd2(n,m);
		
		for(int i = 1; i <= m; i++){
			dp[1][i] = (dp[1][i-1] + c[i+m-1][i])%MOD;
		}
		
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = (dp[i][j-1] + ((c[j+m-1][j]*dp[i-1][j])%MOD))%MOD;
			}
		}
		
		cout << dp[n][m] << "\n";
	}
		
	return 0;
}
