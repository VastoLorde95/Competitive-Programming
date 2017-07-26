#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

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
typedef pair<int,int> pii;

const int LOGN = 18, N = 1 << LOGN;

struct node{
	ll cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt += value;
	}
	void combine(node &left, node &right){
		cnt = left.cnt + right.cnt;
	}
};

int n, q;
int lazy[N];
node tree[2*N];

vector<int> g[N];
int c[N];

int indx;
int baseArray[N];
int chainHead[N], pos[N], chain[N], sz[N], chain_no;
int p[LOGN][N], lvl[N];


void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(baseArray[l]);
		return;
	}
	int left = id << 1, right = left+1, mid = (l+r) >> 1;
	build(left, l, mid); build(right, mid, r);
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd(int id,int l,int r,int x){
	lazy[id] += x;
	tree[id].update((r - l) * x);
}

void shift(int id,int l,int r){
	if(lazy[id] and l+1 < r){
		int mid = (l+r) >> 1;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0;
	}
}

void pointUpdateTree(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r) return tree[id].assign(val);
	
	shift(id, l, r);
	
	int left = id << 1, right = left + 1, mid = (l+r) >> 1;
	
	if(index < mid) pointUpdateTree(index, val, left, l, mid);
	else pointUpdateTree(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

void rangeUpdateTree(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y) return upd(id, l, r, val);
	
	shift(id, l, r);
	
	int left = id << 1, right = left + 1, mid = (l+r) >> 1;
	
	rangeUpdateTree(x, y, val, left, l, mid); 
	rangeUpdateTree(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

ll rangeQueryTree(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].cnt;
	
	shift(id, l, r);
	
	int left = id << 1, right = left + 1, mid = (l+r) >> 1;
	
	return rangeQueryTree(x, y, left, l, mid) + rangeQueryTree(x, y, right, mid, r);
}

void dfs(int cur, int prev){
	sz[cur] = 1;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		lvl[*it] = lvl[cur] + 1, p[0][*it] = cur;
		dfs(*it, cur);
		sz[cur] += sz[*it];
	}
}

void HLD(int cur, int prev){
	chain[cur] = chain_no, pos[cur] = ++indx;
	baseArray[indx] = c[cur];	// careful
	
	int heavy_child = -1, heavy_size = 0;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		if(sz[*it] > heavy_size) heavy_size = sz[*it], heavy_child = *it;
	}
	
	if(heavy_child != -1) HLD(heavy_child, cur);

	foreach(it, g[cur]){
		if(*it == prev or *it == heavy_child) continue;
		chainHead[++chain_no] = *it;
		HLD(*it, cur);
	}	
}


int LCA(int u, int v){
	if(lvl[u] < lvl[v]) swap(u, v);
	int diff = lvl[u] - lvl[v];
	for(int i = 0; i < LOGN; i++) if((diff >> i) & 1) u = p[i][u];
	if(u != v){
		for(int i = LOGN-1; i >= 0; i--) if(p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
		u = p[0][u];
	}
	return u;
}

void preprocess(){
	lvl[1] = 0, p[0][1] = 1;
	dfs(1,-1);
	
	chain_no = 1, indx = 0, chainHead[1] = 1;
	HLD(1,-1);
	
	for(int i = 1; i < LOGN; i++) for(int j = 1; j <= n; j++) p[i][j] = p[i-1][p[i-1][j]];
}

ll queryChain(int u, int v){	//This assumes that v is the ancestor of u
	int uchain, vchain = chain[v];
	ll ans = 0;
	while(true){
		uchain = chain[u];
		if(uchain == vchain){ // We are in the same chain and hence we can directly perform the query from u to v
			ans += rangeQueryTree(pos[v], pos[u] + 1);
			break;	
		}
		ans += rangeQueryTree(pos[chainHead[uchain]], pos[u] + 1);
		u = p[0][chainHead[uchain]]; //Go to the next chain
	}
	return ans;	 
}

void updateChain(int u, int v, int val){	//This assumes that v is the ancestor of u
	int uchain, vchain = chain[v];
	while(true){
		uchain = chain[u];
		if(uchain == vchain){ // We are in the same chain and hence we can directly perform the query from u to v
			rangeUpdateTree(pos[v], pos[u] + 1, val);
			break;	
		}
		rangeUpdateTree(pos[chainHead[uchain]], pos[u] + 1, val);
		u = p[0][chainHead[uchain]]; //Go to the next chain
	}
}

void solve(){
	sd2(n,q);

	for(int i = 1; i <= n; i++){
		sd(c[i]);	// TODO : change this
		g[i].clear();
	}
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	preprocess();
	
	
	// query logic follows
	
}

int main(){
	solve();
	return 0;
}
