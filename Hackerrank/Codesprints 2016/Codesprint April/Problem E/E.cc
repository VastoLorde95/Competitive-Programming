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

const int N = 50100;

int n;
int c[N];
int d[N];

vector<int> g[N];

int xsum[N][2];


int l[N], r[N];

int t;

void dfs(int cur, int prev){
	xsum[cur][0] = c[cur];
	
	l[cur] = ++t;
	
	foreach(it, g[cur]){
		if(*it == prev) continue;

		d[*it] = d[cur] + 1;
		dfs(*it, cur);
		
		xsum[cur][0] ^= xsum[*it][1];
		xsum[cur][1] ^= xsum[*it][0];
		
	}
	
	r[cur] = ++t;
}

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		sd(c[i]);
	}
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1,-1);		

	int q; sd(q);
	while(q--){
		int u, v; sd2(u,v);
		if(l[u] < l[v] and l[v] < r[u]){
			puts("INVALID");
			continue;
		}
		
		int x = xsum[1][1];
		
		int d1 = d[u], d2 = d[v];
		
		if(d1 % 2 == 1)
			x ^= xsum[u][0];
		else
			x ^= xsum[u][1];
		if(d2 % 2 == 0)
			x ^= xsum[u][0];
		else
			x ^= xsum[u][1];
		
		if(!x) puts("NO"); else puts("YES");
	}
	
	return 0;
}
