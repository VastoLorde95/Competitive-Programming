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

const int N = 3010;
const int INF = 1e9;

int n, m;
int d[N][N];

vector<int> g[N];
int dis[N];
int v[N];

set<pii> s[N];
set<pii> t[N];

queue<int> q;
void bfs(int u){
	int st = u;
	q.push(st);
	
	for(int i = 1; i <= n; i++){
		dis[i] = INF;
		v[i] = 0;
	}
	
	dis[st] = 0;
	while(!q.empty()){
		st = q.front(); q.pop();
		
		if(v[st]) continue;
		v[st] = 1;
		
		foreach(it, g[st]){
			if(dis[*it] != INF or v[*it]) continue;
			dis[*it] = min(dis[*it], dis[st] + 1);
			q.push(*it);
		}
	}
	
	for(int i = 1; i <= n; i++){
		d[u][i] = dis[i];
	}
}

vector<int> res;

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= m; i++){
		int u, v; sd2(u,v);
		if(u == v) continue;
		d[u][v] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(d[i][j]) g[i].pb(j);
		}
	}
	
	for(int i = 1; i <= n; i++){
		bfs(i);
		
		for(int j = 1; j <= n; j++){
			if(d[i][j] == INF or j == i) continue;
			
			if(s[i].size() < 3) s[i].insert(mp(d[i][j], j));
			else{
				s[i].insert(mp(d[i][j], j));
				s[i].erase(s[i].begin());
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(d[j][i] == INF or j == i) continue;
			
			if(t[i].size() < 3) t[i].insert(mp(d[j][i], j));
			else{
				t[i].insert(mp(d[j][i], j));
				t[i].erase(t[i].begin());
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j or d[i][j] == INF) continue;
			
			int cur = d[i][j];
			
			foreach(it, t[i]){
				if(it->se == j) continue;
				foreach(it2, s[j]){
					if(it2->se == i or it2->se == it->se) continue;
					if(ans < cur + it->fi + it2->fi){
						ans = cur + it->fi + it2->fi;
						res.clear();
						res.pb(it->se);
						res.pb(i);
						res.pb(j);
						res.pb(it2->se);
					}
				}
			}
		}
	}
	
	assert(ans < INF);
	
	tr(res);
	
	
	return 0;
}
