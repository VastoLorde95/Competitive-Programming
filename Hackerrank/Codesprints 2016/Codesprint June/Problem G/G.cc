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

const int N = 500100;
const int M = 1010;

vector<int> g[N];
vector<pair<int, pii> > paths;
vector<pair<int, pii> > edges;

int bad[M];
int l[N], r[N], t;

void dfs(int cur, int prev){
	l[cur] = ++t;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur);
	}
	r[cur] = ++t;
}

bool cmp(const pair<int, pii> &p1, const pair<int, pii> &p2){
	return p1.fi > p2.fi;
}

void solve(){
	int n, m;
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	
	edges.clear();
	for(int i = 1; i < n; i++){
		int a, b, d; sd3(a,b,d);
		g[a].pb(b);
		g[b].pb(a);
		edges.pb(mp(d, mp(a,b)));
	}
	
	dfs(1,-1);
	
	paths.clear();
	for(int i = 0; i < m; i++){
		int u, v, c; sd3(u,v,c);
		paths.pb(mp(c,mp(u,v)));
		bad[i] = 0;
	}
	
	sort(paths.begin(), paths.end(), cmp);
//	sort(edges.begin(), edges.end());
	
	ll ans = 0;
	for(int i = 1; i < (1ll << m); i++){
		int rr = __builtin_popcount(i);
		bool ok = true;
		
		ll tot = 0;
		for(int k = 0; k < m; k++){
			if(i&(1ll<<k)) tot += paths[k].fi;
		}
		
		if(tot <= ans) continue;
		
		for(int j = 0; j < n-1; j++){
			int cnt = 0;
			int cap = edges[j].fi;
			if(cap >= rr) continue;
			
			int x = edges[j].se.fi, y = edges[j].se.se;
			if(l[x] > l[y]) swap(x,y);
			
			for(int k = 0; k < m and cnt <= cap; k++){
				if((i&(1ll<<k)) == 0) continue;
				int u = paths[k].se.fi, v = paths[k].se.se;
				if(l[u] <= l[x] and l[y] <= l[v] and l[v] < r[y]) cnt++;
			}
			
			
			if(cnt > cap){
				ok = false;
				break;
			}
		}
		
		if(ok) ans = tot;
	}
	printf("%lld\n", ans);
}

int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
