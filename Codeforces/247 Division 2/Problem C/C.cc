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
#define fi first
#define se second

using namespace std;

long long MOD = 1000000007, dp[101][2];
int n, k, d;


int main(){
	sd3(n,k,d);
	
	dp[0][0] = 1;
	
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(i+j <= 100){
				if(j >= d){
					dp[i+j][1] += dp[i][0];
					dp[i+j][1] += dp[i][1];
				}
				else{
					dp[i+j][1] += dp[i][1];
					dp[i+j][0] += dp[i][0];
				}	
				
				dp[i+j][0] %= MOD;
				dp[i+j][1] %= MOD;
			}
		}
	}
	
	cout << dp[n][1] << endl;
	
	return 0;
}
