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

const int N = 200100;

int n, k;
int a[N];
vector<int> g[N];

int p[N], rnk[N], sz[N];
void create(int x){
	p[x] = x, rnk[x] = 0, sz[x] = 1;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rnk[px] > rnk[py]) p[py] = px, sz[px] += sz[py];
	else p[px] = py, sz[py] += sz[px];
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}

int vis[N];

void dfs(int cur, int bad){
	vis[cur] = 1;
	foreach(it, g[cur]){
		if(vis[*it] or a[*it] < bad) continue;
		merge(cur, *it);
		dfs(*it, bad);
	}
}

int main(){
	sd2(n,k);
	
	vector<int> v;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}

	int lo = 0, hi = n, mid;
	while(lo+1 < hi){
		mid = (lo + hi) >> 1;
		
		int bad = v[mid];
		
		for(int i = 1; i <= n; i++){
			vis[i] = 0;
			create(i);
		}
		
		bool ok = false;
		for(int i = 1; i <= n; i++){
			if(!vis[i] and a[i] >= bad){
				dfs(i, bad);

				if(sz[find(i)] >= k){
					ok = true;
					break;
				}
			}
		}
		
		if(ok) lo = mid;
		else hi = mid;
	}	
	
	printf("%d\n", v[lo]);
	
	return 0;
}
