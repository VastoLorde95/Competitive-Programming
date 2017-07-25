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

const int N = 100100;
const int M = 200100;

vector<pii> g[N];
int n, m;

int bridge[M];

int visTime[N];
int lowTime[N];
int tme;

void dfs(int cur, int prev){
	lowTime[cur] = visTime[cur] = ++tme;
	foreach(it, g[cur]){
		int nxt = it->fi, id = it->se;
		if(id == prev) continue;
		
		if(visTime[nxt] > 0){
			lowTime[cur] = min(lowTime[cur], visTime[nxt]);
		}
		else{
			dfs(nxt, id);
			if(lowTime[nxt] > visTime[cur]) bridge[id] = 1;
			lowTime[cur] = min(lowTime[cur], lowTime[nxt]);
		}
	}
}

int bridgeComp[N];
int deg[N];
int vis[N];

void makeBridgeTree(int cur, int prev, int comp){
	vis[cur] = 1;
	bridgeComp[cur] = comp;
	foreach(it, g[cur]){
		int nxt = it->fi, id = it->se;
		if(vis[nxt]) continue;
		if(bridge[id]) continue;
		
		makeBridgeTree(nxt, id, comp);
	}
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= m; i++){
		int u, v;
		sd2(u,v);
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
	}
	
	dfs(1, -1);
	
	for(int i = 2; i <= n; i++){
		if(!visTime[i]){
			printf("NO");
			return 0;
		}
	}
	
	bool ok = true;
	for(int i = 1; i <= m; i++){
		if(bridge[i]){
			ok = false; break;
		}
	}
	
	if(ok){
		printf("YES");
		return 0;
	}
	
	int node = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]) makeBridgeTree(i, -1, ++node);
	}
	
	for(int i = 1; i <= n; i++){
		int u = bridgeComp[i];
		foreach(it, g[i]){
			if(u != bridgeComp[it->fi]) deg[u]++;
		}
	}
	
	int cnt = node;
	for(int i = 1; i <= node; i++){
		if(deg[i] <= 2) --cnt;
	}
	
	printf("%s", (cnt == 0)? "YES" : "NO");
	
	return 0;
}
