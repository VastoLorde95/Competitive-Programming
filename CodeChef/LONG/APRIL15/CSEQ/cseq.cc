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
#define fi first
#define se second

using namespace std;

long long t;
long long n, l, r, mod = 1000003, res, fact[1000005];

/* This function calculates power of p in n! */
long long countFact(long long n, long long p)
{
	long long k=0;
	while (n>=p)
	{
		k+=n/p;
		n/=p;
	}
	return k;
}

/* This function calculates (a^b)%MOD */
long long pow(long long a, long long b, long long MOD)
{
	long long x=1,y=a; 
	while(b > 0)
	{
		if((b&1) > 0) x=(x*y)%MOD;
		y = (y*y)%MOD;
		b >>= 1;
	}
	return x;
}

/* 	Modular Multiplicative Inverse
	Using Euler's Theorem
	a^(phi(m)) = 1 (mod m)
	a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n, long long MOD)
{
	return pow(n,MOD-2,MOD);
}

long long factMOD(long long n, long long MOD)
{
	long long res = 1; 
	while (n > 0)
	{
		res = (res* fact[(n%MOD)])%MOD;
		if ((n/=MOD)%2 > 0) 
			res = MOD - res;
	}
	return res%MOD;
}

long long C(long long n, long long r, long long MOD)
{
	if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
		return 0;

	return (factMOD(n, MOD) * ((InverseEuler(factMOD(r, MOD), MOD) * InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}



int main()
{    
	fact[0] = 1;
	fact[1] = 1;
	for(long long i = 2; i <= mod; i++){
		fact[i] = (i*fact[i-1])%mod;
	}

	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&l,&r);
		
		res = (C((r-l+1)+n, (r-l+1), mod) - 1 + mod)%mod;

		printf("%lld\n",res);
	}
}
