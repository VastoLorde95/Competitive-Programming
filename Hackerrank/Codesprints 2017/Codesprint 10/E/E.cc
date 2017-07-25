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

const int N = 300100;

inline void upd(ll &x, ll y){
	x = max(x, y);
}

int n;
vector<int> g[N];
ll w[N];

ll best_at_node[N];
ll best_in_tree[N];

ll ans;

void getBest(int x, int p = -1){
	best_at_node[x] = w[x];
	for(int y : g[x]){
		if(y == p) continue;
		getBest(y, x);
		if(best_at_node[y] > 0) best_at_node[x] += best_at_node[y];
	}
	
	best_at_node[x] = max(best_at_node[x], 0ll);
	
	best_in_tree[x] = best_at_node[x];
	for(int y : g[x]){
		upd(best_in_tree[x], best_in_tree[y]);
	}
}

void getAns(int x, int p = -1, ll best1 = 0, ll best2 = 0){
	best1 = max(best1, 0ll);
	best2 = max(best2, 0ll);
	
	upd(ans, best_in_tree[x] * best1);
	
	for(int y : g[x]){
		if(y == p) continue;
		
		ll nbest2 = best2 + best_at_node[x] - best_at_node[y];
		ll nbest1 = max(best1, nbest2);
		getAns(y, x, nbest1, nbest2);
	}
}

int main(){ _
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> w[i];	
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	getBest(1);
	getAns(1);
	
	for(int i = 1; i <= n; i++){
		w[i] = -w[i];
		best_at_node[i] = best_in_tree[i] = 0;
	}

	getBest(1);
	getAns(1);
	
	cout << ans << endl;
	
	return 0;
}
