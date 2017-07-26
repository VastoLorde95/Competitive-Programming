#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 200100;

int n, m, s;
vector<pair<int, int> > g[N];

int vis[N], pre[N], nxt[N], sp[N], on[N];
ll d[N], inf = 1ll<<50;

void shortestPath(int str){
	for(int i = 1; i <= n; i++){
		d[i] = inf, vis[i] = 0, pre[i] = -1;
	}
	
	priority_queue<pair<ll, int> > q;
	d[str] = 0, pre[str] = str;
	
	q.push(mp(0,str));
	
	while(!q.empty()){
		int u = q.top().se; q.pop();
		
		if(vis[u]) continue;
		vis[u] = 1;
		
		foreach(it, g[u]){
			int v = it->fi, c = it->se;
			
			if(vis[v]) continue;
		
			ll nd = d[u] + c;
			if(nd < d[v]){
				d[v] = nd;
				pre[v] = u;
				q.push(mp(-d[v], v));
			}
		}
	}
}

void shortestPath2(int str){
	for(int i = 1; i <= n; i++){
		d[i] = inf, vis[i] =  0, pre[i] = -1;
	}
	
	memset(on, 0, sizeof on);
	
	priority_queue<pair<ll, pair<int, int> > > q;
	d[str] = 0, pre[str] = str;
	on[str] = 1;
	q.push(mp(0,mp(1,str)));
	
	while(!q.empty()){
		int u = q.top().se.se; q.pop();
		
		assert(d[u] >= 0);
		
		if(vis[u]) continue;
		vis[u] = 1;
		
		foreach(it, g[u]){
			int v = it->fi, c = it->se;
			
			ll nd = d[u] + c;
			if(nd < d[v]){
				d[v] = nd;
				pre[v] = u;
				on[v] = on[u] + sp[v];
				q.push(mp(-d[v], mp(on[v], v)));
			}
			else if(nd == d[v] and on[u]+sp[v] > on[v]){
				d[v] = nd;
				pre[v] = u;
				on[v] = on[u] + sp[v];
				q.push(mp(-d[v], mp(on[v], v)));
			}
		}
	}
}

void solve(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	
	for(int i = 0; i < m; i++){
		int u, v, c; sd3(u,v,c);
		g[u].pb(mp(v,c));
		g[v].pb(mp(u,c));
	}
	
	
	memset(sp, 0, sizeof sp);
	
	sd(s);
	int x;
	for(int i = 0; i < s; i++){
		sd(x);
		sp[x] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		if(sp[i]){
			shortestPath(i);
			break;
		}
	}
	
	int mx = 0, id = -1;
	for(int i = 1; i <= n; i++){
		if(sp[i]){
			if(d[i] > mx){
				mx = d[i];
				id = i;
			}
		}
	}
	
	tr(func,line,id);
	shortestPath2(id);
	
	memset(vis, 0, sizeof vis);
	memset(nxt, 0, sizeof nxt);
	vis[id] = 1;
	
	for(int i = 1; i <= n; i++){
		if(vis[i] or !sp[i]) continue;
		
		int cur = i;
		while(!vis[cur]){
			vis[cur] = 1;
			int p = pre[cur];
			nxt[p] = cur;
			cur = p;
		}
	}
	
	vector<int> res;
	while(id > 0){
		res.pb(id);
		id = nxt[id];
	}
	
	int cnt = 0;
	foreach(it, res) cnt += sp[*it];
//	assert(cnt == s);
	
	printf("%d\n", (int) res.size());
	foreach(it, res){
		printf("%d ", *it);
	}
	puts("");
	
}


int main(){
	int t; sd(t); while(t--) solve();
	return 0;
}
