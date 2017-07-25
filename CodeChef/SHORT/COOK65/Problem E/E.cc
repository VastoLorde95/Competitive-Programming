#include <bits/stdc++.h>

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const ll LOGN = 19;
const ll N = 1 << LOGN;
const ll INF = 1ll << 40;

ll n, q, A, B, P;

vector<ll> g[N];
ll c[N];

ll indx;
ll baseArray[N], chainHead[N], pos[N], chain[N], sz[N], chain_no;
ll p[LOGN][N], lvl[N];

int vis[N];

struct node{
	ll cnt, maxval, lazy;
	
	node(){
		cnt = maxval = lazy = 0;
	}
	
	void assign(ll value){
		lazy = 0;
		maxval = value;
		cnt = (maxval < P)? 1 : 0;
	}
	
	void update(ll value){
		maxval += value, lazy += value;
	}
	
	void combine(node &left, node &right){
		maxval = max(left.maxval, right.maxval) + lazy;
		cnt = left.cnt + right.cnt;
	}
	
} tree[2*N];

void build(ll id = 1, ll l = 0, ll r = n){
	if(l+1 == r){
		tree[id].assign(baseArray[l]);
		return;
	}
	
	ll left = id << 1, right = left + 1, mid = (l + r) >> 1;

	tree[id].lazy = 0;	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void updateSegTree(ll x, ll y, ll val, ll id = 1, ll l = 0, ll r = n){
	if(x >= r or l >= y or x >= y) return;
	if(x <= l and r <= y){
		tree[id].update(val);
		return;
	}
	
	ll left = id << 1, right = left+1, mid = (l+r) >> 1;
	
	updateSegTree(x, y, val, left, l, mid); 
	updateSegTree(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

void propagateSegTree(ll id, ll x, ll y, ll lazy){
	if(tree[id].maxval + lazy < P or !tree[id].cnt){
		tree[id].update(lazy);
		return;
	}
	
	if(x+1 == y){
		if(tree[id].maxval + lazy >= P) tree[id].maxval = -INF, tree[id].cnt = 0;
		return;
	}
	
	lazy += tree[id].lazy;
	tree[id].lazy = 0;
	
	ll left = id << 1, right = left + 1, mid = (x+y) >> 1;

	propagateSegTree(left, x, mid, lazy);
	propagateSegTree(right, mid, y, lazy);
	
	tree[id].combine(tree[left], tree[right]);
}

ll querySegTree(ll x, ll y, ll id = 1, ll l = 0, ll r = n, ll lazy = 0){
	tree[id].update(lazy);
	if(x >= r or l >= y or x >= y) return 0;
	
	if(x <= l and r <= y){
		propagateSegTree(id, l, r, 0);
		return r - l - tree[id].cnt;
	}
	
	ll left = id << 1, right = left+1, mid = (l+r) >> 1;
	
	lazy = tree[id].lazy;
	tree[id].lazy = 0;
	
	int ret = querySegTree(x, y, left, l, mid, lazy) + querySegTree(x, y, right, mid, r, lazy);
	tree[id].combine(tree[left], tree[right]);
	return ret;
}

void dfs(ll cur, ll prev){
	vis[cur] = 1;
	sz[cur] = 1;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		if(vis[*it]) continue;
		
		lvl[*it] = lvl[cur] + 1;
		p[0][*it] = cur;
		
		dfs(*it, cur);
		sz[cur] += sz[*it];
	}
}

void heavyLightDecomposition(ll cur, ll prev){
	chain[cur] = chain_no, pos[cur] = ++indx;
	baseArray[indx] = c[cur];
	
	ll heavy_child = -1, heavy_size = 0;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		if(sz[*it] > heavy_size){
			heavy_size = sz[*it];
			heavy_child = *it;
		}
	}
	
	if(heavy_child != -1) heavyLightDecomposition(heavy_child, cur);

	foreach(it, g[cur]){
		if(*it == prev or *it == heavy_child) continue;

		chain_no++;
		chainHead[chain_no] = *it;
		heavyLightDecomposition(*it, cur);
	}	
}

void preprocess(){
	for(ll i = 1; i < LOGN; i++)
		for(ll j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
}

ll LCA(ll x, ll y){
	if(lvl[x] < lvl[y]) swap(x,y);
	
	ll tmp = 1; while((1 << tmp) <= lvl[x]) tmp++; tmp--;
	
	for(ll i = tmp; i >= 0; i--) if(lvl[x] - (1<<i) >= lvl[y]) x = p[i][x];
	if(x == y) return y;
	
	for(ll i = tmp; i >= 0; i--) if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];
	return p[0][x];
}

void chainUpdate(ll x, ll y, ll w, ll flag){
	while(true){
		if(chain[x] == chain[y]){
			updateSegTree(pos[y]+flag, pos[x]+1, w);
			return;
		}
		
		ll head = chainHead[chain[x]];
		updateSegTree(pos[head], pos[x]+1, w);
		x = p[0][head];
	}
}

ll chainQuery(ll x, ll y, ll flag){
	ll total = 0;
	while(true){
		if(chain[x] == chain[y]){
			total += querySegTree(pos[y]+flag, pos[x]+1);
			return total;
		}
		
		ll head = chainHead[chain[x]];
		total += querySegTree(pos[head], pos[x]+1);
		x = p[0][head];
	}
}

void update(ll u, ll v, ll w){
	ll lca = LCA(u,v);
	assert(lca > 0 and lca <= n);
	chainUpdate(u, lca, w, 0);
	chainUpdate(v, lca, w, 1);
}

ll query(ll u, ll v){
	ll lca = LCA(u,v);
	assert(lca > 0 and lca <= n);
	return chainQuery(u, lca, 0) + chainQuery(v, lca, 1);
}

void solve(){
	sd2(n,q); sd2(A,B);
	
	if(A == 0)
		P = (B >= 0)? -INF: INF;
	else
		P = (B < 0)? ceil((-1.0*B)/A): (-B)/A;
	
	for(ll i = 1; i <= n; i++) sd(c[i]);
	for(int i = 0; i <= 3*n; i++){
		tree[i] = *(new node);
	}
	
	for(int i = 0; i <= n; i++){
		g[i].clear();
		sz[i] = 0;
		lvl[i] = 0;
		vis[i] = 0;
		for(int j = 0; j < LOGN; j++) p[j][i] = 0;
	}
	
	for(ll i = 1; i < n; i++){
		ll u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	lvl[1] = 0;
	for(int j = 0; j < LOGN; j++){
		p[j][1] = 1;	
	}
	
	dfs(1,-1);
	
	chain_no = 1, indx = -1, chainHead[1] = 1;
	heavyLightDecomposition(1,-1);
	
	preprocess();
	build();
	
	ll type, u, v, w;
	while(q--){
		sd3(type,u,v);
		if(type == 1){
			sd(w);
			update(u,v,w);
		}
		else{
			int res = query(u,v);
			assert(res >= 0 and res <= n);
			printf("%lld\n", res);
		}
	}
}

int main(){
	ll t; sd(t);
	while(t--) solve();
	return 0;
}
