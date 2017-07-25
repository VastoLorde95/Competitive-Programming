#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int N = 400100;

int n;
vector<int> g[N];
int sz[N], par[N], res[N];

void dfs(int x, int p){
	sz[x] = 1;
	par[x] = p;
	foreach(it, g[x]){
		if(*it == p) continue;
		dfs(*it, x);
		sz[x] += sz[*it];
	}
}

void dfs2(int x, int p, int mx){
	if(n-sz[x]-mx <= n/2) res[x] = 1;
	
	foreach(it, g[x]){
		if(*it == p) continue;
		dfs2(*it, x, (n-sz[*it] <= n/2)? max(n-sz[*it], mx) : mx);
	}	
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		int u, v;
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1, -1);
	
	int c = -1;
	for(int i = 1; i <= n and c == -1; i++){
		int mx = n - sz[i];
		foreach(it, g[i]){
			if(*it == par[i]) continue;
			mx = max(mx, sz[*it]);
		}
		if(mx <= n/2) c = i;
	}
	
	res[c] = 1;
	
	for(int i = 1; i <= n; i++) sz[i] = 0;
	
	dfs(c, -1);
	
	int mx = 0, smx = 0, id;
	foreach(it, g[c]){
		if(mx < sz[*it]){
			smx = mx;
			mx = sz[*it]; id = *it;
		}
		else if(smx < sz[*it]) smx = sz[*it];
	}
	
	foreach(it, g[c]){
		if(*it != id)
			dfs2(*it, c, (n - sz[*it] <= n/2)? max(mx, n - sz[*it]) : mx);
		else
			dfs2(*it, c, (n - sz[*it] <= n/2)? max(smx, n - sz[*it]) : smx);
	}

	for(int i = 1; i <= n; i++) printf("%d ", res[i]);
	puts("");
	
	return 0;
}
