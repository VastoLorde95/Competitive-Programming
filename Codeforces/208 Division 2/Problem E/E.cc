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

const int N = 1010;

int n, m;
int g[N][N];

int r[N][N];
int c[N][N];

int vis[N][N];
int deg[N][N];
int in[N][N];

int tot;

vector<int> ans;

bool inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	return false;
}

int get(int x1, int y1, int x2, int y2){
	if(x1 == x2) return abs(r[x1][y1] - r[x1][y2]);
	return abs(c[x1][y1] - c[x2][y2]);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void go(int k, int x, int y){
	vector<pii> pts;
	queue<pii> q;
	
	int cnt = 1;
	q.push(mp(x,y));
	in[x][y] = 1;
	
	
	while(!q.empty()){
		x = q.front().fi;
		y = q.front().se;
		q.pop();
		
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		
		pts.pb(mp(x,y));		
				
		for(int i = 0; i < 4; i++){
			int nx = x + k * dx[i];
			int ny = y + k * dy[i];
			
			if(!inrange(nx, ny)) continue;
			if(!g[nx][ny]) continue;
			if(vis[nx][ny]) continue;
			if(get(x, y, nx, ny) != k) continue;
			
			deg[x][y]++;
			deg[nx][ny]++;

			cnt += k;
			if(in[nx][ny]) cnt--;
			
			q.push(mp(nx,ny));
			in[nx][ny] = 1;
		}
	}
	
	bool ok = true;
	
	if(cnt != tot){
		ok = false;
	}
	
	int odd = 0;
	foreach(it, pts){
		x = it->fi, y = it->se;
		if(deg[x][y] % 2) odd++;
	}
	
	if(odd > 2) ok = false;
	
	if(ok) ans.pb(k);
	
	foreach(it, pts){
		x = it->fi, y = it->se;
		deg[x][y] = 0;
		vis[x][y] = 0;
		in[x][y] = 0;
	}
	
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(g[i][j]);
			r[i][j] = c[i][j] = g[i][j];
			tot += g[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			r[i][j] += r[i][j-1];
		}
	}
	
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			c[i][j] += c[i-1][j];
		}
	}
	
	int x = -1, y = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
				x = i, y = j;
				i = n+1;
				break;
			}
		}
	}
		
	for(int i = 2; i <= tot; i++){
		go(i, x, y);
	}	
	
	if(ans.empty())
		puts("-1");
	else{
		foreach(it, ans) printf("%d ", *it); puts("");
	}
	
	return 0;
}
