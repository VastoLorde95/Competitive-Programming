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

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<ll,ll> pii;

const int LOGN = 18;
const int N = 1 << LOGN;
const ll INF = 1ll << 50;

struct node{
	vector<pii> x;
	ll w, id, upd;
	int ptr;
	void assign(vector<pii> &p){
		x = p;
		if(!p.empty()){
			w = p[0].fi;
			id = p[0].se;
			ptr = 0;
			upd = 0;
		}
		else{
			w = INF, id = INF, upd = INF;
			ptr = 0;
		}
	}
	
	void update(ll x){
		w += x;
		upd += x;
		if(w > INF) w = INF;
		if(upd > INF) upd = INF;
	}
	
	void combine(node &left, node &right){
		if(left.w < right.w){
			w = left.w;
			id = left.id;
		}
		else if(left.w == right.w){
			w = left.w;
			id = min(left.id, right.id);
		}
		else{
			w = right.w;
			id = right.id;
		}
	}
};

ll lazy[N];
node tree[2*N];

int n, m, q;

vector<int> g[N];
int c[N];

vector<pii> gg[N];

int indx;
vector<pii> baseArray[N];
int  chainHead[N], pos[N], chain[N], sz[N], chain_no;
int p[LOGN][N], lvl[N];

int r[N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(baseArray[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(int id,int l,int r,ll x){ //	update the current node and its index in the lazy array
	lazy[id] += x;
	tree[id].update(x);
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(lazy[id]){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0; // passing is done, reset the index in the lazy array
	}
}

// range update -> update(x, y, val);
void updateTree(int x, int y, ll val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	updateTree(x, y, val, left, l, mid); 
	updateTree(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
pair<ll, ll> queryTree(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return mp(INF, INF);
	if(x <= l && r <= y) return mp(tree[id].w, tree[id].id);
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	pair<ll, ll> p1 = queryTree(x, y, left, l, mid), p2 = queryTree(x, y, right, mid, r);
	
	return min(p1, p2);
}

void pointUpdateTree(int x, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].ptr++;
		if(tree[id].ptr == tree[id].x.size()){
			tree[id].w = INF;
			tree[id].id = INF;
			tree[id].upd = x;
		}
		else{
			int ptr = tree[id].ptr;
			tree[id].w = tree[id].x[ptr].fi + tree[id].upd;
			tree[id].id = tree[id].x[ptr].se;
		}
		return;
	}
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	if(x < mid)
		pointUpdateTree(x, left, l, mid);
	else
		pointUpdateTree(x, right, mid, r);
		
	tree[id].combine(tree[left], tree[right]);
}

int LCA(int u, int v){
	if(lvl[u] < lvl[v])
		swap(u, v);
		
	int diff = lvl[u] - lvl[v];
	
	for(int i = 0; i < LOGN; i++)
		if((diff>>i) & 1)
			u = p[i][u];
			
	if(u != v){
		for(int i = LOGN-1; i >= 0; i--){
			if(p[i][u] != p[i][v])
			{
				u = p[i][u];
				v = p[i][v];
			}
		}
		u = p[0][u];
	}
	return u;
}

void dfs(int cur, int prev){
	sz[cur] = 1;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		lvl[*it] = lvl[cur] + 1;
		p[0][*it] = cur;
		
		dfs(*it, cur);
		sz[cur] += sz[*it];
	}
}

void heavyLightDecomposition(int cur, int prev){
	chain[cur] = chain_no, pos[cur] = ++indx, baseArray[indx] = gg[cur]; // careful
	
	int heavy_child = -1, heavy_size = 0;
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

		chainHead[++chain_no] = *it;
		heavyLightDecomposition(*it, cur);
	}
	
	r[cur] = indx;
}

void preprocess(){
	for(int i = 1; i < LOGN; i++)
		for(int j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
}

pii query_up(int u, int v){		//This assumes that v is the ancestor of u
	int uchain, vchain = chain[v];
	pair<ll, ll> ans = mp(INF,INF);
	
	while(1){
		uchain = chain[u];
		
		if(uchain == vchain){		//We are in the same chain and hence we can directly perform the query from u to v
			ans = min(ans, queryTree(pos[v], pos[u] + 1));
			break;	
		}
		ans = min(ans, queryTree(pos[chainHead[uchain]], pos[u] + 1));
		
		u = p[0][chainHead[uchain]];	//Go to the next chain
	}
	
	return ans;	 
}

pii query(int x, int y){
	int z = LCA(x,y);
	pii p1 = query_up(x,z);
	pii p2 = query_up(y,z);
	return min(p1,p2);
}

void update(int x, int val){
	updateTree(pos[x], r[x]+1, val);
}

void solve(){
	sd3(n,m,q);

	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}

	for(int i = 1; i <= m; i++){
		sd(c[i]);
		gg[c[i]].pb(mp(i,i));
	}
	
	for(int i = 1; i <= n; i++){
		sort(gg[i].begin(), gg[i].end());
	}
	
	lvl[1] = 0, p[0][1] = 1;
	
	dfs(1,-1);
	
	chain_no = 1, indx = -1, chainHead[1] = 1;
	heavyLightDecomposition(1,-1);
	
	preprocess();
	
	build();
	
	for(int i = 0; i < q; i++){
		int t; sd(t);
		if(t == 1){
			int u, v, k;
			sd3(u,v,k);
			vector<int> res;
			while(k--){
				pii x = query(u,v);
				if(x.se >= INF) break;
				res.pb(x.se);
				int city = c[x.se];
				pointUpdateTree(pos[city]);
			}
			
			printf("%d ", (int) res.size());
			foreach(it, res){
				printf("%d ", *it);
			}
			puts("");
		}
		else{
			int v, k; sd2(v,k);
			update(v,k);
		}
	}
}

int main(){
	solve();
	return 0;
}
