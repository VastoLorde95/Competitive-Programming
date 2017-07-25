#include <bits/stdc++.h>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 4e5 + 100;

int n, m, maxn = 1;
vector<pair<int, int> > rmqList[N];
int rmqMaxN[N];
vector<pair<int, int> > lst;
vector<int64> rmq[N];
vector<int> pos[N];

inline void make_rmq() {
    sort(all(lst));
    while (maxn < n) {
        maxn *= 2;
    }
    for (int i = 0; i < len(lst); i++) {
        rmqList[i + maxn] = { mp(lst[i].sc, i) };
        rmq[i + maxn] = { 0, 0 };
        rmqMaxN[i + maxn] = 1;
    }
    for (int i = maxn - 1; i > 0; i--) {
        rmqList[i].resize(len(rmqList[i * 2]) + len(rmqList[i * 2 + 1]));
        merge(all(rmqList[i * 2]), all(rmqList[i * 2 + 1]), rmqList[i].begin());
        rmqMaxN[i] = 1;
        while (rmqMaxN[i] < len(rmqList[i])) {
            rmqMaxN[i] *= 2;
        }
        rmq[i].assign(rmqMaxN[i] * 2, 0);
    }
    for (int i = maxn * 2 - 1; i > 0; i--) {
        for (int j = 0; j < len(rmqList[i]); j++) {
            pos[rmqList[i][j].sc].pb(j);
        }
    }
}

inline int64 getValue(pair<int, int> pt) {
    int index = lower_bound(all(lst), pt) - lst.begin();
    assert(index < len(lst) && lst[index] == pt);
    int i = index + maxn;
    int64 ans = 0;
    pt = mp(pt.sc, index);
    int len = 0;
    while (i > 0) {
        int index2 = pos[index][len++];
        assert(index2 < len(rmqList[i]) && rmqList[i][index2] == pt);
        int j = index2 + rmqMaxN[i];
        while (j > 0) {
            ans ^= rmq[i][j];
            j >>= 1;
        }
        i >>= 1;
    }
    return ans;
}

inline void updateLocal(int i, int b, int t, int64 val) {
    b = lower_bound(all(rmqList[i]), mp(b, -inf)) - rmqList[i].begin(), t = upper_bound(all(rmqList[i]), mp(t, inf)) - rmqList[i].begin() - 1;
    if (b > t) {
        return ;
    }
    b += rmqMaxN[i], t += rmqMaxN[i];
    while (b <= t) {
        if (b & 1) {
            rmq[i][b] ^= val;
        }
        if (!(t & 1)) {
            rmq[i][t] ^= val;
        }
        b = (b + 1) / 2;
        t = (t - 1) / 2;
    }
}

inline void update(int l, int r, int b, int t, int64 val) {
    l = lower_bound(all(lst), mp(l, -inf)) - lst.begin(), r = upper_bound(all(lst), mp(r, inf)) - lst.begin() - 1;
    if (l > r) {
        return ;
    }
    l += maxn, r += maxn;
    while (l <= r) {
        if (l & 1) {
            updateLocal(l, b, t, val);
        }
        if (!(r & 1)) {
            updateLocal(r, b, t, val);
        }
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
}

pair<int, int> a[N];
int64 rnd[N];
tuple<int, int, int, int> fence[N];

inline int64 myrand2() {
    return (1ll * rand() * RAND_MAX) + rand();
}

inline int64 myrand() {
    return (myrand2() * RAND_MAX * RAND_MAX) + myrand2();
}

inline void timestamp(string s) {
    static double last = 0.0;
    double cur = 1. * clock() / CLOCKS_PER_SEC;
    eprintf("%s: time: %.3lf; previous: %.3lf\n", s.data(), cur, cur - last);
    last = cur;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].fs, &a[i].sc);
    }

    lst = vector<pair<int, int>>(a, a + n);
    make_rmq();

    for (int i = 0; i < m; i++) {
        rnd[i] = myrand();
        static char buf[N];
        scanf("%s", buf);
        if (strcmp(buf, "add") == 0) {
            int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            update(x1, x2, y1, y2, rnd[i]);
            fence[i] = make_tuple(x1, y1, x2, y2);
        } else if (strcmp(buf, "delete") == 0) {
            int x; scanf("%d", &x), x--;
            int x1, y1, x2, y2; tie(x1, y1, x2, y2) = fence[x];
            update(x1, x2, y1, y2, rnd[x]);
        } else if (strcmp(buf, "query") == 0) {
            int a, b; scanf("%d%d", &a, &b), a--, b--;
            puts(getValue(::a[a]) == getValue(::a[b]) ? "YES" : "NO");
        } else {
            assert(false);
        }
    }
    timestamp("make requests");
    return 0;
}
