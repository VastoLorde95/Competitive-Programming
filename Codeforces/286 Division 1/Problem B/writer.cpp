
    // Enjoy your stay.
     
    #include <bits/stdc++.h>
     
    #define EPS 1e-9
    #define INF 1070000000LL
    #define MOD 1000000007LL
    #define fir first
    #define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
    #define ite iterator
    #define mp make_pair
    #define mt make_tuple
    #define rep(i,n) rep2(i,0,n)
    #define rep2(i,m,n) for(int i=m;i<(n);i++)
    #define pb push_back
    #define sec second
    #define sz(x) ((int)(x).size())
     
    using namespace std;
     
    typedef istringstream iss;
    typedef long long ll;
    typedef pair<ll,ll> pi;
    typedef stringstream sst;
    typedef vector<ll> vi;
     
    const int N = 100010;
     
    int n, m;
    vi g[N];
    vi rg[N];
    vi vs;
    bool used[N];
    int cmp[N], cmpsize[N];
     
    void add_edge(int from, int to){
    g[from].pb(to);
    rg[to].pb(from);
    }
     
    void dfs(int v){
    used[v] = 1;
    rep(i, sz(g[v])){
    if(!used[g[v][i]]) dfs(g[v][i]);
    }
    vs.pb(v);
    }
     
    void rdfs(int v, int k){
    used[v] = 1;
    cmp[v] = k;
    rep(i, sz(rg[v])){
    if(!used[rg[v][i]]) rdfs(rg[v][i], k);
    }
    }
     
    int scc(){
    memset(used, 0, sizeof(used));
    vs.clear();
    rep(v, n){
    if(!used[v])
    dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = sz(vs) - 1; i >= 0; i--){
    if(!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
    }
     
    int dfs2(int v){
    used[v] = 1;
    int res = cmpsize[cmp[v]] == 1;
    rep(i,sz(g[v])) if(!used[g[v][i]]){
    res &= dfs2(g[v][i]);
    }
    rep(i,sz(rg[v])) if(!used[rg[v][i]]){
    res &= dfs2(rg[v][i]);
    }
    return res;
    }
     
    int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
     
    cin >> n >> m;
    rep(i, m){
    int a, b;
    cin >> a >> b;
    add_edge(a-1, b-1);
    }
    scc();
    memset(cmpsize, 0, sizeof(cmpsize));
    rep(i, n){
    cmpsize[cmp[i]]++;
    }
    memset(used, 0, sizeof(used));
    int ans = n;
    rep(i, n) if(!used[i]){
    ans -= dfs2(i);
    }
    cout << ans << endl;
    }
