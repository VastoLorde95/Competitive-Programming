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

const int MOD = 1e9 + 7;
const int N = 100100;

vector<int> g[N];
int n, m;
int cnt;

int vis[N+1];

void dfs(int x){
	vis[x] = 1;
	cnt++;
	foreach(it, g[x]){
		if(vis[*it]) continue;
		
		dfs(*it);
	}
}

int p[N];

int main(){ _
	cin >> n >> m;
	
	p[0] = 1;
	for(int i = 1; i < N; i++){
		p[i] = p[i-1] * 2;
		if(p[i] >= MOD) p[i] -= MOD;
	}
	
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		g[l].pb(r+1);
		g[r+1].pb(l);
	}
	
	ll ans = 1;
	
	for(int i = 1; i <= n+1; i++){
		if(vis[i]) continue;
		
		cnt = 0;
		dfs(i);
		
		ans = (ans * p[cnt-1]) % MOD;
	}
	
	cout << ans << endl;
	
	return 0;
}
