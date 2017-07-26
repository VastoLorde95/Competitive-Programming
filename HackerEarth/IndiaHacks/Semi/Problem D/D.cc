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

int inf = 1e9;

const int N = 1001000;
int p[N], rnk[N], sz[N];

void create(int x){
	p[x] = x;
	rnk[x] = 0;
	sz[x] = 1;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rnk[px] > rnk[py]){
		p[py] = px;
		sz[px] += sz[py];
	}
	else{
		p[px] = py;
		sz[py] += sz[px];
	}
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}

int n, m;

int get(int x, int y){
	return x*m + y;
}

bool ok(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= m) return false;
	return true;
}

pair<int,int> leftTop[N];
pair<int,int> rightTop[N];

int leftOK[N];
int rightOK[N];

vector<pair<int, pair<int, int> > > events[N]; 

int used[N];
int region[N];

int dx [] = {-1, 0};
int dy [] = {0, -1};

void update(int x, int y, int id){
	if(y < leftTop[id].se){
		leftTop[id] = mp(x,y);
	}
	else if(y == leftTop[id].se and x < leftTop[id].fi){
		leftTop[id] = mp(x,y);	
	}
	
	if(y > rightTop[id].se){
		rightTop[id] = mp(x,y);
	}
	else if(y == rightTop[id].se and x < rightTop[id].fi){
		rightTop[id] = mp(x,y);	
	}
}

void dfs1(int id, int x, int y){
	stack<pair<int,int> > st;
	st.push(mp(x,y));
	while(!st.empty()){
		x = st.top().fi, y = st.top().se; st.pop();
		if(!ok(x,y)) continue;
		int fid = find(get(x,y));
		if(fid != id) continue;
		if(leftOK[get(x,y)]) continue;
		leftOK[get(x,y)] = 1;
		st.push(mp(x+1,y));
		st.push(mp(x-1,y));
		st.push(mp(x,y+1));
	}
}

void dfs2(int id, int x, int y){
	stack<pair<int,int> > st;
	st.push(mp(x,y));
	while(!st.empty()){
		x = st.top().fi, y = st.top().se; st.pop();
		if(!ok(x,y)) continue;
		int fid = region[get(x,y)];
		if(fid != id) continue;
		if(rightOK[get(x,y)]) continue;
		rightOK[get(x,y)] = 1;
		st.push(mp(x+1,y));
		st.push(mp(x-1,y));
		st.push(mp(x,y-1));
	}
}

void solve(){
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i++) cin >> g[i];
	
	for(int i = 0; i < n*m; i++){
		create(i);
		events[i].clear();
		leftTop[i] = mp(inf,inf);
		rightTop[i] = mp(inf,-inf);
		used[i] = 0;
		leftOK[i] = 0;
		rightOK[i] = 0;
		region[i] = 0;
	}
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 2; k++){
				int nx = i+dx[k];
				int ny = j+dy[k];
				if(!ok(nx,ny)) continue;
				
				if(g[nx][ny] == g[i][j]){
					merge(find(get(nx,ny)), find(get(i,j)));
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x = find(get(i,j));
			update(i,j,x);
			region[get(i,j)] = x;
		}
	}
	
	for(int j = 0; j < m; j++){
		int i = 0;
		while(i < n){
			int x = region[get(i,j)];
			int start = i, end = i;
			i++;
			while(i < n and region[get(i,j)] == x) i++;
			end = i-1;
			events[x].pb(mp(j,mp(start, end)));
		}
	}
	
	memset(used, 0, sizeof used);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int id = region[get(i,j)];
			if(!used[id]){
				dfs1(id, leftTop[id].fi, leftTop[id].se);
				dfs2(id, rightTop[id].fi, rightTop[id].se);
				used[id] = 1;
			}
		}
	}
	
	memset(used, 0, sizeof used);
	
	for(int k = 0; k < n; k++){
		for(int j = 0; j < m; j++){
			int id = region[get(k,j)];
			if(used[id]) continue;
			used[id] = 1;
			
			for(int i = 1; i < events[id].size(); i++){
				if(events[id][i].fi == events[id][i-1].fi){
					int low = events[id][i-1].se.se;
					int hi = events[id][i].se.fi;
					int j = events[id][i].fi;
					int x = get(low,j);
					int y = get(hi,j);
					
					if(leftOK[x] == 1 and rightOK[x] == 1 and leftOK[y] == 1 and rightOK[y] == 1){
						cout << "NO\n";
						return;
					}
				}
			}
		}
	}
	
	
	cout << "YES\n";

}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
