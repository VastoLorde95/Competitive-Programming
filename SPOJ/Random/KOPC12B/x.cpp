#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>
using namespace std;

const int MAXN=2000002;
const int MAXN2=MAXN<<1;
long long factt[MAXN];
long long MODD = 1000000007;
long long n;
void pree()
{
factt[0]=factt[1]=1;
for(int i=2;i<MAXN;++i)
{
factt[i]=factt[i-1]*i;
factt[i]%=MODD;
}
}
long long minv(long long n)
{
	long long ret=1, p = MODD - 2;
	n=factt[n];
	while(p)
	{
		if(p&1)
		{
			ret*=n;
			ret%=MODD;
		}
		p>>=1;
		n*=n;
		n%=MODD;
	}
	return ret;
}

long long ncr(long long n,long long r)
{
	long long ret=factt[n];
	ret%=MODD;
	ret*=minv(n-r);
	ret%=MODD;
	ret*=minv(r);	
	ret%=MODD;
	return ret;
}
int main()
{
	int cases;
	long long ti;
	pree();
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%lld",&n);
		ti=ncr((n<<1)-1LL,n-1LL);
		ti%=MODD;
		ti*=n;
		ti%=MODD;
		printf("%lld\n",ti);
	}
	return 0;
}

