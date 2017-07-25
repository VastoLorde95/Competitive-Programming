#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int t, n, b[1100], dp[1100][1100], MOD = 1000000007, temp;

int main(){
	sd(t);
	while(t--){
		sd(n);
		
		for(int i = 1; i <= n; i++)	sd(b[i]);
		
		dp[0][0] = 1;
		
		for(int i = 1; i <= n; i++){
			temp = min(i, b[i]);
			for(int j = n; j > temp; j--) dp[i][j] = 0;
			for(int j = b[i]; j > 0; j--){
				dp[i][j] = (dp[i-1][j-1] + dp[i][j+1])%MOD;
				
				if(dp[i][j] >= MOD){
					dp[i][j] -= MOD;
				}
			}
			dp[i][0] = dp[i][1];
		}
		
		printf("%d\n",dp[n][0]);
	}
	return 0;
}
