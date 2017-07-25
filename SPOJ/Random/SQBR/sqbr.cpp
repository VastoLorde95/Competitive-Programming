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
	int d, n, k, temp, open[39], dp[39][39];
	sd(d);
	while(d--){
		sd2(n,k);
		for(int i = 1; i < 39; i++)
			open[i] = 0;
			
		for(int i = 0; i < k; i++){
			sd(temp);
			open[temp] = 1;
		}
		
		dp[1][1] = 1;
		
		for(int i = 1; i <= 2*n; i++){
			for(int j = 0; j <= i; j++){
				if(i == 1){
					dp[i][j] = (j == 1)? 1:0;
				}
				else{
					if(open[i] == 1){
						dp[i][j] = (j == 0)? 0:dp[i-1][j-1];
					}
					else{
						dp[i][j] = dp[i-1][j+1] + ((j==0)?0:dp[i-1][j-1]);
					}
				}	
			}
		}
		
		printf("%d\n",dp[2*n][0]);
		
	}
	
	return 0;
}
