#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

const int MAX_SUM = 600 + 10;
const int MAX_NUMBER_OF_PARTS = 600 + 10;
const int MAX_XOR_VALUE = 1024 + 10;
const int MOD = 1000000000 + 7;
const int MAX_NUMBER_OF_GROUPS = 10 + 10;

bool is_xor_reachable[MAX_SUM][MAX_NUMBER_OF_PARTS][MAX_XOR_VALUE];
int dp[MAX_SUM][MAX_NUMBER_OF_GROUPS][MAX_XOR_VALUE];
int grundy[MAX_SUM];
int n, m, k;

void calculate_grundy_numbers () {
	if (k == 2) {
		for(int i = 2; i <= n; i++)
			grundy[i] = 1 - i % 2;
		return ;
	}
	if (k > 3) {
		for(int i = 1; i <= n; i++)
			grundy[i] = i - 1;
		return ;
	}
	grundy[1] = 0;
	for(int i = 2; i <= k; i++)
		is_xor_reachable[i][i][0] = true;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= MAX_XOR_VALUE; j++) {
			bool is_xor_found = false;
			for(int p = 1; p <= k; p++)
				if (is_xor_reachable[i][p][j]) {
					is_xor_found = true;
					break;
				}
			if (!is_xor_found) {
				grundy[i] = j;
				break;
			}
		}
		for(int j = 2; j <= k; j++)
			if (i * j <= n) 
				is_xor_reachable[i * j][j][(j % 2) * i] = true;
		for(int j = 1; j <= i; j++) 
			if (j + i <= n)
				is_xor_reachable[i + j][2][grundy[i] ^ grundy[j]] = true;
		for(int j = 1; j <= n - i; j++)
			for(int p = 1; p < k; p++)
				for(int x = 0; x <= MAX_XOR_VALUE; x++) if (((x ^ grundy[i]) < MAX_XOR_VALUE) && is_xor_reachable[j][p][x])
					is_xor_reachable[j + i][p + 1][x ^ grundy[i]] = true;
	}
}

inline void update (int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main () {
	cin >> n >> m >> k;
    assert(1 <= m && m <= 10);
    assert(m <= n && n <= 600);
    assert(2 <= k && k <= 600);
	calculate_grundy_numbers();
//	brute_calculate_grundy_numbers();
    
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int x = 0; x < MAX_XOR_VALUE; x++) if (dp[i][j][x])
				for(int y = 1; y <= n - i; y++)
					update(dp[i + y][j + 1][x ^ grundy[y]], dp[i][j][x]);		
	int ret = 0;	
	for(int i = 1; i < MAX_XOR_VALUE; i++)
		update(ret, dp[n][m][i]);
	cout << ret << endl;
	return 0;
}
