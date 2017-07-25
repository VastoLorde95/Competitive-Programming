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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int n, mix[101], dp[101][101][2], INF = 1<<30, MOD = 100, j, temp;
	while(scanf("%d",&n)!=-1){
		for(int i = 1; i <= n; i++){
			sd(mix[i]);
		}
		
		for(int i = 1;  i <= n; i++){
			dp[i][i][0] = mix[i];	//(a+b)%100
			dp[i][i][1] = 0;	//Smoke
		}
		for(int l = 2; l <= n; l++){
			for(int i = 1; i <= n-l+1; i++){
				j = i + l -1;
				dp[i][j][1] = INF;
				for(int k = i; k <= j-1; k++){
					temp = dp[i][k][1] + dp[k+1][j][1] + dp[i][k][0]*dp[k+1][j][0];
					if(temp < dp[i][j][1]){
						dp[i][j][0] = (dp[i][k][0] + dp[k+1][j][0])%MOD;
						dp[i][j][1] = temp;
					}
				}
			}
		}
		/*for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout<<dp[i][j][1]<<"\t"<<dp[i][j][0]<<"\t";
			}	
			cout<<endl;
		}*/
				
		printf("%d\n",dp[1][n][1]);
	}
	return 0;
}
