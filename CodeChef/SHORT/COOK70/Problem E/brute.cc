#include <bits/stdc++.h>
using namespace std;
 
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
 
vi a[14];
int g[14][10];
int h[14];
map<pair<int, vii>, int> f;
 
int calc(int c, vii v) {
	if (c == 0) {
		FOR(i, 0, sz(v)) {
			if (v[i].fi && v[i].se) {
				return -INF / 10;
			}
		}
		return 0;
	}
	if (f.count(mp(c, v))) return f[mp(c, v)];
	int& res = f[mp(c, v)];
	res = -INF / 10;
	if (c >= 10) chkmax(res, calc(10, v));
	FOR(r, 0, 10) {
		vii nv;
		int found = 0;
		FOR(i, 0, sz(v)) if (!found) {
			int a = v[i].fi;
			int b = v[i].se;
			int s = (r - a + 10) % 10;
			int t = b % 10;
			int ok = 0;
			FOR(j, 0, 14) if (h[j] % 10 == s && c - a >= h[j]) {
				if (!~g[j][t] || g[j][t] > b) {
					found = 1;
					break;
				}
				else {
					nv.pb(mp((a + h[j] - r) / 10, (b - g[j][t]) / 10));
					ok = 1;
				}
			}
			if (!ok) {
				found = 1;
				break;
			}
		}
		if (!found) {
			chkmax(res, 10 * calc((c - r) / 10, nv) + r);
		}
	}
	return res;
}
 
void init() {
	a[1].pb(1);
	a[2].pb(5); a[2].pb(2); a[2].pb(2); a[2].pb(2);
	a[3].pb(2);
	a[4].pb(1); a[4].pb(2);
	a[5].pb(5); a[5].pb(2); a[5].pb(2); a[5].pb(2); a[5].pb(2);
	a[6].pb(2); a[6].pb(2);
	a[7].pb(5);
	a[8].pb(2); a[8].pb(2); a[8].pb(2);
	a[9].pb(1); a[9].pb(5);
	a[10].pb(5); a[10].pb(2);
	a[11].pb(2); a[11].pb(2); a[11].pb(2); a[11].pb(2);
	a[12].pb(1); a[12].pb(5); a[12].pb(2);
	a[13].pb(5); a[13].pb(2); a[13].pb(2);
	ms(g, -1);
	FOR(i, 0, 14) {
		int x = 0;
		FOR(j, 0, sz(a[i])) {
			x += a[i][j];
		}
		h[i] = x;
		FOR(msk, 0, 1 << sz(a[i])) {
			int y = 0;
			FOR(j, 0, sz(a[i])) if (bit(msk, j)) {
				y += a[i][j];
			}
			g[i][y % 10] = y;
		}
	}
}
 
void solve() {
	init();
	int test; cin >> test;
	while (test--) {
		int c, l; cin >> c >> l;
		vector<pair<int, int> > v; v.pb(mp(0, l));
		cout << calc(c, v) << "\n";
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
