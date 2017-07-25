#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define SD(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define print(x,y,z) printf("%d %d %d\n",x,y,z);
#define print2(x) printf("%d\n",x);
#define SULL(x) scanf("%ull",&x)

using namespace std;


int main(){
	int T, n, i, j, k, l;
	int dp[11][12];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(i = 1; i < 11; i++)
		dp[i][i] = 1;
		
	for(i = 1; i < 11; i++){
		for( j = 0; j < i; j++){
			if( j == 0 or j == 1){
				for( k = 0; k < 11; k++)
					dp[i][j] += dp[i-1][k];
			}
			else{
				for(k = j-1; k < i-1; k++)
					for(l = j-1; l <= k; l++)
						dp[i][j] += (dp[k][l] * pow(j-1,(i - k - 1)));
				for(k = j-1; k < i; k++)
					dp[i][j] += dp[i-1][k];	 
			} 
		}
	}
	int s;
	for( i = 0; i < 11; i++){
		s = 0;
		for(j = 0; j <= i; j++){
			//cout<<dp[i][j]<<"\t";
			s += dp[i][j];
		}
		dp[i][11] = s;
		//cout<<"\t"<<dp[i][11]<<endl;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",dp[n-1][11]);
	}
	return 0;
}
