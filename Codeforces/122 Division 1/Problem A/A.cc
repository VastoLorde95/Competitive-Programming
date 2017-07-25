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

int n, m, grid[50][50], v[50][50], mn = 2, p, cnt;
string s;

bool inrange(int x, int y){
	if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1) return true;
	return false;
}

void dfs(int x, int y){
	if(v[x][y] == 1) return;
	
//	tr2(x,y);
	
//	int r; cin >> r;
	
	v[x][y] = 1;
	cnt++;
	
	if(inrange(x+1,y)) dfs(x+1,y);
	if(inrange(x-1,y)) dfs(x-1,y);
	if(inrange(x,y+1)) dfs(x,y+1);
	if(inrange(x,y-1)) dfs(x,y-1);
	
	return;
				
}

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			grid[i][j] = (s[j] == '#');
			p += grid[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1){
				grid[i][j] = 0;
				cnt = 0;
				
				memset(v, 0, sizeof(v));
				
				if(inrange(i+1,j)) dfs(i+1,j);
				else if(inrange(i-1,j)) dfs(i-1,j);
				else if(inrange(i,j+1)) dfs(i,j+1);
				else if(inrange(i,j-1)) dfs(i,j-1);
				
				if(cnt < p-1){
//					tr3(p,i,j);
					mn = 1;
				}
				
				grid[i][j] = 1;
			}
		}
	}
	
	if(p <= 2){
		printf("-1\n");
	}
	else{
		printf("%d\n",mn);
	}

	
	return 0;
}
