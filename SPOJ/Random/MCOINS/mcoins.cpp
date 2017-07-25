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
	int k,l,m,j;
	sd3(k,l,m);
	int dp[1000001];
	dp[1] = 1;
	dp[k] = 1;
	dp[l] = 1;
	for(int i = 2; i < k; i++){
		dp[i] = (i%2)? 1:0;
	}
	for(int i = k+1 ; i < l; i++){
		dp[i] = abs(min(dp[i-1], dp[i-k]) - 1);
	}
	for(int i = l+1; i <= 1000000; i++){
		dp[i] = abs(min(min(dp[i-1], dp[i-k]), dp[i-l]) - 1);
	}
	for(int i = 0; i < m; i++){
		sd(j);
		if(dp[j]) printf("A");
		else      printf("B");
	}
	return 0;
}
