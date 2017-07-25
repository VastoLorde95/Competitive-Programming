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
int t, n;
long long dp[2000002], MOD = 1000000007, result, a;
long long inv(long long x){
	long long ans = 1,  p = x, n = 1000000005;
	while(n){
		if(n&1) ans = (ans*p)%MOD;
		p = (p*p)%MOD;
		n >>= 1;
	}
	return ans;
}

int main(){
	dp[0] = 1;
	for(long long i = 1; i <= 2000001; i++)
		dp[i] = (dp[i-1]*i) % MOD;
	sd(t);
	a = inv(2);
	while(t--){
		scanf("%d", &n);
		result = ((((inv(dp[n])*inv(dp[n]))%MOD))*a)%MOD;
		result = (result*dp[n+n])%MOD;
		printf("%lld\n", ((result*n)%MOD));
	}
	return 0;
}


