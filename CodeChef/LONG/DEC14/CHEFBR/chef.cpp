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
	int n, j;
	long long dp[100][100], num[100], marked[100], MOD = 1000000007, temp;
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%lld",&num[i]);
		dp[i][i] = 1;
	}
	for(int j = 1; j < n; j++){
		for(int i = 0; i + j < n; i++){
			temp = dp[i][i+j-1];
			for(int k = i; k < i+j; k++){
				if(num[k] == -num[i+j] and num[k] < 0){
					if(k == i and j == 1) temp = (temp + 1)%MOD;
					else if(k == i) temp = (temp + dp[k+1][i+j-1])%MOD;
					else if(k == i+j-1) temp = (temp + dp[i][k-1])%MOD;
					else temp = (temp + dp[i][k-1]*dp[k+1][i+j-1])%MOD;
				}
			}
			dp[i][i+j] = temp;
		}
	}
	
	printf("%lld\n",dp[0][n-1]);
	
	return 0;
} 
