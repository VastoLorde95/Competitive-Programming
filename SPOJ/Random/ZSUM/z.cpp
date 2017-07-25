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

long long MOD = 10000007;

long long exp(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b&1) ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}
	
int main(){
	long long n,k,res;
	scanf("%lld %lld",&n,&k);
	while(n!= 0 or k != 0){
		res = (2*exp(n-1,k))%MOD;
		res = (res + exp(n,k))%MOD;
		res = (res + (2*exp(n-1,n-1)%MOD))%MOD;
		printf("%lld\n", (res + exp(n,n))%MOD);
		scanf("%lld %lld",&n,&k);
	}
	return 0;
}
