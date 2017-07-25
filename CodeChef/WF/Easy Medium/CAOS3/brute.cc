#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int maxn = 20;

int memo[maxn][maxn][maxn][maxn];
int mark[maxn][maxn][maxn][maxn], stamp;
int n, m;
bool canClick[maxn][maxn];

inline int getSG(int xl, int xr, int yl, int yr)
{
	if (xl > xr || yl > yr) {
		return 0;
	}
	int &ts = mark[xl][xr][yl][yr];
	int &sg = memo[xl][xr][yl][yr]; // to see the memo first
	if (ts != stamp) {
		ts = stamp;
	} else {
		return sg;
	}
	
	// get SG recursively
	vector<int> occur;
	for (int x = xl; x <= xr; ++ x) {
		for (int y = yl; y <= yr; ++ y) {
			if (canClick[x][y]) {
				int s = getSG(xl, x - 1, yl, y - 1)
					  ^ getSG(x + 1, xr, yl, y - 1)
					  ^ getSG(xl, x - 1, y + 1, yr)
					  ^ getSG(x + 1, xr, y + 1, yr);
				occur.push_back(s);
			}
		}
	}
	// calculate mex function
	sort(occur.begin(), occur.end());
	occur.erase(unique(occur.begin(), occur.end()), occur.end());
	sg = occur.size();
	for (int i = 0; i < occur.size(); ++ i) {
		if (occur[i] != i) {
			return sg = i;
		}
	}
	
	
	
	return sg;
}

inline void solve()
{
	++ stamp;
	scanf("%d%d", &n, &m);
	
	assert(1 <= n && n <= 20);
	assert(1 <= m && m <= 20);
	
	char map[maxn][maxn + 1];
	for (int i = 0; i < n; ++ i) {
		scanf("%s", map[i]);
		
		assert(strlen(map[i]) == m);
		
		for (int j = 0; j < m; ++ j) {
			assert(map[i][j] == '#' || map[i][j] == '^');
		}
	}
	
	//check whether a grid is able to click
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			bool &valid = canClick[i][j];
			valid = true;
			for (int k = 0; k < 4; ++ k) {
				for (int len = 0; len <= 2; ++ len) {
					int x = i + dx[k] * len, y = j + dy[k] * len;
					if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] != '^') {
						valid = false;
						break;
					}
				}
			}
		}
	}
	
	if (getSG(0, n - 1, 0, m - 1)) {
		puts("Asuna");
	} else {
		puts("Kirito");
	}
}

int main()
{
	stamp = 0;
	memset(mark, -1, sizeof(mark));
	int T;
	for (scanf("%d", &T), assert(1 <= T && T <= 10);T --;) {
		solve();
	}
	return 0;
}

