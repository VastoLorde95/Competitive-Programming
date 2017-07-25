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

long long exp(long long a, long long b, long long p){
	long long res = 1;
	//a = a%p;
	while(b>0){
		if(b&1) res = (res*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return res;
}


int main(){
	long long a,b,c,res,MOD=1000000007;
	scanf("%lld %lld %lld",&a,&b,&c);
	while(a != -1){
		if(a%MOD != 0){
			res = exp(b,c,MOD-1);
			res = exp(a,res,MOD);
		}
		else{
			if(b == 0 and c != 0)
				res = 1;
			else 
				res = 0;
		}
		
		printf("%lld\n",res);
		scanf("%lld %lld %lld",&a,&b,&c);
	}
	return 0;
}
