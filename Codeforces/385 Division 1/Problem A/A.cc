#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 2001;

vector<int> g[N];
int f[N];
int n, m, k;

int edge[N][N];

int vis[N];
vector<int> comp;

void dfs(int x){
	vis[x] = 1;
	comp.pb(x);
	foreach(it, g[x]){
		if(vis[*it]) continue;
		dfs(*it);
	}
}

int main(){ _
	cin >> n >> m >> k;
	
	for(int i = 1; i <= k; i++){
		int c;
		cin >> c;
		f[c] = 1;
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		edge[u][v] = edge[v][u] = 1;
	}
	
	ll mx = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(f[i]){
			comp.clear();
			dfs(i);
			
			ll cnt = 0;
			for(int j = 0; j < comp.size(); j++){
				for(int k = j+1; k < comp.size(); k++){
					if(edge[comp[j]][comp[k]]) cnt++;
				}
			}
			
			ll tmp = comp.size();
			mx = max(mx, tmp);
			
			tmp = (tmp * (tmp-1))/2;
			
			ans += tmp - cnt;
		}
	}

	ll cnt2 = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(!vis[i] and !vis[j] and edge[i][j]) cnt2++;
		}
	}
	
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cnt++;
		}
	}

	ans += ((cnt * (cnt-1))/2) - cnt2;
	ans += cnt * mx;

	cout << ans << endl;
		
	return 0;
}
