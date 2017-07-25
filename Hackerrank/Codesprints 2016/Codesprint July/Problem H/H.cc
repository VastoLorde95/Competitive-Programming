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
typedef pair<int,int> pii;

const int LOGN = 18;
const int N = 1 << LOGN;
const ll INF = 1ll << 60;

struct node{
	ll mx;
	void assign(ll value){ mx = value; }
	void update(ll value){ mx += value; }
	void combine(node &left, node &right){ mx = max(left.mx, right.mx); }
};

int n;
ll a[N], lazy[N];
node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd(int id,ll x){
	lazy[id] += x;
	tree[id].update(x);
}

void shift(int id,int l,int r){
	if(lazy[id] and l+1 < r){
		upd(id * 2, lazy[id]);
		upd(id * 2 + 1, lazy[id]);
		lazy[id] = 0;
	}
}

void update(int x, int y, ll val, int id = 1, int l = 0, int r = n){
	if(x >= y) return;
	if(x >= r or l >= y) return;
	if(x <= l && r <= y) return upd(id, val);
	shift(id, l, r);
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	update(x, y, val, left, l, mid); 
	update(x, y, val, right, mid, r);
	tree[id].combine(tree[left], tree[right]);
	return;
}

ll query(){ return tree[1].mx; }

int p[LOGN][1<<LOGN], lvl[1<<LOGN];

int LCA(int x, int y){
	if(lvl[x] < lvl[y]) swap(x,y);
	int tmp = 1;
	while((1<<tmp) <= lvl[x]) tmp++;
	tmp--;
	for(int i = tmp; i >= 0; i--)  if(lvl[x] - (1<<i) >= lvl[y]) x = p[i][x];
	if(x == y) return y;
	for(int i = tmp; i >= 0; i--) if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];
	return p[0][x];
}

vector<pii> g[N];
int m;
int pos[N], tstamp;
int l[N], r[N];

vector<pii> subtree[N];

//void dfs1(int cur, int prev, ll wt){
//	stack<int> s;
//	s.push(cur);
//	
//	int vis[N] = {0};
//	int ptr[N] = {0};
//	
//	vis[cur] = 1;
//	while(!s.empty()){
//		cur = s.top();
//		if(ptr[cur] == g[cur].size()){
//			r[cur] = tstamp - 1;
//			s.pop();
//		}
//		else{
//			int nxt = g[cur][ptr[cur]].fi;
//			if(vis[nxt]){
//				ptr[cur]++; continue;
//			}
//			
//			lvl[nxt] = lvl[cur] + 1;
//			p[0][nxt] = cur;
//			l[nxt] = tstamp++;
//		}
//	}
//	p[0][1] = 1;
//	
//}

void dfs1(int cur, int prev, ll wt){
	tr(cur, lvl[cur]);
	l[cur] = pos[cur] = tstamp++;
	a[pos[cur]] = wt, p[0][cur] = prev;
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		lvl[it->fi] = lvl[cur] + 1;
		dfs1(it->fi, cur, wt - it->se);
		subtree[cur].pb(mp(l[it->fi], r[it->fi]));
	}
	r[cur] = tstamp-1;
}

int cost[N];
int active[N];
int type[N];
vector<pii> tkt[N];

void dfs2(int cur, int prev, ll profit){
	foreach(it, tkt[cur]){
		int id = it->se;
		if(!type[id]) continue;
		if(active[id]) profit += cost[id];
		else active[id] = 1;
	}
	
	a[pos[cur]] += profit;
	
	foreach(it, g[cur]){
		int nxt = it->fi;
		if(nxt == prev) continue;
		dfs2(nxt, cur, profit);
	}
	
	foreach(it, tkt[cur]){
		int id = it->se;
		if(!type[id]) continue;
		if(active[id]) active[id] = 0;
	}
}

bool cmp(const pii &p1, const pii &p2){
	return pos[p1.fi] < pos[p2.fi];
}

ll ans;

void dfs3(int cur, int prev){
	foreach(it, tkt[cur]){
		int nxt = it->fi, id = it->se;
		if(type[id]){
			if(LCA(nxt, cur) == nxt){
				vector<pii>::iterator jt = upper_bound(subtree[nxt].begin(), subtree[nxt].end(), mp(r[cur], r[cur]));
				jt--;
				update(0, jt->fi, cost[id]);
				update(jt->se + 1, n, cost[id]);
			}
			continue;
		}
		update(l[nxt], r[nxt] + 1, cost[id]);
	}
	
	
//	for(int i = 1; i <= n; i++){
//		tr("######", meta, cur, i, query(pos[i], pos[i]+1));
//	}
	
	ans = max(ans, query());
//	tr(meta, cur, ans);
	
	int j = 0;
	
	foreach(it, g[cur]){
		int nxt = it->fi, cst = it->se;
		if(nxt == prev) continue;
		
		vector<int> rev;
		while(j < tkt[cur].size()){
			if(!type[tkt[cur][j].se]){
				j++; continue;
			}
			
			int ptr = tkt[cur][j].fi;
			
			if(LCA(ptr, cur) == ptr){
				j++; continue;
			}
			
			if(l[ptr] < l[nxt]){
				j++; continue;
			}
			
			if(l[ptr] > r[nxt]) break;
			
//			tr(meta, cur, nxt, ptr);
			rev.pb(j);
			update(l[ptr], r[ptr] + 1, -cost[tkt[cur][j].se]);
			
			j++;
		}
		
		update(0, l[nxt], -cst);
		update(l[nxt], r[nxt] + 1, cst);
		update(r[nxt] + 1, n, -cst);
		
		dfs3(nxt, cur);
		
		update(0, l[nxt], cst);
		update(l[nxt], r[nxt] + 1, -cst);
		update(r[nxt] + 1, n, cst);
		
		foreach(jt, rev){
			int ptr = tkt[cur][*jt].fi;
			update(l[ptr], r[ptr] + 1, cost[tkt[cur][*jt].se]);
		}
	}
	
	foreach(it, tkt[cur]){
		int nxt = it->fi, id = it->se;
		if(type[id]){
			if(LCA(nxt, cur) == nxt){
				vector<pii>::iterator jt = upper_bound(subtree[nxt].begin(), subtree[nxt].end(), mp(r[cur], r[cur]));
				jt--;
				update(0, jt->fi, -cost[id]);
				update(jt->se + 1, n, -cost[id]);
			}
			continue;
		}
		update(l[nxt], r[nxt] + 1, -cost[id]);
	}
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		 int u, v, l; sd3(u,v,l);
		 g[u].pb(mp(v,l));
		 g[v].pb(mp(u,l));
	}
	
	tr(meta);
	dfs1(1, 1, 0);
	tr(meta);
	for(int i = 1; i < LOGN; i++) for(int j = 1; j <= n; j++) p[i][j] = p[i-1][p[i-1][j]];
	
	sd(m);
	for(int i = 1; i <= m; i++){
		int u, v, l; sd3(u,v,l);
		 cost[i] = l;
		 tkt[u].pb(mp(v,i));
		 tkt[v].pb(mp(u,i));
		 
		 int z = LCA(u,v);
		 if(z == u or z == v){
		 	type[i] = 1;
		 }
	}
	
	dfs2(1, 1, 0);
	
	for(int i = 1; i <= n; i++) sort(tkt[i].begin(), tkt[i].end(), cmp);
	
	build();
	
	ans = query();
	
	dfs3(1, 1);
	
	printf("%lld\n", ans);
	
	return 0;
}
