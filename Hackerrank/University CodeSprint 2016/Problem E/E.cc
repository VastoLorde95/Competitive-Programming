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

const int N = 10000;

int n;
int m;

vector<int> g[N];
int col[N];
int best[N];
int c;

vector<int> path, ans;

void dfs(int x){
	path.pb(x);
	int id = path.size();
	col[x] = c;
	
	int nxt = -1;
	int b = -1;
	
	foreach(it, g[x]){
		if(col[*it] == c) continue;
		if(best[*it] > b){
			b = best[*it];
			nxt = *it;
		}
		if(g[*it].size() == 2){
			nxt = *it;
			break;
		}
	}
	
	if(nxt == -1) return;
	if(c > 1000 and path.size() + best[nxt] <= ans.size()) return;

	dfs(nxt);
	return;
}

unordered_set<int> edges[N];
//set<pii> edges;

int main(){ _
	cin >> n >> m;	
	
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].pb(y);
		g[y].pb(x);
		
		edges[x].insert(y);
		edges[y].insert(x);
	}
	
	srand(unsigned(time(0)));
	
	for(int i = 0; i < n; i++){
		random_shuffle(g[i].begin(), g[i].end());
	}
	
//	int ITER = 1+n/2;
//	if(n == 10000) ITER = 1000;
//	if(n <= 500) ITER *= 10;

	int ITER = 150;
	for(int j = 0; j < ITER; j++){
		c++;
		
		path.clear();
		
		dfs(rand()%n);
//		dfs(0);
		
		if(path.size() > ans.size()) ans = path;
		
		int sz = path.size();
		for(int i = 0; i < sz; i++){
			best[path[i]] = max(best[path[i]], max(sz-i,i+1));
		}
		
		if(sz == n) break;
	}
	
	vector<int> vis(n,0);
	
	for(auto &x : ans){
		vis[x] = 1;
	}
	
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		
		for(int j = 1; j < ans.size(); j++){
			if(edges[ans[j-1]].count(i) and edges[i].count(ans[j])){
				vector<int> t;
				
				for(int k = 0; k < j; k++){
					t.pb(ans[k]);
				}
				
				t.pb(i);
				
				for(int k = j; k < ans.size(); k++){
					t.pb(ans[k]);
				}
				
				vis[i] = 1;
				ans = t;
				break;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		
		for(int j = 1; j < ans.size(); j++){
			if(edges[ans[j-1]].count(i) and edges[i].count(ans[j])){
				vector<int> t;
				
				for(int k = 0; k < j; k++){
					t.pb(ans[k]);
				}
				
				t.pb(i);
				
				for(int k = j; k < ans.size(); k++){
					t.pb(ans[k]);
				}
				
				vis[i] = 1;
				ans = t;
				break;
			}
		}
	}
	
	cout << ans.size() << endl;
	foreach(it, ans){
		cout << *it+1 << ' ';
	}
	cout << endl;
	
	return 0;
}
