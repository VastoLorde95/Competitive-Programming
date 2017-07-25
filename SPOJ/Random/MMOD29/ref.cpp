/*
Problem Name : MMOD29
Problem Number : SPOJ 3909
Link : http://www.spoj.pl/problems/MMOD29/en/
Problem Type : Math
Difficulty : 4.5 / 10
Interest : 6 / 10
Complexity : O(lgX)
Date : December 2, 2010
*/

#include <stdio.h>

#define rep(i,n) for(i=0;i<(n);i++)

int bigmod(int b, int p, int m) {
 if(p == 0) return 1;
 if(p == 1) return b%m;
 if(p&1) return ((b%m) * bigmod(b,p-1,m)) % m;
 else {
  int sq = bigmod(b,p/2,m);
  return (sq * sq) % m;
 }
}

int main() {
 int n,res,i,x;
 int primes[] = {2,3,167};
 int powers[] = {2,1,1};
 int MOD = 29;
 while(scanf(" %d",&n) == 1) {
  if(n == 0) break;
  res = 1;
  rep(i,3) {
   x = (bigmod(primes[i],powers[i]*n+1,MOD) - 1 + MOD) % MOD;
   res = (res * x) % MOD;
   x = bigmod(primes[i]-1,MOD-2,MOD);
   res = (res * x) % MOD;
  }
  printf("%d\n",res);
 }
 return 0;
}
