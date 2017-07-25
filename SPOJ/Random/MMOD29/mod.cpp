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

int n, mod = 29;
long long res;

long long exp(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b&1) ans = (ans*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	sd(n);
	while(n){
		res = (((exp(167,n+1) + 28)%mod * ((exp(3,n+1) + 28)%mod * (exp(2, 2*n + 1)+28)%mod)%mod)*9)%mod;
		printf("%lld\n",res);
		sd(n);
	}
	return 0;
}
