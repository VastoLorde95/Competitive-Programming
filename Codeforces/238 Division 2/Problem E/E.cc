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

const long double PI = 3.1415926535897932384626433832795;

const int N = 100100;

int n, m;

vector<int> g[N];
int v[N];

vector<pair<int, pii> > res;

int t;
int inf = 1e9;

int dfs(int cur, int prev){
	if(v[cur] != inf) return -1;
	v[cur] = ++t;

	vector<int> e;
	int nxt;
	
	foreach(it, g[cur]){
		if(v[*it] < v[cur]) continue;
		
		nxt = dfs(*it, cur);
		if(nxt > 0)
			res.pb(mp(cur, mp(*it, nxt)));
		else if(nxt == -1)
			e.pb(*it);
	}
	
	while(e.size() > 1){
		int x = e.back(); e.pop_back();
		int y = e.back(); e.pop_back();
		res.pb(mp(x,mp(cur, y)));
	}
	
	if(e.empty())
		return -1;
	else
		return e.back();
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++) v[i] = inf;
	
	
	if(m%2 == 1){
		puts("No solution");
		return 0;
	}
	
	int u, v;
	for(int i = 1; i <= m; i++){
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1, -1);	
	
	foreach(it, res){
		printf("%d %d %d\n", it->fi, it->se.fi, it->se.se);
	}
		
	return 0;
}
