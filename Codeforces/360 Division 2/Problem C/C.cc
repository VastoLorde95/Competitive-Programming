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

const int N = 100100;

int n, m;
vector<int> g[N];
int col[N];
int vis[N];

void dfs(int cur, int c){
	if(vis[cur]){
		if(c != col[cur]){
			puts("-1");
			exit(0);
		}
		return;
	}
	
	vis[cur] = 1;
	col[cur] = c;
	
	int ncol;
	if(c == 1) ncol = 2;
	else ncol = 1;
	
	foreach(it, g[cur]){
		dfs(*it, ncol);
	}	
}

//void bfs(int cur, int c){
//	queue<pii> q;
//	q.push(mp(cur,c));
//	while(!q.empty()){
//		cur = q.front().fi, c = q.front().se; q.pop();
//		if(vis[cur]) continue;
//		col[cur] = c;
//		vis[cur] = 1;
//		
//		int ncol;
//		if(c == 1) ncol = 2; else ncol = 1;
//		
//		foreach(it, g[cur]){
//			int x = *it;
//			if(vis[cur]
//		}
//	}
//}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int u, v;
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i, 1);
		}
	}
	
	vector<int> s, t;
	for(int i = 1; i <= n; i++){
		if(col[i] == 1) s.pb(i); else t.pb(i);
	}
	
	assert(s.size() > 0 and t.size() > 0);
	assert(s.size() + t.size() == n);
	
	printf("%d\n", (int) s.size());
	foreach(it, s) printf("%d ", *it); puts("");
	printf("%d\n", (int) t.size());
	foreach(it, t) printf("%d ", *it); puts("");
	
	
	return 0;
}
