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

const int N = 100100;
const int MOD = 1e9 + 7;

int n, q;
int p[N];
int vis[N];
vector<pii> g[N];
int color[N];

void init(){
	for(int i = 1; i <= n; i++){
		g[i].clear();
		vis[i] = 0;
		color[i] = 0;
	}
}

bool dfs(int cur, int col){
	if(vis[cur]){
		if(color[cur] != col) return false;
		return true;
	}
	
	vis[cur] = 1, color[cur] = col;
	
	foreach(it, g[cur]){
		int x = it->fi, t = it->se;
		if(!dfs(x, col^t)) return false;
	}
	
	return true;
}

void solve(){
	sd2(n, q);
	
	init();
	
	int u, v, x;
	for(int i = 1; i < n; i++) sd2(u,v);
	
	for(int i = 0; i < q; i++){
		sd3(u,v,x);
		g[u].pb(mp(v,x));
		g[v].pb(mp(u,x));	
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(!dfs(i,0)){
				printf("0\n"); return;
			}
			cnt++;
		}
	}
	
	printf("%d\n", p[cnt-1]);
}

int main(){
	p[0] = 1;
	for(int i = 1; i < N; i++){
		p[i] = p[i-1] << 1;
		if(p[i] >= MOD) p[i] -= MOD;
	}
	
	int t; sd(t);
	while(t--) solve();	
	return 0;
}
