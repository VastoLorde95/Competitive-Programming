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

const int N = 1010;
const int M = 11;
const int INF = 1e9;

int n, m, k;

int dis[N][1<<M];
int vis[N][1<<M];
int mask[N];
vector<pii> g[N];

set<pair<int, pii> > q;

void go(){
	dis[1][mask[1]] = 0;
	
	q.insert(mp(dis[1][mask[1]], mp(1, mask[1])));
	
	while(!q.empty()){
		pair<int, pii> top = *q.begin();
		q.erase(q.begin());
		
		int x = top.se.fi;
		int msk = top.se.se;
		
		if(vis[x][msk]) continue;
		vis[x][msk] = 1;
		dis[x][msk] = top.fi;
		
		foreach(it, g[x]){
			int y = it->fi, w = it->se;
			int nmask = msk | mask[y];
			
			if(vis[y][nmask]) continue;
			
			int ndis = dis[x][msk] + w;
			if(ndis < dis[y][nmask]){
				dis[y][nmask] = ndis;
				q.insert(mp(dis[y][nmask], mp(y, nmask)));
			}
		}	
	}
}

int main(){
	sd3(n,m,k);
	
	for(int i = 1; i <= n; i++){
		int ti;
		sd(ti);
		int x;
		while(ti--){
			sd(x); x--;
			mask[i] |= (1 << x);
		}
	}
	
	for(int i = 1; i <= m; i++){
		int u, v, t;
		sd3(u,v,t);
		g[u].pb(mp(v,t));
		g[v].pb(mp(u,t));
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << k); j++){
			dis[i][j] = INF;
		}
	}

	go();
	
	int ans = INF;
	
	for(int i = 0; i < (1 << k); i++){
		for(int j = 0; j < (1 << k); j++){
			if((i|j) == ((1 << k) - 1)){
				ans = min(ans, max(dis[n][i], dis[n][j]));
			}		
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
