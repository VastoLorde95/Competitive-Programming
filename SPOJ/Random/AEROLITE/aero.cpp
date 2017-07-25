#include <iostream>
#include <cstring>
using namespace std;
 
int MOD = 11380;
int memo[12][12][12][32];
 
int solve(int c1, int c2, int c3, int d) {
  if (c1<0 || c2<0 || c3<0 || d<0) return 0;
  if (c1+c2+c3==0) return 1;
  int &res = memo[c1][c2][c3][d];
  if (res >= 0) return res;
  res = 0;
  // parenthesis first
  for (int c3in=0; c3in<c3; c3in++)
    res = (res + solve(0,0,c3in,d-1)*solve(c1,c2,c3-c3in-1,d)) % MOD;
  // bracket first
  for (int c2in=0; c2in<c2; c2in++)
    for (int c3in=0; c3in<=c3; c3in++)
      res = (res + solve(0,c2in,c3in,d-1)*solve(c1,c2-c2in-1,c3-c3in,d)) % MOD;
  // curly brace first
  for (int c1in=0; c1in<c1; c1in++)
    for (int c2in=0; c2in<=c2; c2in++)
      for (int c3in=0; c3in<=c3; c3in++)
        res = (res + solve(c1in,c2in,c3in,d-1)*solve(c1-c1in-1,c2-c2in,c3-c3in,d)) % MOD;
  return res;
}
 
int main() {
  memset(memo,-1,sizeof(memo));
  int c1,c2,c3,d;
  while (cin >> c1 >> c2 >> c3 >> d) cout << (solve(c1,c2,c3,d)-solve(c1,c2,c3,d-1)+MOD)%MOD << endl;
}
