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
	int s, n, size[2001], value[2001];
	int dp[2][2001], maxi, indx;
	sd2(s,n);
	for(int i = 1; i <= n; i++){
		sd2(size[i],value[i]);
	}
	memset(dp, 0, sizeof(dp));
	maxi = 0, indx = 0;
	for(int i = 1; i <= n; i++){
		indx = 1 - indx;
		for(int j = 1; j <= s; j++){
			if(size[i] <= j)
				dp[indx][j] = max(dp[1-indx][j-size[i]] + value[i], dp[1-indx][j]);
			else
				dp[indx][j] = dp[1-indx][j];
			if(dp[indx][j] > maxi)
				maxi = dp[indx][j];
		}
	}	
	printf("%d\n",maxi);
	return 0;
}
