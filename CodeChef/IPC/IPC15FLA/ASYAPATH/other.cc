#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair<LL, int> PLI;
typedef pair<int, LL> PIL;
typedef pair<LL, LL> PLL;
typedef double DB;
 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))
#define sqr(x) ((x)*(x))
#define bit(x) (1<<(x))
#define bitl(x) (1LL<<(x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
 
template<typename T, typename U>
inline void chkmin(T &x, U y) {
	if (y < x) x = y;
}
 
template<typename T, typename U>
inline void chkmax(T &x, U y) {
	if (x < y) x = y;
}
 
const int MAXN = 222222;
const int MOD = 1e9+7;
 
int r[MAXN], f[MAXN], g[MAXN], x[111], y[111], ID[111], dp[111][111], con[111][111];
int n, m, D;
 
bool cmp(int u, int v) {
    if (x[u] != x[v]) return x[u] < x[v];
    if (y[u] != y[v]) return y[u] < y[v];
    return u < v;
}
 
int valid(int a, int b) {
    return x[a] <= x[b] && y[a] <= y[b];
}
 
int C(int n, int m) {
    if (m < 0 || m > n) return 0;
	int ret = 1LL*f[n]*g[m]%MOD*g[n-m]%MOD;
	return ret;
}
 
int main() {
	r[1] = f[0] = f[1] = g[0] = g[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		r[i] = (LL)(MOD - r[MOD % i]) * (MOD / i) % MOD;
		f[i] = (LL)f[i-1] * i % MOD;
		g[i] = (LL)g[i-1] * r[i] % MOD;
	}
	int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &n, &m, &D);
        for (int i = 1; i <= D; i++) {
			scanf("%d", &x[i]);
		}
        for (int i = 1; i <= D; i++) {
			scanf("%d", &y[i]);
		}
        for (int i = 0; i <= D+1; i++) ID[i] = i;
        x[0] = 1, y[0] = 1, x[D+1] = n, y[D+1] = m;
        for (int i = 1; i < D; i++) {
        	assert(x[ID[i]] != x[ID[i+1]] || y[ID[i]] != y[ID[i+1]]);
        }
        sort(ID, ID + D + 2, cmp);
        memset(con, 0, sizeof con);
        for (int i = 0; i < D+2; i++) {
        	int u = ID[i];
        	for (int j = i+1; j < D+2; j++) {
        		int v = ID[j];
        		if (valid(u, v)) {
                    con[u][v] = C(x[v]-x[u] + y[v]-y[u], x[v]-x[u]);
					for (int k = i+1; k < j; k++) {
						int w = ID[k];
						if (valid(u, w) && valid(w, v)) {
                            con[u][v] = (con[u][v] + (LL)(MOD - con[u][w]) * C(x[v]-x[w] + y[v]-y[w], x[v]-x[w])) % MOD;
						}
					}
                } else {
                	con[u][v] = 0;
                }
        	}
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i <= D; i++) {
        	for (int j = 0; j < D+2; j++) {
        		int u = ID[j];
    			for (int k = j+1; k < D+2; k++) {
    				int v = ID[k];
    				if (v > u) {
    					dp[i+1][v] = (dp[i+1][v] + (LL)dp[i][u] * con[u][v]) % MOD;
    				}
    			}
        	}
        }
        for (int i = 0; i <= D; i++) {
        	printf("%d%c", dp[i+1][D+1], i < D ? ' ' : '\n');
        }
    }
	return 0;
} 
