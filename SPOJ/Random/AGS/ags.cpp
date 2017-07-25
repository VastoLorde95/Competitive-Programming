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
	while(b){
		if(b&1) res = (res*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return res;
}

/*Divide and conquer approach for finding the sum of a GP in O(log^2 n) time*/
long long gp(long long r, long long n, long long p){
	if(n == 0)
		return (1%p);
	else if(n == 1)
		return (1+r)%p;
	else{
		if(n&1){
			return ( (  (1 + exp(r,(n+1)/2,p) )%p) * gp(r,(n-1)/2,p) )%p;
		}
		else{
			return (((( (1 + exp(r,n/2,p))     %p) * gp(r,(n-1)/2,p) )%p) + exp(r,n,p))%p;
		}
	}
}

int main(){
	int t;
	int a,d,r,n,MOD;
	long long x,sum;
	sd(t);
	while(t--){
		scanf("%d %d %d",&a,&d,&r);
		scanf("%d %d",&n,&MOD);
		
		x =   (a * exp(r,(n-1)/2,MOD))%MOD;
		sum = (d *  gp(r,(n-1)/2,MOD) )%MOD;		
		
		
		if(n&1){	
			printf("%lld\n",(((x+sum)%MOD) - (d%MOD) + MOD)%MOD);
		}
		else{
			printf("%lld\n",(x+sum)%MOD);
		}
	}
	return 0;
}
