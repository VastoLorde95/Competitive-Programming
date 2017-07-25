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

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;
const int M = 26;

int n, m;
vector<pii> g[N];
int visited[N], dist[N];
ll ways[N], k;

string ans;

int len;

void bfs(){
	ways[n] = 1;

	for(int i = 1; i <= n; i++){
		dist[i] = 1e9;
	}
	
	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();
		
		if(visited[u]) continue;
		visited[u] = 1;
		
		if(u == 1) break;
		
		foreach(it, g[u]){
			int v = it->fi, y = it->se;
			if(!visited[v] and dist[u]+1 <= dist[v]){
				dist[v] = dist[u]+1;
				ways[v] = min(k+1, ways[v] + ways[u]);
				q.push(v);
			}
		}
	}
}

ll compute(ll x, ll y){
	if(y >= ((double) k / (double) x)) return k+1;
	return x*y;
}

void buildString(){
	vector<pair<int,ll> > current;
	current.pb(mp(1,1));
	
	while(ans.length() < len){
		map<int, ll> nextNodes;
		
		for(int i = 0; i < M; i++){
			ll total = 0;
			foreach(node, current){
				int u = node->fi;
				ll paths = node->se;
				foreach(it, g[u]){
					int v = it->fi, c = it->se;
					if(c == i and dist[v] == dist[u]-1) total = min(k+1, total + compute(ways[v], paths));
				}
			}
			
			if(total >= k){
				ans += (char) ('a'+i);
				foreach(node, current){
					int u = node->fi;
					ll paths = node->se;
					foreach(it, g[u]){
						int v = it->fi, c = it->se;
						if(c == i and dist[v] == dist[u]-1) nextNodes[v] = min(k+1, nextNodes[v] + paths);
					}
				}
				
				current.clear();
				foreach(it, nextNodes) current.pb(*it);
				break;
			}
			else{
				k -= total;
			}
		}
	}
}

int main(){
	scanf("%d %d %lld", &n, &m, &k);
	
	for(int i = 0; i < m; i++){
		int u, v; char c;
		scanf(" %d %d %c", &u, &v, &c);
		g[u].pb(mp(v,c-'a'));
		g[v].pb(mp(u,c-'a'));
	}
	
	bfs();
	len = dist[1];
	
	if(ways[1] < k){
		puts("-1");
		return 0;
	}
	
	buildString();
	
	printf("%s\n", ans.c_str());
	
	return 0;
}
