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

const int N = 20100;

int n, k;
int w[N];
vector<int> g[N];
ll m[N];

int dfs(int x, int p, ll wt){
	int cnt = 0; m[x] = w[x];
	
	vector<ll> tmp;
	foreach(it, g[x]){
		if(*it == p) continue;
		cnt += dfs(*it, x, wt);
		
		m[x] += m[*it];
		tmp.pb(m[*it]);
	}
	
	sort(tmp.begin(), tmp.end());
	
	int j = (int) tmp.size() - 1;
	
	while(m[x] > wt) m[x] -= tmp[j--], cnt++;
	
	return cnt;
}

inline bool f(ll wt){
	return dfs(1, 1, wt) <= k-1;
}

int main(){
	sd2(n,k);
	
	int mx = 0;
	for(int i = 1; i <= n; i++){
		sd(w[i]);
		mx = max(mx, w[i]);
	}	
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}

	ll lo = mx-1, hi = 1ll * n * mx, mid;
	
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	
	printf("%lld\n", hi);
	
	return 0;
}
