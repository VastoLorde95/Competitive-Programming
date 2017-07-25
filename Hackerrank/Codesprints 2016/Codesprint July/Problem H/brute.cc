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

const int N = 200100;

vector<pii> g[N];
vector<pair<pii, int> > cost;
int n, m;

vector<pii> st[N];

ll best = -(1ll << 60);

int active[N];

void dfs(int x, int pr, ll a, ll b){
	foreach(it, st[x]){
		if(active[it->fi]){
			b += it->se;
			active[it->fi] = 0;
		}
		else active[it->fi] = 1;
	}

	best = max(best, b - a);
	
	foreach(it, g[x]){
		if(it->fi == pr) continue;
		
		dfs(it->fi, x, a + it->se, b);
	}
	
	foreach(it, st[x]){
		active[it->fi] ^= 1;
	}
	
}


int main(){
	tr(meta);
#ifdef LOCAL
	tr(meta);
#endif
	tr(meta);
	sd(n);
	for(int i = 1; i < n; i++){
		int u, v, l;
		sd3(u,v,l);
		g[u].pb(mp(v,l));
		g[v].pb(mp(u,l));
	}
	sd(m);
	for(int i = 0; i < m; i++){
		int u, v, c; sd3(u,v,c);
		st[u].pb(mp(i,c));
		st[v].pb(mp(i,c));
	}
	
	for(int i = 1; i <= n; i++){
		dfs(i,-1, 0, 0);
	}
	
	printf("%lld\n", best);
	
	return 0;
}
