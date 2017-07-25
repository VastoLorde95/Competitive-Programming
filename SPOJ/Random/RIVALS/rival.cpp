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
int t;
long long dp[2000001], MOD = 1000000007, result;
int x, y;

long long inv(long long p){
	long long ans = 1, n = 1000000005;
	while(n){
		if(n&1) ans = (ans*p)%MOD;
		p = (p*p)%MOD;
		n >>= 1;
	}
	return ans;
}

int main(){
	dp[0] = 1;
	for(int i = 1; i <= 2000000; i++)
		dp[i] = (dp[i-1]*i) % MOD;
	sd(t);
	while(t--){
		scanf("%lld %lld", &x, &y);
		result = (inv(dp[x])*inv(dp[y]))%MOD;
		result = (result*dp[x+y])%MOD;
		printf("%lld\n", result);
	}
	return 0;
}


