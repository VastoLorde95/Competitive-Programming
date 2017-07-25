#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const ld eps = 1e-9;

bool eq(ld a, ld b) { return fabsl(a - b) < eps; }
bool ge(ld a, ld b) { return a - b > -eps; }
bool le(ld a, ld b) { return b - a > -eps; }
bool gt(ld a, ld b) { return a - b > eps; }
bool lt(ld a, ld b) { return b - a > eps; }
ld sqr(ld x) { return x * x; }

#ifdef LOCAL
#define gassert assert
#else
void gassert(bool) {}
#endif

struct pt {
    ld x, y;

    pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
    ld operator*(const pt &p) const { return x * p.x + y * p.y; }
    ld operator%(const pt &p) const { return x * p.y - y * p.x; }

    pt operator*(const ld &a) const { return pt{x * a, y * a}; }
    pt operator/(const ld &a) const { gassert(!eq(a, 0)); return pt{x / a, y / a}; }
    void operator*=(const ld &a) { x *= a, y *= a; }
    void operator/=(const ld &a) { gassert(!eq(a, 0)); x /= a, y /= a; }

    bool operator<(const pt &p) const {
        if (eq(x, p.x)) return gt(p.y, y);
        return x < p.x;
    }

    bool operator==(const pt &p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator!=(const pt &p) const { return !(*this == p); }

    bool right() const { return pt{0, 0} < *this; }

    pt rot() { return pt{-y, x}; }
    ld abs() const { return hypot(x, y); }
    ld abs2() const { return x * x + y * y; }
};

istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

const int maxn = 100100;
const int maxc = 10000;
int n, m;
pt p[maxn];
ld c[maxn];

pt A[maxn];
pt B[maxn];
ld r[maxn];

const ld C1 = 6. / 11;
const ld C2 = 5. / 11;

ld func(ld x, ld y) {
    pt P{x, y};
    ld res = -infl;
    forn (i, n) {
        ld cur = P * p[i] - c[i];
        
        cout << i << ' ' <<  p[i] << ' ' << c[i] << ' ' << P << endl;
        
        res = max(res, cur);
    }
    forn (i, m) {
        ld cur = (P - A[i]).abs() + (P - B[i]).abs() - r[i];
        res = max(res, cur);
    }
    return res;
}

ld resx, resy;

ld solve(ld x) {
    ld yl = -maxc, yr = maxc;
    forn (iter, 60) {
        ld y1 = yl * C1 + yr * C2;
        ld y2 = yr * C1 + yl * C2;
        ld v1 = func(x, y1);
        ld v2 = func(x, y2);
        if (v1 <= v2)
            yr = y2;
        else
            yl = y1;
    }
    resy = (yl + yr) / 2;
    return func(x, resy);
}

ld solve() {
    ld xl = -maxc, xr = maxc;
    forn (iter, 60) {
        ld x1 = xl * C1 + xr * C2;
        ld x2 = xr * C1 + xl * C2;
        ld v1 = solve(x1);
        ld v2 = solve(x2);
        if (v1 <= v2)
            xr = x2;
        else
            xl = x1;
    }
    resx = (xl + xr) / 2;
    return solve(resx);
}

int main() {
    #ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    #endif
    cout.precision(6);
    cout << fixed;
    int pn;
    cin >> pn;
    forn (iter, pn) {
        int k;
        cin >> k;
        vector<pt> poly(k + 1);
        forn (i, k)
            cin >> poly[i];
        poly[k] = poly[0];
        forn (i, k) {
            pt v = (poly[i] - poly[i + 1]).rot();
            
            v /= v.abs();
            ld C = poly[i] * v;
            
            cout << poly[i] << ' ' << poly[i+1] <<  ' ' << v << endl;
            
            p[n] = v;
            c[n++] = C;
        }
    }
    cin >> m;
    forn (i, m) {
        cin >> A[i] >> B[i] >> r[i];
        r[i] *= 2;
    }
    
    cout << "this " << func(0,0) << endl;
    
//    ld val = solve();
//    assert(val <= 0.001);
//    cerr << "val: " << val << '\n';
//    cout << resx << '\n' << resy << '\n';
}
