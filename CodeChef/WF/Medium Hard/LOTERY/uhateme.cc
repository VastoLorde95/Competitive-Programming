#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <functional>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <vector>
//#include <bits/stdc++.h>
 
using namespace std;
 
//memset
#define MEMSET_INF 127 // about 2B
#define set0(a) memset(a,0,sizeof(a));
#define setminus1(a) memset(a,-1,sizeof(a));
#define setinf(a) memset(a,MEMSET_INF,sizeof(a));
 
//stl
#define mp make_pair
#define pb push_back
//#define pc(x) putchar_unlocked(x);
//#define gc() getchar_unlocked();
 
 
 
//Loops
#define REP(i,n) for(int i = 0;i < (int)(n); i++)
#define REP1(i,a,b) for(int i = (int)(a);i <= (int)(b); i++)
#define REPMAP(i,mm) for(auto i = mm.begin();i !=mm.end(); i++)
 
//modulo
#define mod %
#define NUM 1000000007
 
//#define morethanonetestcases
//#define testing
 
//limits
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX	9223372036854775807LL
#endif
#ifndef LONG_LONG_MIN
#define LONG_LONG_MIN	(-LONG_LONG_MAX-1)
#endif
#ifndef INT_MAX
#define INT_MAX		2147483647
#endif
#ifndef INT_MIN
#define INT_MIN		(-INT_MAX-1)
#endif
#ifndef M_PI
#define M_PI   3.14159265358979323846264338327950288
#endif
 
#define LMAX LONG_LONG_MAX
#define LMIN LONG_LONG_MIN
#define IMAX INT_MAX
#define IMIN INT_MIN
#define PI M_PI
#define EPS 1e-6
 
//trace
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
 
//typedeff
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;
 
 
//#define putchar_unlocked(x) putchar(x)
//#define getchar_unlocked() getchar()
//#define unordered_map map
 
 
vector<int> primes;
int c[1000000],d[1000000];
int PRIMESar[100005];
int MMI[100005];
int IOTEMP;
 
void markMultiples(bool arr[], int a, int n) {
	int num = 2 * a;
	while (num <= n) {
		arr[num - 1] = 1;
		num += a;
	}
}
 
 
void SieveOfEratosthenes(int n) {
 
	if (n >= 2) {
 
		bool arr[n];
		memset(arr, 0, sizeof(arr));
 
 
		for (int i = 1; i < n; ++i) {
			if (arr[i] == 0) {
 
				primes.pb(i + 1);
				markMultiples(arr, i + 1, n);
			}
		}
	}
}
 
 
 
int powmod(int base, int exponent) {
	ll x = 1, y = base;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			x = (x * y);
			if (x > NUM)
				x %= NUM;
		}
		y = (y * y);
		if (y > NUM)
			y %= NUM;
		exponent /= 2;
	}
	return x;
}
 
int modularMultiplicativeInverse(int a) {
	return powmod(a, NUM - 2);
}
 
int getprimeproduct(int low, int high) {
	if (high < low)
		return 1;
	int ans = ((ll)PRIMESar[high] * (ll)MMI[low - 1]) mod NUM;
	return ans;
}
 
int query(int a, int b) {
	if (a == b)
		return a;
 
	ll ans = 1;
 
	int lowcheck = 1;
	for (int i = 0; primes[i] * primes[i] <= b; i++) {
		int num = primes[i];
		int tobe = 1;
		lowcheck = num;
		while (num <= b) {
			//if in range...
			int aa = (a-1)/ num;
			aa++;
 
			int bb = b/num;
 
			if (aa <= bb) {
				tobe = num;
				num *= primes[i];
			} else {
				break;
			}
		}
		if (tobe != 1){
			ans = (ans * (ll)tobe) mod NUM;
		}
	}
 
 
	int highcheck = 1e7;
	int i = 1;
	while(highcheck > lowcheck + 1){
		int high = b / i;
		int low = (a-1)/ i;
		low++;
		if (high >= highcheck) {
			high = highcheck - 1;
		}
		if (low <= lowcheck) {
			low = lowcheck + 1;
			highcheck = -100;
		}
		int zz = getprimeproduct(low, high);
		if (zz != 1) {
			ans = (ans* (ll)zz) mod NUM;
		}
		highcheck = min(highcheck, low);
		i = max(i+1 , b/highcheck);
	}
 
 
	return ans;
}
 
void scanint( int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;((c<48 || c>57));c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}
 
inline void writeint (int n)
  {
      int N = n, rev, count = 0;
      rev = N;
      if (N == 0) { putchar_unlocked('0'); putchar_unlocked('\n'); return ;}
      while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
      rev = 0;
      while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
      while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10;}
      while (count--) putchar_unlocked('0');
      putchar_unlocked('\n');
  }
 
void solve() {
 
	int NN = 100005;
	SieveOfEratosthenes(NN);
	ll lastprod = 2;
	setminus1(PRIMESar);
	PRIMESar[0] = 1;
	MMI[0] = 1;
	PRIMESar[2] = 2;
	MMI[2] = modularMultiplicativeInverse(2);
	int x = 0;
	for (int i = 1; i < primes.size(); i++) {
		lastprod = (lastprod * primes[i]) mod NUM;
		if(primes[i] < 100005){
			PRIMESar[primes[i]] = lastprod;
			if(lastprod == 1)
				MMI[primes[i]] = 1;
			else
				MMI[primes[i]] = modularMultiplicativeInverse(lastprod);
		}
	}
	for(int i =1; i <100005; i++){
		if(PRIMESar[i] == -1){
			PRIMESar[i] = PRIMESar[i-1];
			MMI[i] = MMI[i-1];
		}
	}
	int t;
	scanint(IOTEMP);
	t = IOTEMP;
	int n, k;
	scanint(IOTEMP);
	n = IOTEMP;
	scanint(IOTEMP);
	k = IOTEMP;
	int a, b, m;
	scanint(IOTEMP);
	a = IOTEMP;
	scanint(IOTEMP);
	b = IOTEMP;
	scanint(IOTEMP);
	m = IOTEMP;
	REP(i,t-1){
		scanint(IOTEMP);
		c[i] = IOTEMP;
	}
	REP(i,t-1){
		scanint(IOTEMP);
		d[i] = IOTEMP;
	}
	
	for (int tt = 0; tt < t; tt++) {
 
		ll ans;
		ans = query(n - k + 1, n);
		IOTEMP = ans;
		writeint(IOTEMP);
		if(tt < t-1){
			n = ((ll)a * ans) mod m;
			n = (n + c[tt]) mod m;
			n++;
			k = ((ll)b * ans) mod n;
			k = (k + d[tt]) mod n;
			k++;
		}
	}
}
 
int main() {
 
	solve();
	return 0;
}
 
