#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

const int N = 1e5 + 5;

int n, d, k;
ii a[N];
int ans[N];

vector < int > up[N];

class tree{ public:
    vector < int > vs, fen;
    void add(int x) {
        vs.push_back(x);
    }
    void init() {
        sort(vs.begin(), vs.end());
        vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
        fen.resize(vs.size() + 1, n + 1);
    }
    int id(int x) {
        return upper_bound(vs.begin(), vs.end(), x) - vs.begin();
    }
    int get(int x) {
        int res = n + 1;
        for(x = id(x); x; x -= x & -x)
            res = min(res, fen[x]);
        return res;
    }
    void upd(int x, int v) {
        for(x = id(x); x < fen.size(); x += x & -x)
            fen[x] = min(fen[x], v);
    }
};

tree data[N << 1];

void addT(int i) {
    int x = a[i].first + N;
    while(x >= 1) {
        data[x].add(a[i].second);
        x >>= 1;
    }
}

void updT(int i) {
    int x = a[i].first + N;
    while(x >= 1) {
        data[x].upd(a[i].second, i);
        x >>= 1;
    }
}

int getT(int x, int y) {
    int res = n + 1;
    for(int l = x + N, r = y + N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if(l & 1) res = min(res, data[l].get(y));
        if(~r & 1) res = min(res, data[r].get(y));
    }
    int tmp = res;
    if(res == n+1) res = 1e9;
    cout << x << ' ' << y << ' ' << res << endl;
    res = tmp;
    return res;
}

int go(int l, int r) {
    int i = getT(l, r);
    if(i > n)
        return 0;
    return a[i].second - a[i].first + 1 + go(l, a[i].first - 1) + go(a[i].second + 1, r);
}

int main () {
    
    scanf("%d %d %d", &n, &d, &k);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
        up[a[i].second - a[i].first + 1].push_back(i);
    }
    
    for(int i = 1; i <= n; i++)
        addT(i);
    
    for(int i = 1; i < N + N; i++)
        data[i].init();
    
    for(int len = d; len >= 1; len--) {
        if(up[len].empty()) {
            ans[len] = ans[len + 1];
            continue;
        }
        for(auto i : up[len]) {
            updT(i);
        }
        if(len == 1)
        ans[len] = go(1, d);
    }
    
    for(int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    
    return 0;
    
}
