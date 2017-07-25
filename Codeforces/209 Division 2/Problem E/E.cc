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

const int N = 510;

int n, xo, yo;
int g[N][N];
int v[N][N];

set<int> r[N];
set<int> c[N];

string res;

bool good(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= n) return true;
	return false;
}

char opp(char c){
	if(c == 'D') return 'U';
	if(c == 'U') return 'D';
	if(c == 'L') return 'R';
	if(c == 'R') return 'L';
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

void dfs(int x, int y, char pdir){
	if(pdir != 'X') res += pdir;
	
	if(!g[x][y]){
		res += '1';
		r[x].insert(y);
		c[y].insert(x);
	}
	
	v[x][y] = 1;
	
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		char d = dir[i];
		
		if(!good(nx,ny)) continue;
		if(v[nx][ny]) continue;
		
		if(d == 'U' and !c[y].empty() and *c[y].begin() < x)
			dfs(nx, ny, d);
		else if(d == 'D' and !c[y].empty() and *c[y].rbegin() > x)
			dfs(nx, ny, d);
		else if(d == 'L' and !r[x].empty() and *r[x].begin() < y)
			dfs(nx, ny, d);
		else if(d == 'R' and !r[x].empty() and *r[x].rbegin() > y)
			dfs(nx, ny, d);
	}
	
	res += '2';
	r[x].erase(y);
	c[y].erase(x);
	g[x][y] = 0;
	
	if(pdir != 'X') res += opp(pdir);
	
}

int main(){
	sd3(n,xo,yo);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sd(g[i][j]);
			
			if(g[i][j]){
				r[i].insert(j);
				c[j].insert(i);
			}
		}
	}	
	
	dfs(xo, yo, 'X');
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(g[i][j]){
				puts("NO");
				return 0;
			}
		}
	}
	
	printf("YES\n%s\n", res.c_str());
	
	return 0;
}
