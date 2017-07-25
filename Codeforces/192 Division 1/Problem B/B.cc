#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, grid[1001][1001], v[1001][1001], d[1001][1001];
int ex, ey;
int px, py;
string s;
queue<pair<pair<int, int>, int > > q;

bool inrange(int x, int y){
	if(x > 0 and x <= n and y > 0 and y <= m and grid[x][y] != -1 and v[x][y] == 0) return true;
	return false;
}

int main(){ _
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			if(s[j-1] == 'T') grid[i][j] = -1;
			else if(s[j-1] == 'S') px = i, py = j, grid[i][j] = 1;
			else if(s[j-1] == 'E') ex = i, ey = j, grid[i][j] = 0;
			else grid[i][j] = s[j-1]-'0';
			d[i][j] = 10000000;
		}
	}
	
	q.push(mp(mp(ex,ey),0));
	
	int x, y, l;
	
	while(!q.empty()){
		x = q.front().fi.fi, y = q.front().fi.se, l = q.front().se; q.pop();
		
		if(v[x][y]) continue;
		
		v[x][y] = 1;
		d[x][y] = l;
		
		if(inrange(x+1,y)) q.push(mp(mp(x+1,y),l+1));
		if(inrange(x-1,y)) q.push(mp(mp(x-1,y),l+1));
		if(inrange(x,y+1)) q.push(mp(mp(x,y+1),l+1));
		if(inrange(x,y-1)) q.push(mp(mp(x,y-1),l+1));
	}
	
	int thres = d[px][py], cnt = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(grid[i][j] != -1)
				if(d[i][j] <= thres) cnt += grid[i][j];
		}
	}
	
	cout << cnt-1 << "\n";
	
	return 0;
}
