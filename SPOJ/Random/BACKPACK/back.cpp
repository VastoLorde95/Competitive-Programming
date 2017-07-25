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
	int t, vmax, n, v, c, u, l, vol[61][4], val[61][4], count[61], maxi, dp[2][3201], indx;
	sd(t);
	while(t--){
		sd2(vmax, n); vmax /= 10;
		for(int i = 1; i <= n; i++){
			vol[i][0] = 0;
			vol[i][1] = 0;
			vol[i][2] = 0;
			vol[i][3] = 0;
			
			val[i][0] = 0;
			val[i][1] = 0;
			val[i][2] = 0;
			val[i][3] = 0;
			
			count[i] = 0;
		}//Initialized all arrays to 0
		
		indx = 0;
		dp[1][0] = 0;
		for(int i= 0; i <= vmax; i++) dp[indx][i] = 0; //Base cases initialized to zero
		
		for(int i = 1; i <= n; i++){
			sd3(v, c, u);
			v /= 10;
			if(!u){
				vol[i][0] = v;
				val[i][0] = c*v;
			}
			else{
				count[u]++;
				vol[u][count[u]] = v;
				val[u][count[u]] = c * v;
			}
		}//Input taken
		
		for (int i = 0; i <= n; i++) {
			vol[i][3] = vol[i][0] + vol[i][1] + vol[i][2];
			val[i][3] = val[i][0] + val[i][1] + val[i][2];
			vol[i][1] = vol[i][0] + vol[i][1];
			val[i][1] = val[i][0] + val[i][1];
			vol[i][2] = vol[i][0] + vol[i][2];
			val[i][2] = val[i][0] + val[i][2];
		}//Input formatted
		
		for(int i = 1; i <= n; i++){
			indx = 1 - indx;
			for(int j = 1; j <= vmax; j++){
 				maxi = max(dp[1-indx][j], dp[indx][j-1]);
				if(val[i][0] > 0){
					for(int k = 0; k < 4; k++){
						if(vol[i][k] <= j) maxi = max(maxi, dp[1-indx][j-vol[i][k]] + val[i][k]);
					}
				}
				dp[indx][j] = maxi;
			}
		}
		printf("%d\n",dp[indx][vmax] * 10);
	}
	return 0;
}
