#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <limits.h>
 
using namespace std;
 
// Constants
#define					HODOR unsigned long long
#define 				MOD	  1000003
// Loop Macros
#define rep(i, a, b)	for(int i = (a); i < (b); ++i)
#define dwn(i, a, b)	for(int i = (a); i >= (b); --i)
#define repi(v, c)		for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define dwni(v, c) 		for( typeof( (c).end()) v = (c).end()-1;  v >= (c).begin(); --v)
// Input Macros
#define s(n)			scanf("%d",&n)
#define sc(n)			scanf("%c",&n)
#define sl(n)			scanf("%lld",&n)
#define ss(n)			scanf("%s",n)
// STL Macros
#define pb 				push_back
#define mp              make_pair
#define all(v)          v.begin(), v.end()
#define gc 				getchar_unlocked
#define pc 				putchar_unlocked
 
//	Functions
#define testcases()		int t; for(s(t);t;--t)
 
template<typename X> inline void inp(X &n ) {
    register int ch=gc();int sign=1;n=0;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=gc();}
    while(  ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=gc();
    n=n*sign;
}
 
template<typename X> inline void out(X a) {
    char snum[20]; int i=0;
    do {snum[i++]=a%10+48; a=a/10; }while(a!=0);
    i=i-1;
    while(i>=0) pc(snum[i--]);
    pc('\n');
}
 
int fact[MOD+5], a, b, ans, num, den;
 
void pre_cal() {
	fact[0] = fact[1] = 1;
	rep(i, 2, MOD+5) 
		fact[i] = (1ULL * fact[i-1] * i)%MOD;
}
 
int exp(int a, int n) {
	int res = 1;
	while ( n ) {
		if ( n&1 ) res=(1LL*res*a)%MOD;
		a = (1LL*a*a)%MOD;
		n >>= 1;
	}
	return res;
}
 
int binomialCoeff(HODOR y, HODOR x) {
	ans = 1;
	while( y ) {
		a = y%MOD, y /= MOD;
		b = x%MOD, x /= MOD;
		if ( b > a )
			return MOD-1;
		num = fact[a];
		den = ( 1ULL * fact[a-b] * fact[b] )%MOD;
		ans = ( 1ULL * ans * ( 1ULL * num * exp(den, MOD-2) )%MOD)%MOD;
	}
	return (ans+MOD-1)%MOD;
}
 
 
int main() {
// freopen("ip","r",stdin);
	int n, l, r;
	pre_cal();
	testcases() {
		inp(n), inp(l), inp(r);
		printf("%d\n", binomialCoeff(1ULL + r - l + n, n));
	}
	return 0;
} 
