#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;
const int M = 105;
int n, m, q, x[N], y[N], a[M], b[M], c[M];
ll f[N][1<<N], g[N][1<<N];

bool in(int v, int st) {return st&(1<<v);}
ll calc(int, int);
ll calcG(int v, int st) {
	for (int i = 0; i < m; i++)
		if (in(x[i], st) != in(y[i], st))
			if ((x[i] != v)&&(y[i] != v)) return 0;
	for (int i = 0; i < q; i++)
		if (!in(c[i], st)) {
			if (in(a[i], st)&&in(b[i], st)) return 0;
		} else if (((!in(a[i], st))||(!in(b[i], st)))&&(c[i] != v)) return 0;
	ll &ans = g[v][st];
	if (ans > 0) return ans;
	return ans = calc(v, st);
}
ll calcF(int v, int st, int p) {
	for (int i = 0; i < m; i++)
		if (in(x[i], st) != in(y[i], st))
			if (((x[i] != v)&&(x[i] != p))||((y[i] != p)&&(y[i] != v))) return 0;
	for (int i = 0; i < q; i++)
		if (!in(c[i], st)) {
			if (in(a[i], st)&&in(b[i], st)) return 0;
		} else if ((!in(a[i], st))||(!in(b[i], st))) return 0;
	ll &ans = f[v][st];
	if (ans > 0) return ans;
	return ans = calc(v, st);
}
ll calc(int v, int st) {
	int stt = st^(1<<v);
	if (stt == 0) return 1;
	ll ans = 0;
	for (int i = stt; i > 0; i = (i-1)&stt) {
		if ((i&stt&(-stt)) == 0) continue;
		for (int u = 0; u < n; u++)
			if (in(u, i)) ans += calcF(u, i, v)*calcG(v, st^i);
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", x+i, y+i);
		x[i]--; y[i]--;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", a+i, b+i, c+i);
		a[i]--; b[i]--; c[i]--;
	}
	cout <<  calcF(0, (1<<n)-1, -1) << endl;
	return 0;
}
