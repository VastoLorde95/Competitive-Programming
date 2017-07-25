#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int d, n, k, i, j;
	sd(d);
	long long dp[13][99];
	memset(dp, 0, sizeof(dp));
	for(i = 1; i < 13; i++)
		dp[i][0] = 1;
	for(i = 1; i <= 98; i++)
		dp[1][i] = 0;
	for(i = 2; i<= 12; i++){
		for(j = 0; j <= 98; j++)
			if(j - + 1 < 0)
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
			else
				for(k = j - i + 1; k <= j; k++)
					dp[i][j] += dp[i-1][k];
		}
		
	/*for(i = 1; i <=5; i++){
		for(j = 0; j <= 10; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;}*/
		
	while(d--){
			sd2(n,k);
			cout<<dp[n][k]<<endl;
		}
	return 0;
	}
