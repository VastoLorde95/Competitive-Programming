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

int p[N], rnk[N], size[N];

void create(int x){
	p[x] = x;
	rnk[x] = 0;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rnk[px] > rnk[py]){
		p[py] = px;
	}
	else{
		p[px] = py;
	}
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}

int n, m;
vector<pair<int, pii> > e;
vector<pii> g[N];

ll ans[2*N];
 
ll s[N];

void dfs(int cur, int prev){
	s[cur] = 1;
	
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		
		dfs(it->fi, cur);
		ans[it->se] += 1ll * s[it->fi] * (n - s[it->fi]);
		s[cur] += s[it->fi];
	}
	
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		create(i);
	}
	
	for(int i = 1; i <= m; i++){
		int a, b, c; sd3(a,b,c);
		e.pb(mp(c, mp(a,b)));
	}	
	
	sort(e.begin(), e.end());
	
	for(int i = 0; i < m; i++){
		int x = e[i].se.fi, y = e[i].se.se;
		int z = e[i].fi;
		
		if(find(x) == find(y)) continue;
		
		g[x].pb(mp(y,z));
		g[y].pb(mp(x,z));
		
		merge(x,y);
	}
	
	dfs(1,-1);
	
	ll tot = 0;
	int mx = 0;
	for(int i = 0; i < 2*N; i++){
		tot += ans[i];
		ans[i] = tot%2;
		tot /= 2;
		if(ans[i]) mx = i;
	}
	
	while(mx >= 0){
		printf("%lld", ans[mx]);
		mx--;
	}
	puts("");
	
	

	
	return 0;
}
