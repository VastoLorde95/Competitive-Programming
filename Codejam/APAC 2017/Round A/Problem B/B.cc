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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 51;

int n, m;
int g[N][N];
int w[N][N];
int ok[N][N];
int v[N][N];

vector<pii> comp;

bool check(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	return false;
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y, int h, int id){
	if(v[x][y] or g[x][y] > h) return;
	v[x][y] = id;
	comp.pb(mp(x,y));
	
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!check(nx,ny)) continue;
		dfs(nx,ny,h,id);
	}	
}
	
bool checkComp(){
	for(int i = 0; i < comp.size(); i++){
		int x = comp[i].fi, y = comp[i].se;
		if(x == 1 or x == n or y == 1 or y == m) return false;
	}
	return true;
}

void getW(int id){
	int mn = 1e9;
	for(int i = 0; i < comp.size(); i++){
		int x = comp[i].fi, y = comp[i].se;
		for(int j = 0; j < 4; j++){
			int nx = x + dx[j];
			int ny = y + dy[j];
			if(!check(nx,ny)) continue;
			if(v[nx][ny] != id){
				mn = min(mn, g[nx][ny]);
			}
		}
	}
	
	for(int i = 0; i < comp.size(); i++){
		int x = comp[i].fi, y = comp[i].se;
		w[x][y] = mn;
	}
}



void solve(){
	sd2(n,m);
	
	set<int> h;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(g[i][j]);
			h.insert(g[i][j]);
			w[i][j] = g[i][j];
			v[i][j] = 0;
		}
	}
	
	foreach(it, h){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				v[i][j] = 0;
			}
		}
		
		int id = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(!v[i][j]){
					comp.clear();
					dfs(i,j,*it, ++id);
					
					if(!checkComp()) continue;
					
					getW(id);
					
				}
			}
		}
	}
	
	int tot = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			tot += w[i][j] - g[i][j];
		}
	}
	
	printf("%d\n", tot);
}

int main(){
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
