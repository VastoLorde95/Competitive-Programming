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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 5000;

int n, m;

vector<vector<int> > g, l, r, u, d;

bool ok(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= m) return false;
	return true;
}

int dfs(int x, int y){
	if(!ok(x,y)) return 0;
	int nx, ny, mx, my, ret;
	int ax, ay, bx, by;
	if(g[x][y] == 1){
		ny = l[x][y], nx = x;
		my = r[x][y], mx = x;
		ax = u[x][y], ay = y;
		bx = d[x][y], by = y;
		if(ok(nx,ny)) r[nx][ny] = r[x][y];
		if(ok(mx,my)) l[mx][my] = l[x][y];
		if(ok(ax,ay)) d[ax][ay] = d[x][y];
		if(ok(bx,by)) u[bx][by] = u[x][y];
		
		g[x][y] = 0;
		ret = 1+dfs(nx,ny);
		g[x][y] = 1;
		
		if(ok(nx,ny)) r[nx][ny] = y;
		if(ok(mx,my)) l[mx][my] = y;
		if(ok(ax,ay)) d[ax][ay] = x;
		if(ok(bx,by)) u[bx][by] = x;
	}
	else if(g[x][y] == 2){
		ny = r[x][y], nx = x;
		my = l[x][y], mx = x;
		ax = u[x][y], ay = y;
		bx = d[x][y], by = y;
		if(ok(nx,ny)) l[nx][ny] = l[x][y];
		if(ok(mx,my)) r[mx][my] = r[x][y];
		if(ok(ax,ay)) d[ax][ay] = d[x][y];
		if(ok(bx,by)) u[bx][by] = u[x][y];

		g[x][y] = 0;
		ret = 1+dfs(nx,ny);
		g[x][y] = 2;
		
		if(ok(nx,ny)) l[nx][ny] = y;
		if(ok(mx,my)) r[mx][my] = y;
		if(ok(ax,ay)) d[ax][ay] = x;
		if(ok(bx,by)) u[bx][by] = x;
	}
	else if(g[x][y] == 3){
		nx = u[x][y], ny = y;
		mx = d[x][y], my = y;
		ay = l[x][y], ax = x;
		by = r[x][y], bx = x;
		if(ok(nx,ny)) d[nx][ny] = d[x][y];
		if(ok(mx,my)) u[mx][my] = u[x][y];
		if(ok(ax,ay)) r[ax][ay] = r[x][y];
		if(ok(bx,by)) l[bx][by] = l[x][y];
		
		g[x][y] = 0;
		ret = 1+dfs(nx,ny);
		g[x][y] = 3;
		
		if(ok(nx,ny)) d[nx][ny] = x;
		if(ok(mx,my)) u[mx][my] = x;
		if(ok(ax,ay)) r[ax][ay] = y;
		if(ok(bx,by)) l[bx][by] = y;
	}
	else{
		nx = d[x][y], ny = y;
		mx = u[x][y], my = y;
		ay = l[x][y], ax = x;
		by = r[x][y], bx = x;
		if(ok(nx,ny)) u[nx][ny] = u[x][y];
		if(ok(mx,my)) d[mx][my] = d[x][y];
		if(ok(ax,ay)) r[ax][ay] = r[x][y];
		if(ok(bx,by)) l[bx][by] = l[x][y];
		
		g[x][y] = 0;
		ret = 1+dfs(nx,ny);
		g[x][y] = 4;
		
		if(ok(nx,ny)) u[nx][ny] = x;
		if(ok(mx,my)) d[mx][my] = x;
		if(ok(ax,ay)) r[ax][ay] = y;
		if(ok(bx,by)) l[bx][by] = y;
	}
	return ret;
}

int main(){
	sd2(n,m);
	
	g.resize(n);
	l.resize(n);
	r.resize(n);
	u.resize(n);
	d.resize(n);
	
	for(int i = 0; i < n; i++){
		g[i].resize(m);
		l[i].resize(m);
		r[i].resize(m);
		u[i].resize(m);
		d[i].resize(m);
	}
	
	char s[N];	
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < m; j++){
			if(s[j] == '.') g[i][j] = 0;
			else if(s[j] == 'L') g[i][j] = 1;
			else if(s[j] == 'R') g[i][j] = 2;
			else if(s[j] == 'U') g[i][j] = 3;
			else if(s[j] == 'D') g[i][j] = 4;
		}
	}
	
	for(int i = 0; i < n; i++){
		l[i][0] = -1;
		for(int j = 1; j < m; j++){
			l[i][j] = (g[i][j-1] > 0)? j-1 : l[i][j-1];
		}
		
		r[i][m-1] = m;
		for(int j = m-2; j >= 0; j--){
			r[i][j] = (g[i][j+1] > 0)? j+1 : r[i][j+1];
		}
	}
	
	for(int j = 0; j < m; j++){
		u[0][j] = -1;
		for(int i = 1; i < n; i++){
			u[i][j] = (g[i-1][j] > 0)? i-1 : u[i-1][j];
		}
		
		d[n-1][j] = n;
		for(int i = n-2; i >= 0; i--){
			d[i][j] = (g[i+1][j] > 0)? i+1 : d[i+1][j];
		}
	}
	
	int mx = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] > 0){
				int len = dfs(i,j);
				if(len > mx) mx = len, cnt = 1;
				else if(len == mx) cnt++;
			}
		}
	}
	
	printf("%d %d\n", mx, cnt);
	
	return 0;
}
