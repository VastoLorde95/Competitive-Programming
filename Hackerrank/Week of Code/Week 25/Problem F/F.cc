#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

#define tm suka

const int maxc = 1e9;

//const int maxn = 1001;
const int maxn = 100100;
vector<int> g[maxn];

int tm[maxn];

int qt[maxn];
int qu[maxn];
int qx[maxn];
int qans[maxn];

//const int sn = 1;
const int sn = 600;
const int sn2 = 1000;
const int block = maxn / 3 + 2;
bitset<block> bs[maxn];
bool used[maxn];
int L, R;
int n;

vector<int> ord;

void pre(int u) {
    used[u] = true;
    for (int v: g[u])
        if (!used[v])
            pre(v);
    ord.push_back(u);
}

void uin(int &a, int b) {
    a = min(a, b);
}

void uax(int &a, int b) {
    a = max(a, b);
}

int a[maxn / sn + 2][maxn];

int upd[maxn];
vector<pii> o;
void put1(int u, int x) {
    o.emplace_back(u, x);
    if (sz(o) < sn2)
        return;
    forn (i, n)
        upd[i] = -1;
    for (auto p: o)
        uax(upd[p.first], p.second);
    o.clear();
    for (int ii = n - 1; ii >= 0; --ii) {
        int u = ord[ii];
        tm[u] = max(tm[u], upd[u]);
        for (int v: g[u])
            uax(upd[v], upd[u]);
    }
}

int get1(int u) {
    int res = tm[u];
    for (auto op: o)
        if (bs[op.first][u - L])
            uax(res, op.second);
    return res;
}

vector<int> q2;

void calc2(int l, int r) {
    int k = l / sn;
    forn (i, n)
        a[k][i] = maxc;
    for (int i = l; i < r; ++i) {
        int id = q2[i];
        uin(a[k][qu[id]], qx[id]);
    }
    for (int ii = n - 1; ii >= 0; --ii) {
        int u = ord[ii];
        for (int v: g[u])
            uin(a[k][v], a[k][u]);
    }
}

int get2(int u, int l, int r) {
    l = lower_bound(q2.begin(), q2.end(), l) - q2.begin();
    r = lower_bound(q2.begin(), q2.end(), r) - q2.begin();
    int res = maxc;
    int l2 = ((l + sn - 1) / sn) * sn;
    int r2 = (r / sn) * sn;
    if (l2 > r2) {
        for (int i = l; i < r; ++i) {
            int id = q2[i];
            int v = qu[id];
            if (bs[v][u - L])
                uin(res, qx[id]);
        }
    } else {
        for (int i = l; i < l2; ++i) {
            int id = q2[i];
            int v = qu[id];
            if (bs[v][u - L])
                uin(res, qx[id]);
        }
        for (int i = r2; i < r; ++i) {
            int id = q2[i];
            int v = qu[id];
            if (bs[v][u - L])
                uin(res, qx[id]);
        }
        l2 /= sn, r2 /= sn;
        for (int i = l2; i < r2; ++i)
            uin(res, a[i][u]);
    }
    return res;
}

int main() {
    int m, q;
    cin >> n >> m >> q;
    
    forn (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
    }
    forn (i, n)
        if (!used[i])
            pre(i);
    
    forn (i, q) {
        int t, u, x = -1;
        scanf("%d%d", &t, &u);
        --u;
        if (t != 3)
            scanf("%d", &x);
        qt[i] = t, qu[i] = u, qx[i] = x;
    }

    forn (i, q) {
        if (qt[i] != 2)
            continue;
        q2.push_back(i);
    }
    
    for (int i = 0; i + sn <= sz(q2); i += sn)
        calc2(i, i + sn);

    for (L = 0; L < n; L += block) {
        R = min(n, L + block);
        forn (i, n) {
            bs[i].reset();
            tm[i] = -1;
        }
        o.clear();

        forn (i, n) {
            int u = ord[i];
            if (L <= u && u < R)
                bs[u][u - L] = true;
            for (int v: g[u])
                bs[u] |= bs[v];
        }

        forn (id, q) {
            if (qt[id] == 3) {
                int u = qu[id];
                if (u < L || u >= R)
                    continue;
                int lb = get1(u);
                int val = lb >= 0 ? qx[lb] : 0;
                uin(val, get2(u, lb, id));
                qans[id] = val;
            }
            if (qt[id] == 1)
                put1(qu[id], id);
        }
    }
    forn (i, q) {
        if (qt[i] == 3)
            cout << qans[i] << '\n';
    }
}
