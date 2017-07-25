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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	

int n, T, t[5001], b;
double dp[5001][5001], p[5001], a, temp, res, sum;
int main(){
	sd2(n,T);
	for(int i = 1; i <= n; i++){
		scanf("%lf %d",&a,&b);
		p[i] = a/100.0;
		t[i] = b;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		sum = dp[i-1][i-1], temp = pow((1-p[i]), t[i] - 1);
		for(int j = i; j <= T; j++){
			if(j-t[i] >= 0){
				sum -= dp[i-1][j-t[i]]*temp;
				dp[i][j] += dp[i-1][j-t[i]]*temp;
			}
			dp[i][j] += sum * p[i];
			
			sum *= (1-p[i]);
			sum += dp[i-1][j];	
			
			res += dp[i][j];
		}
	}
	
	printf("%.7lf\n",res);
	return 0;
}
