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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, grid[1501][1501], sx, sy;
pair<int, int> v[1501][1501];
int vi[1501][1501];
string s;

bool dfs(int x, int y, int x0, int y0){
	if(grid[x0][y0] == 0) return false;
	
	if(vi[x0][y0]){
		if(v[x0][y0].fi != x or v[x0][y0].se != y) return true;
		return false;
	}
	
//	tr2(x,y);
	
	vi[x0][y0] = 1;
	v[x0][y0] = mp(x,y);
	
	if(dfs(x+1,y,(x0+1)%n,y0)) return true;
	if(dfs(x-1,y,(x0-1+n)%n,y0)) return true;
	if(dfs(x,y+1,x0,(y0+1)%m)) return true;
	if(dfs(x,y-1,x0,(y0-1+m)%m)) return true;
	
	return false;
}

int main(){ _
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] != '#'){
				grid[i][j] = 1;
				if(s[j] == 'S') sx = i, sy = j;
			}	
		}
	}
		
	if(dfs(sx, sy, sx, sy)) cout << "Yes\n"; else cout << "No\n";
	
	return 0;
}
