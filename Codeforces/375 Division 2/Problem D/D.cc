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

const int N = 60;

int g[N][N];
int vis[N][N];

vector<pii> comp[N*N];

int n, m, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m and g[x][y] == 1) return true;
	return false;
}

bool onborder(int x, int y){
	if((x == 1 or x == n) or (y == 1 or y == m)) return true;
	return false;
}

void dfs(int x, int y, int c){
	if(vis[x][y]) return;
	
	vis[x][y] = 1;
	comp[c].emplace_back(x,y);
	
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(!inrange(nx, ny)) continue;
		dfs(nx, ny, c);
	}
}

bool cmp(const int &i, const int &j){
	return comp[i].size() < comp[j].size();
}

int main(){ _
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++){
			g[i+1][j+1] = (s[j] == '.');
		}
	}	

	int cno = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(vis[i][j] == 0 and g[i][j] == 1){
				dfs(i, j, ++cno);
			}
		}
	}
	
	vector<int> v;
	for(int i = 1; i <= cno; i++){
		bool ok = true;
		for(auto &pt : comp[i]){
			if(onborder(pt.fi, pt.se)){
				ok = false;
				break;
			}
		}
		if(ok) v.pb(i);
	}

	sort(v.begin(), v.end(), cmp);
	
	int sz = v.size();
	int todel = sz - k;
	
	assert(todel >= 0);
	
	int cost = 0;
	for(int i = 0; i < todel; i++){
		for(auto &pt : comp[v[i]]){
			g[pt.fi][pt.se] = 0;
		}
		cost += comp[v[i]].size();
	}
	
	cout << cost << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]) cout << '.';
			else cout << '*';
		}
		cout << endl;
	}
	
	return 0;
}
