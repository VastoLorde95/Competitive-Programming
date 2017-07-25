#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 100100;

int n;
int c[N], p[N];
int best_ptr[N], best_sz[N];
multiset<int> best[N];
vector<int> g[N];

void dfs(int cur, int prev){
	int mx = -1, id = -1;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur);
		
		if(best_sz[*it] > mx){
			mx = best_sz[*it];
			id = best_ptr[*it];
		}
	}
	
	if(mx == -1){
		best_ptr[cur] = cur;
		best[cur].insert(p[cur]);
		best_sz[cur] = 1;
	}
	else{
		foreach(it, g[cur]){
			if(*it == prev or best_ptr[*it] == id) continue;
			
			int tid = best_ptr[*it];
			foreach(itt, best[tid]) best[id].insert(*itt);
			
			best[tid].clear();
		}

		best[id].insert(p[cur]);
		
		while(best[id].size() > c[cur]) best[id].erase(best[id].begin());
		
		best_ptr[cur] = id;
		best_sz[cur] = best[id].size();
	}
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++) sd2(c[i], p[i]);
	
	int u, v;
	for(int i = 1; i < n; i++){
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1,-1);
	
	long long ans = 0;
	int id = best_ptr[1];
	foreach(it, best[id]) ans += *it;
	
	printf("%lld\n", ans);
	
	return 0;
}
