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

int cost[51], value[51], k, n, m, i, j, d, e;
float dp[22][101][51][3];
int main(){
	float max;
	int prev_dish, no_times;
	sd3(k,n,m);
	while(k != 0 or n != 0 or m != 0){
		memset(cost, 0, sizeof(cost));
		memset(value, 0, sizeof(value));
		memset(dp, 0, sizeof(dp));
		for( i = 1; i <= n; i++)
			sd2(cost[i], value[i]);
		
		for(i = 0; i <= m; i++){
			for(j = 1; j <= n; j++){
				if(cost[j] <= i){
					dp[1][i][j][0] = value[j];
					dp[1][i][j][1] = 0;
					dp[1][i][j][2] = 1;
				}
				else{
					dp[1][i][j][0] = 0;
					dp[1][i][j][1] = 0;
					dp[1][i][j][2] = 0;
				}
			}
		}
		for( i = 2; i <= k; i++){//day
			for( j = 0; j <= m; j++){//budget
				for( d = 1; d <= n; d++){//dish no.
					max = 0, prev_dish = 0, no_times = 0;
					if(cost[d] <= j){
						for( e = 1; e <= n; e++){
							if(dp[i-1][j-cost[d]][e][0] != 0){
								if(e == d){
									if(dp[i-1][j-cost[d]][e][2] == 2){
										if(dp[i-1][j-cost[d]][e][0] > max){
											max = dp[i-1][j-cost[d]][e][0];
											prev_dish = e;
											no_times = 2;
										}
									}
									else if(dp[i-1][j-cost[d]][e][2] == 1){
										if((dp[i-1][j-cost[d]][e][0] + (float)(0.5 * value[d])) > max){
											max = dp[i-1][j-cost[d]][e][0] + (float)(0.5 * value[d]);
											prev_dish = e;
											no_times = 2;
										}
									}
								}
								else{
									if((dp[i-1][j-cost[d]][e][0] + value[d]) > max){
										max = dp[i-1][j-cost[d]][e][0] + value[d];
										prev_dish = e;
										no_times = 1;
									}
								}
							}
						}
						dp[i][j][d][0] = max;
						dp[i][j][d][1] = prev_dish;
						dp[i][j][d][2] = no_times; 
					}
					else{
						dp[i][j][d][0] = 0;
						dp[i][j][d][1] = 0;
						dp[i][j][d][2] = 0;
					}
				}
			}
		}	
		max = 0;
		int indx = 0, prev_dish = 0, budget = m;
		for(j = 0; j <= m; j++){
			for(i = 1; i <= 50; i++){
				if(dp[k][j][i][0] > max){
					max = dp[k][j][i][0];
					indx = i;
					budget = j;
				}
			}
		}
		printf("%.1f\n",max);
		if(indx != 	0){
			for(i = k; i >= 1; i--){
				cout<<indx<<" ";
				prev_dish = dp[i][budget][indx][1];
				budget = budget - cost[indx];
				indx = prev_dish;
			}
			cout<<endl;	
		}
		cout<<endl;
 		sd3(k,n,m);
	}
	return 0;
}
