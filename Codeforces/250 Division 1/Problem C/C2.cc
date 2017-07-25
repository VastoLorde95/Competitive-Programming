#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;

typedef complex<long long> Point;

long long cross(const Point &a, const Point &b) {
	return imag(conj(a) * b);
}

long long ccw(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - a);
}

const int N = 200, MODULO = (int) 1e9 + 7;
int n, f[N][N];
Point p[N];

void enter() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		p[i] = Point(x, y);
	}
	long long area = 0;
	for(int i = n - 1, j = 0; j < n; i = j++)
		area += cross(p[i], p[j]);
	if(area < 0) reverse(p, p + n);
	
//	for(int i = 0; i < n; i++) cout << real(p[i]) << " " << imag(p[i]) << endl;
}

void solve() {
	for(int diff = 1; diff < n; ++diff)
		for(int i = 0, j = diff; j < n; ++i, ++j) {
			if(diff == 1) f[i][j] = 1;
			else {
				for(int k = i + 1; k < j; ++k) if(ccw(p[i], p[j], p[k]) < 0)
					f[i][j] = (f[i][j] + 1LL * f[i][k] * f[k][j]) % MODULO;
			}
		}
	cout << f[0][n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	enter();
	solve();
	return 0;
}
