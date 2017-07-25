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

const ld PI = 3.1415926535897932384626433832795;

const int LOGN = 19;
const int N	= 1 << LOGN;
const int MAXN = N;

int tree[MAXN*4]; // Careful, indexing begins from 1.
int lazy[MAXN*4];

int n;

void push(int id){
	int left = 2*id, right = left + 1;
	if(lazy[id]){
		if(lazy[id] == -1) tree[id] = 0;
		else tree[id] = 1;
	
		lazy[left] = lazy[id];
		lazy[right] = lazy[id];
		
		lazy[id] = 0;
	}
}

int query(int idx, int id = 1, int l = 1, int r = n){
	push(id);
	if(l == r) return tree[id];
	
    int mid = (l + r) >> 1;
    if(idx <= mid) return query(idx, id*2, l, mid);
    else return query(idx, (id*2)+1, mid+1, r);
}

void update(int x, int y, int val, int id = 1, int l = 1, int r = n){
	if(y < l or x > r) return;
	if(x <= l and r <= y){
		lazy[id] = val;
		return;
	}
	push(id);
	
	int mid = (l + r) >> 1;
	int left = 2*id, right = left + 1;
	
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid+1, r);
	
}

vector<int> g[N];
int pos[N];
int chainId[N];
int chainHead[N];
int sz[N];
int L[N], R[N];
int chain_num = 1, tme;
int par[N];

void update_up(int u, int v){
	while(true){
		if(chainId[u] == chainId[v]){
			update(pos[v], pos[u], -1);
			return;
		}
		
		int nxt = chainHead[chainId[u]];
		update(pos[nxt], pos[u], -1);
		u = par[nxt];
	}
}

void dfs(int x, int p){
	sz[x] = 1;
	par[x] = p;
	foreach(it, g[x]){
		if(*it == p) continue;
		dfs(*it, x);
		sz[x] += sz[*it];
	}
}

void hld(int x, int p){
	pos[x] = ++tme;
	L[x] = tme;
	chainId[x] = chain_num;
	if(!chainHead[chain_num]) chainHead[chain_num] = x;
	
	int hsize = 0, hchild = -1;
	foreach(it, g[x]){
		if(*it == p) continue;
		if(sz[*it] > hsize){
			hsize = sz[*it];
			hchild = *it;
		}
	}

	if(hchild == -1){
		R[x] = tme;
		return;
	}
	hld(hchild, x);
	
	foreach(it, g[x]){
		if(*it == p or *it == hchild) continue;
		chain_num++;
		hld(*it, x);
	}
	
	R[x] = tme;
}

int main(){ _
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1, 1);
	hld(1, 1);
	
	int q;
	cin >> q;
	while(q--){
		int c, v;
		cin >> c >> v;
		if(c == 1){
			update(L[v], R[v], 1);
		}
		else if(c == 2){
			update_up(v, 1);
		}
		else{
			cout << query(pos[v]) << '\n';
		}
	}
	
	return 0;
}
