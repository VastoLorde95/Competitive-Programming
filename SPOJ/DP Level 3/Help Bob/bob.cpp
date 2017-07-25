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
	double dp[33000];
	int pizzas[15][2], discount[15][15];
	int m, MASK, i, j, k, temp, temp2;
	double min, area, d;
	sd(m);
	while(m != 0){
		MASK = (1<<m);
		for(i = 0; i < MASK; i++){
			dp[i] = 1e20;
		}
		memset(discount, 0.0, sizeof(discount));
		
		for(i = 0; i < m; i++){
			sd3(pizzas[i][0], pizzas[i][1], temp);
			for( j = 0; j < temp; j++){
				sd(temp2);
				sd(discount[i][temp2-1]);
			}
		}

		min = 1e20;
		dp[0] = 0;
		for(i = 0; i < MASK; i++){
			area = 0.0;
			for(j = 0; j < m; j++){
				if(i & (1 << j)){
					area += pizzas[j][1];
				}
				else{
					d = 1;
					for(k = 0; k < m; k++){
						if(i&(1<<k))
							d *= (100 - discount[k][j])/100.0;
					}
					if((dp[i] + (pizzas[j][0]*d)) < dp[i | (1<<j)])	//I don't have to minimize price/area in the dp but the price itself by chosing appropriate discounts. Then we check that for the minimum prices calculated, if the price/area is less than the previously calculated reuslt
						dp[i|(1<<j)] = (dp[i] + (pizzas[j][0]*d));
				}
			}
			if(i > 0){
				if(dp[i]/area < min){
					min = dp[i]/area;
				}
			}
		}	
		printf("%.4f\n",min);
		sd(m);
	}
	return 0;
}

