#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n, m, L, s, t;

const int maxn = 100100;
const ll big = 1e13;

vector<pair<int, int>> edges;
vector<pair<int, int>> g[maxn];
ll W[maxn];
ll dist[maxn];
int from[maxn];
int fromV[maxn];

typedef pair<ll, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> o;
void dickstra(int u) {
    forn (i, n)
        dist[i] = infl;
    dist[u] = 0;
    o.emplace(dist[u], u);
    while (!o.empty()) {
        u = o.top().second;
        ll cc = o.top().first;
        o.pop();
        if (cc != dist[u])
            continue;
        int uu = u % n;
        for (auto p: g[uu]) {
            int id = p.second;
            int v = p.first;
            ll ndist = dist[u] + W[id];
            if (dist[v] <= ndist)
                continue;
            dist[v] = ndist;
            o.emplace(dist[v], v);
            from[v] = id;
            fromV[v] = u;
        }
    }
}

void fail() {
    cout << "NO\n";
    exit(0);
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> n >> m >> L >> s >> t;
    set<int> bads;
    forn (i, m) {
        int u, v, w; 
        cin >> u >> v >> w;
        edges.emplace_back(u, v);
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
        W[i] = w;
        if (w == 0) {
            W[i] = big;
            bads.insert(i);
        }
    }
    dickstra(s);
    if (dist[t] < L)
        fail();
    for (int i: bads)
        W[i] = 1;
    dickstra(s);
    if (dist[t] > L)
        fail();

    while (dist[t] < L) {
        int u = t;
        ll rem = L - dist[t];
        set<int> nbads;
        while (u != s) {
            int id = from[u];
            if (bads.count(id))
                nbads.insert(id);
            u = fromV[u];
        }
        for (int i: bads)
            if (!nbads.count(i))
                W[i] = big;
        bads = nbads;
        int cnt = sz(nbads);
        u = t;
        while (u != s) {
            int id = from[u];
            if (nbads.count(id)) {
                ll delta = rem / cnt;
                W[id] += delta;
                --cnt;
                rem -= delta;
            }
            u = fromV[u];
        }
        dickstra(s);
        assert(dist[t] <= L);
    }
    cout << "YES\n";
    forn (i, m)
        cout << edges[i].first << ' ' << edges[i].second << ' ' << W[i] << '\n';
}
