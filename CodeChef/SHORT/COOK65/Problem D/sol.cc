#include<bits/stdc++.h>

using namespace std;

const int md = 1000000007;

void add(int &x, int y) {
	x += y;
	if (x >= md) x -= md;
}

/*

We build each element of V, digit by digit i.e. in each step try out all possible combinations of the m'th digits for each element
of V, and see if we can obtain the substring "47" while maintaining the fact that if all X consisted of only the m smallest digits,
then do the current elements of V satisfy the constraints as imposed on them by the vector S? Thus we can check if a particular combination
for V is valid, and if it is valid, does it contain the string "47"? To maintain transitions correctly, we keep a track of the carry from
the first (m-1) digits of V and the most significant digit from the sum of the first (m-1) digits of V.

dp[m][i][mask][sum][state] denotes the number of ways we can make a vector V that satisfies all conditions such that
-> The numbers in V have exactly m digits (including 0 prefixes)
-> The sum of the m'th digits of the first i numbers is sum
	i.e. sigma (j = 1 to i) V[j][m] = sum
-> mask :=
	If the j'th bit is 0, then the j'th element if V satisfies its constraints as imposed by S[j]
	If the j'th bit is 1, then the j'th element if V does not satisfy the constraints as imposed by S[j]
-> state :=
	0 => we haven't found "47", after building V such that the elements of V had exactly (m-1) digits
	1 => The most significant digit in the sum of the elements of V when each element had exactly (m-1) digits is "7"
	2 => we have already encountered 47 as a substring in the sum

Since each element in the vector V can have atmost 18 digits, we look at the number of ways we can get the result
when the final mask is 0 i.e. all elements satisfy their respective constraints and :-
ok = 2 and the most significant digit of the sum can be any digit from 0 to 9
ok = 1, i.e. the second most significant digit is 7 and the most significant digit is 4 i.e. sum = 4

*/
int s[8], dp[19][9][1 << 8][80][3];
long long x[8];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %lld", s + i, x + i);

	dp[0][0][0][0][0] = 1;

	for (int k = 0; k < 18; k++) {
		for (int p = 0; p < n; p++) {
			for (int mask = 0; mask < (1 << n); mask++) {
				for (int sum = 0; sum < 80; sum++) {
					for (int ok = 0; ok < 3; ok++) {
						int f = dp[k][p][mask][sum][ok], xd = x[p] % 10;
					
						if (f == 0) continue;
					
						int sub = mask & ((1 << n) - (1 << p) - 1);
						for (int d = 0; d < xd; d++)
							add(dp[k][p + 1][sub | (s[p] << p)][sum + d][ok], f);
					
						add(dp[k][p + 1][mask][sum + xd][ok], f);
						for (int d = xd + 1; d < 10; d++)
							add(dp[k][p + 1][sub | ((s[p] ^ 1) << p)][sum + d][ok], f);
					}
				}
			}
		}
	
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int sum = 0; sum < 80; sum++) {
				add(dp[k + 1][0][mask][sum / 10][2], dp[k][n][mask][sum][2]);
			
				int ok = 0;
				if (sum % 10 == 7) ok = 1;
				if (sum % 10 == 4) ok = 2;
				add(dp[k + 1][0][mask][sum / 10][ok], dp[k][n][mask][sum][1]);
				add(dp[k + 1][0][mask][sum / 10][ok % 2], dp[k][n][mask][sum][0]);
			}
		}
	
	
		for (int i = 0; i < n; i++) x[i] /= 10;
	}


	int ans = dp[18][0][0][4][1];
	for (int i = 0; i < 9; i++) add(ans, dp[18][0][0][i][2]);
	
	printf("%d\n", ans);
	
	return 0;
}

