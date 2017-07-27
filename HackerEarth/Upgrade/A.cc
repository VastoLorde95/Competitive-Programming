/*

HackerEarth problem Upgrade 
URL: https://www.hackerearth.com/challenge/competitive/july-clash-15/algorithm/upgrade/
Solution using Heavy Light Decomposition and Implicit Treap
*/

#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

namespace Treap{

struct node{
	int pri, size, val, sum, rev;
	node *l, *r;
	node(int x){
		pri = rand(), val = x, size = 1, sum = val, rev = 0;
		l = r = NULL;
	}
};

int getSize(node *cur){
	return cur ? cur->size : 0;
}

void propagate(node *cur){
	if(!cur or !cur->rev) return;
	
	cur->rev ^= 1;
	swap(cur->l, cur->r);
	
	if(cur->l) cur->l->rev ^= 1;
	if(cur->r) cur->r->rev ^= 1;
}

void updSize(node *cur){
	if(!cur) return;
	cur->size = getSize(cur->l) + 1 + getSize(cur->r);
	
	cur->sum = cur-> val;
	propagate(cur->l);
	propagate(cur->r);
	
	cur->sum += (cur->l) ? cur->l->sum : 0;
	cur->sum += (cur->r) ? cur->r->sum : 0;
}

//void updNode(node *cur){
//	if(!cur) return;
//	cur->sum = cur-> val;
//	propagate(cur->l);
//	propagate(cur->r);
//	
//	cur->sum += (cur->l) ? cur->l->sum : 0;
//	cur->sum += (cur->r) ? cur->r->sum : 0;
//}

typedef pair<node *, node *> LR;

LR split(node *root, int pos){
	if(!root) return LR(NULL, NULL);
	
	propagate(root);		// lazy propagation
	
	LR ret;
	
	int cur_size = getSize(root->l) + 1;
	if(cur_size <= pos){
		LR tmp = split(root->r, pos - cur_size);
		root->r = tmp.fi;
		ret = mp(root, tmp.se);
	}	
	else{
		LR tmp = split(root->l, pos);
		root->l = tmp.se;
		ret = mp(tmp.fi, root);
	}

	updSize(root);		// update the parameters of root since its children have possibly been modified	
//	updNode(root);
	return ret;
}

node *merge(node *l, node *r){
	if(!l or !r) return l ? l : r;
	
	if(l->pri > r->pri){
		propagate(l);		// lazy propagation
		l->r = merge(l->r, r);
		updSize(l);			// update the parameters of l since its children have possibly been modified	
//		updNode(l);	
		return l;
	}
	else{
		propagate(r);		// lazy propagation
		r->l = merge(l, r->l);
		updSize(r);		// update the parameters of r since its children have possibly been modified	
//		updNode(r);
		return r;
	}
}

int range_query(node * &treap, int x, int y){
	node *l, *mid, *r;

	LR tmp;

	tmp = split(treap, y);	
	mid = tmp.fi, r = tmp.se;
	
	tmp = split(mid, x-1);
	l = tmp.fi, mid = tmp.se;

	int ans = mid->sum;

	treap = merge(l, mid);
	treap = merge(treap, r);

	return ans;
}
}	// end of namespace

const int LOGN = 17;
const int N = 1 << LOGN;

vector<int> g[N];
int a[N];

int sz[N], p[LOGN][N], height[N];

int chain_num;
int chain_id[N], chain_parent[N];

int pos[N], tstmp;

int A[N];

int n, q;

int LCA(int x, int y){
	if(height[x] < height[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= height[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(height[x] - (1<<i) >= height[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}

void makeJumpTable(){
	for(int j = 1; j < LOGN; j++){
		for(int i = 1; i <= n; i++){
			p[j][i] = p[j-1][p[j-1][i]];
		}
	}
}

void heavylight(int x, int prev){
	chain_id[x] = chain_num;
	pos[x] = ++tstmp;
	
	int mx = 0, nxt = -1;
	for(int y : g[x]){
		if(y == prev) continue;
		if(sz[y] > mx) mx = sz[y], nxt = y;
	}
	
	if(nxt != -1) heavylight(nxt, x);
	
	for(int y : g[x]){
		if(y == prev or y == nxt) continue;
		chain_parent[++chain_num] = y;
		heavylight(y, x);
	}
}

void dfs(int x, int prev){
	sz[x] = 1, p[0][x] = prev;
	
	for(int y : g[x]){
		if(y == prev) continue;
		height[y] = height[x] + 1;
		dfs(y, x);
		sz[x] += sz[y];
	}
}

void read(){
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v); g[v].pb(u);
	}
}

void heavyLightDecomposition(){
	dfs(1, 1);
	
	chain_num = 1;
	chain_parent[chain_num] = 1;
	heavylight(1, 1);
	
	for(int i = 1; i <= n; i++) A[pos[i]] = a[i];
	makeJumpTable();
}

using namespace Treap;

node *treap;

void buildTreap(){
	treap = new node(A[1]);
	for(int i = 2; i <= n; i++){
		node *nn = new node(A[i]);
		treap = merge(treap, nn);
	}
}

vector<pii> go_up(int u, int v, bool flag){
	vector<pii> ret;
	while(true){
		if(chain_id[u] == chain_id[v]){
			if(!flag){
				if(u != v) ret.pb(mp(pos[v]+1, pos[u]));
			}
			else
				ret.pb(mp(pos[v], pos[u]));
			return ret;
		}
		
		int tv = chain_parent[chain_id[u]];
		ret.pb(mp(pos[tv], pos[u]));
		u = p[0][tv];
	}
}

ll query_up(int u, int v, bool flag){
	ll ans = 0;
	while(true){
		if(chain_id[u] == chain_id[v]){
			if(!flag){
				if(u != v) ans += range_query(treap, pos[v]+1, pos[u]);
			}
			else ans += range_query(treap, pos[v], pos[u]);
			return ans;
		}
		
		int tv = chain_parent[chain_id[u]];
		ans += range_query(treap, pos[tv], pos[u]);
		u = p[0][tv];
	}
}

void reverse(int u, int v, int lca){
	if(pos[u] > pos[v]) swap(u,v);
	vector<pii> r1 = go_up(u, lca, true);
	vector<pii> r2 = go_up(v, lca, false);

	reverse(r1.begin(), r1.end());
	reverse(r2.begin(), r2.end());

	vector<pii> r;
	r.insert(r.end(), r1.begin(), r1.end());
	r.insert(r.end(), r2.begin(), r2.end());
	
	int sz = r.size();
	
	vector<int> indices(sz, -1);
	
	vector<node *> treaps = {treap};
	for(int i = sz-1; i >= 0; i--){
		int x = r[i].fi, y = r[i].se;
		node *cur = treaps.back();
		LR tmp = split(cur, y);
		treaps.back() = tmp.se;
		
		cur = tmp.fi;
		tmp = split(cur, x-1);
		
		treaps.pb(tmp.se);
		indices[i] = treaps.size()-1;
		
		treaps.pb(tmp.fi);
	}
	
	node *merged = treaps[indices[r1.size()-1]];
	merged->rev ^= 1;
	
	for(int i = ((int)r1.size())-2; i >= 0; i--){
		treaps[indices[i]]->rev ^= 1;
		merged = merge(merged, treaps[indices[i]]);
	}
	
	for(int i = r1.size(); i < sz; i++) merged = merge(merged, treaps[indices[i]]);
	
	merged->rev ^= 1;
	for(int i = r1.size()-1; i >= 0; i--){
		int x = r[i].fi, y = r[i].se;
		int len = y - x + 1;
		
		LR tmp = split(merged, len);
		node *l = tmp.fi, *r = tmp.se;
			
		l->rev ^= 1;	
		
		treaps[indices[i]] = l;
		merged = r;	
	}
	
	for(int i = r1.size(); i < sz; i++){
		int x = r[i].fi, y = r[i].se;
		int len = y - x + 1;
		
		LR tmp = split(merged, len);
		node *l = tmp.fi, *r = tmp.se;
		
		treaps[indices[i]] = l;
		merged = r;
	}
	
	while(treaps.size() > 1){
		int sz = treaps.size();
		treaps[sz-2] = merge(treaps[sz-1], treaps[sz-2]);
		treaps.pop_back();
	}
	
	treap = treaps[0];
}

inline int query(int u, int v, int lca){
	return query_up(u, lca, true) + query_up(v, lca, false);
}

void solve(){
	char c;
	int u, v, lca;
	while(q--){
		cin >> c >> u >> v;
		lca = LCA(u,v);
		if(c == 'R') reverse(u, v, lca);	
		else cout << query(u, v, lca) << '\n';
	}
}

int main(){ _
	srand(time(NULL));
	read();
	heavyLightDecomposition();
	buildTreap();
	solve();
	return 0;
}
