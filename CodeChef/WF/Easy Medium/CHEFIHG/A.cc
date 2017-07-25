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

const int N = 21;

int g[N][N];
int n, m;

bool inrange(int x, int y){
	return (1 <= x and x <= n and 1 <= y and y <= m and g[x][y] > 0);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

string res;

int vis[N][N];
int pre[N][N][2];
int type[N][N];

int Dx, Dy;

char getc(int i){
	if(i == 0) return 'D';
	else if(i == 1) return 'U';
	else if(i == 2) return 'R';
	else return 'L';
}

void bfs(int x, int y){
//	tr(x, y, res);
	for(char c : res){
		if(c == 'L' and inrange(x, y-1)) y--;
		if(c == 'R' and inrange(x, y+1)) y++;
		if(c == 'U' and inrange(x-1, y)) x--;
		if(c == 'D' and inrange(x+1, y)) x++;
	}
//	tr(x, y);

	memset(vis, 0, sizeof vis);
	memset(pre, -1, sizeof pre);
	memset(type, -1, sizeof type);
	
	queue<pii> q;
	q.push(mp(x,y));
	
	while(!q.empty()){
		pii cur = q.front();
		q.pop();
		
		int x = cur.fi, y = cur.se;
		
//		tr(x, y);
		
		if(x == Dx and y == Dy) break;
		
		if(vis[x][y]) continue;
		
		vis[x][y] = 1;
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

//			tr(nx, ny, pre[nx][ny][0], pre[nx][ny][1], vis[nx][ny], g[nx][ny]);			
			if(!inrange(nx, ny) or pre[nx][ny][0] != -1 or vis[nx][ny]) continue;
//			tr(nx, ny, pre[nx][ny][0], pre[nx][ny][1], vis[nx][ny]);
			
			pre[nx][ny][0] = x;
			pre[nx][ny][1] = y;
			type[nx][ny] = i;
			q.push(mp(nx, ny));
		}
	}
	
	x = Dx, y = Dy;
	
//	tr(x, y, pre[x][y][0]);
	
	string tmp;
	while(pre[x][y][0] != -1){
		tmp += getc(type[x][y]);
		int nx = pre[x][y][0];
		int ny = pre[x][y][1];
		x = nx;
		y = ny;
	}
	
	reverse(tmp.begin(), tmp.end());
	res += tmp;
}

int main(){ _
	cin >> n >> m;
	
	string s;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			if(s[j-1] == '.') g[i][j] = 1;
			else if(s[j-1] == 'C'){
				g[i][j] = 2;
				Dx = i;
				Dy = j;
			}
		}
	}
	
	for(int i = 2; i < n; i++){
		for(int j = 2; j < m; j++){
			if(g[i][j] != 1) continue;
			bfs(i, j);
		}
	}

	assert(100000 >= res.length());
	
	cout << res << endl;
	
	return 0;
}
