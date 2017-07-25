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

double dp[2001][2001], p;
int n, t;
int main(){
	scanf("%d %lf %d",&n, &p, &t);
	
	for(int i = 1; i <= t; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = (p*(1+dp[i-1][j-1]) + (1-p)*dp[i-1][j]);
		}
	}
	printf("%.7lf\n", dp[t][n]);
	return 0;
}
