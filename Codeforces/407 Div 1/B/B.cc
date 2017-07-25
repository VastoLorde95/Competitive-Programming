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

const int N = 1001000;

vector<int> g[N];
ll d[N];
ll loop;
int n, m;
int vis[N];
int longd[N];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	foreach(it, g[x]) dfs(*it);
}

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		int u, v;
		sd2(u,v);
		
		longd[u]++;
		longd[v]++;
		
		if(u == v){
			loop++;
		}
		else{
			d[u]++;
			d[v]++;
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(longd[i] > 0){
			dfs(i);
			break;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i] and longd[i] > 0){
			printf("0\n");
			return 0;
		}
	}
	
	ll ans = 0;
	ans += loop * (m - loop);
	
	ans += (loop * (loop-1)) / 2;
	
	for(int i = 1; i <= n; i++){
		ans += (d[i] * (d[i] - 1)) / 2;
	}
	
	assert(ans >= 0);
	
	printf("%lld\n", ans);
	
	return 0;
}
