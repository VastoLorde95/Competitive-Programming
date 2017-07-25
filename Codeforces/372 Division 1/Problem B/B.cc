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
typedef pair<ll,ll> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ll N = 1010;
const ll M = 10100;
const ll INF = 10000000000000ll;

vector<pair<ll, pair<ll, ll> > > g[N];

ll n, m;

ll vis[N];
set<pair<ll, ll> > q;

void sp1(ll x, ll len[]){
	for(ll i = 0; i < n; i++) vis[i] = 0;
	for(ll i = 0; i < n; i++) len[i] = INF;
	
	q.clear();
	
	len[x] = 0;
	q.insert(mp(len[x], x));
	
	while(!q.empty()){
		pii cur = *q.begin();
		q.erase(cur);
		
		ll dis = cur.fi;
		ll x = cur.se;
		
		if(vis[x]) continue;
		vis[x] = 1;
		
		foreach(it, g[x]){
			ll y = it->fi, w = it->se.fi;
			if(vis[y] or w == 0) continue;
			
			ll ndis = dis + w;
			
			if(ndis < len[y]){
				len[y] = ndis;
				q.insert(mp(len[y], y));
			}
		}
	}
}

ll prv[N];
ll len[N];
bool erased[M];
ll len1[N];
ll len2[N];
ll cost[M];

vector<pair<pii, pair<ll, ll> > > edges;

map<pii, ll> ids;

set<ll> onpath;

void sp2(ll s, ll t, ll fl){
	for(ll i = 0; i < n; i++) vis[i] = 0;
	for(ll i = 0; i < n; i++) len[i] = INF;
	for(ll i = 0; i < n; i++) prv[i] = -1;
	
	len[s] = 0;
	
	q.clear();
	q.insert(mp(len[s], s));
	
	while(!q.empty()){
		pii cur = *q.begin();
		q.erase(cur);
		
		ll dis = cur.fi;
		ll x = cur.se;
		
		if(vis[x]) continue;
		vis[x] = 1;
		
		foreach(it, g[x]){
			ll y = it->fi, w = it->se.fi, id = it->se.se;
			if(erased[id]) w = cost[id];
			if(vis[y]) continue;
			
			ll ndis = dis + w;
			
			if(ndis < len[y]){
				len[y] = ndis;
				prv[y] = x;
				q.insert(mp(len[y], y));
			}
		}
	}
	
	if(len[t] > fl){
		cout << "NO" << endl;
		exit(0);
	}
	
	vector<ll> path;
	
	ll q = t;
	while(q != -1){
		path.pb(q);
		q = prv[q];
	}

//	tr(path, len[t], fl);

	bool ok = true;
	for(ll i = 1; i < path.size(); i++){
		ll id = ids[mp(path[i-1], path[i])];
		if(!erased[id]) continue;
//		tr(path[i-1], path[i], ok);
		onpath.insert(id);
		if(ok){
			cost[id] += fl - len[t];
			ok = false;
		}
	}
	return;	
}

void sp(ll s, ll t, ll l){
	for(ll i = 0; i < n; i++) vis[i] = 0;
	for(ll i = 0; i < n; i++) len[i] = INF;
	
	len[s] = 0;
	
	q.clear();
	q.insert(mp(len[s], s));
	
	while(!q.empty()){
		pii cur = *q.begin();
		q.erase(cur);
		
		ll dis = cur.fi;
		ll x = cur.se;
		
		if(x == t){
			if(dis != l){
				tr(dis, l, dis != l);
			}
			assert(dis == l);
			break;
		}		
				
		if(vis[x]) continue;
		vis[x] = 1;
		
		foreach(it, g[x]){
			ll y = it->fi;
			ll w = it->se.fi;
			ll id = it->se.se;
			if(erased[id]) w = cost[id];
			if(vis[y]) continue;
			
			ll ndis = dis + w;
			
			if(ndis < len[y]){
				len[y] = ndis;
				q.insert(mp(len[y], y));
			}
		}
	}
}

int main(){ _
	ll l, s, t;
	cin >> n >> m >> l >> s >> t;
	
	for(ll i = 0; i < m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		g[u].pb(mp(v,mp(w,i)));
		g[v].pb(mp(u,mp(w,i)));
		
		ids[mp(u,v)] = i;
		ids[mp(v,u)] = i;
		
		erased[i] = (w == 0);
		
		edges.pb(mp(mp(u,v), mp(w,i)));
	}
	
	sp1(s, len1);
	if(len1[t] < l){
		cout << "NO" << endl;
		return 0;
	}
	else if(len1[t] == l){
		cout << "YES" << endl;
		for(ll i = 0; i < m; i++){
			if(erased[i]) edges[i].se.fi = INF;
			cout << edges[i].fi.fi << ' ' << edges[i].fi.se << ' ' << edges[i].se.fi << '\n';
		}
		return 0;
	}
	sp1(t, len2);

	for(ll i = 0; i < m; i++){
		if(!erased[i]) continue;	
		
		ll u = edges[i].fi.fi, v = edges[i].fi.se, id = edges[i].se.se;
		ll w1 = (len1[u] + len2[v]);
		ll w2 = (len1[v] + len2[u]);
		
		if(w1 <= w2){
			cost[id] = max(l - w1 , 1ll);
		}
		else{
			cost[id] = max(l - w2 , 1ll);
		}
		
		cost[id] = min(cost[id], INF);
	}
	
	sp2(s, t, l);
	
	cout << "YES" << endl;
	for(ll i = 0; i < m; i++){
		if(erased[i]){
			edges[i].se.fi = cost[edges[i].se.se];
			if(!onpath.count(edges[i].se.se)) edges[i].se.fi = INF;
			cost[i] = edges[i].se.fi;
		}
	}
	
	sp(s, t, l);
	
	for(ll i = 0; i < m; i++){
		cout << edges[i].fi.fi << ' ' << edges[i].fi.se << ' ' << edges[i].se.fi << '\n';
	}
	
	return 0;
}
