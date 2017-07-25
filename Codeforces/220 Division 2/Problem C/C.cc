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

using namespace std;

int n, m, grid[1000][1000], dp[1000][1000], color[1000][1000], mx, flag, col = 1, num;
string s;

bool inrange(int x, int y){
	if(x >= 0 and x < n and y >= 0 and y < m) return true;
	return false;
}

int dfs(int x, int y, int prev, int col){
	if(flag) return 0;
	
//	tr3(x,y,col);
	
	if(grid[x][y] != (prev)%4+1) return 0;

	if(color[x][y] == col and grid[x][y] == 1 and dp[x][y] == -1){
		flag = 1;
		return 0;
	}
	
	if(dp[x][y] > 0){
		return dp[x][y];
	}
	
//	tr3(x,y,col);
//	cin >> num;
	
	color[x][y] = col;
	
	int ret = 0;
	
	if(inrange(x+1,y) and !flag){
		ret = max(ret, dfs(x+1,y,grid[x][y],col));
	}
	if(inrange(x-1,y) and !flag){
		ret = max(ret, dfs(x-1,y,grid[x][y],col));
	}
	if(inrange(x,y+1) and !flag){
		ret = max(ret, dfs(x,y+1,grid[x][y],col));
	}
	if(inrange(x,y-1) and !flag){
		ret = max(ret, dfs(x,y-1,grid[x][y],col));
	}	
	
	if(grid[x][y] == 4) ret++;
	
	dp[x][y] = ret;
	
	mx = max(mx, ret);
	
	return dp[x][y];
	 
	
}

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			dp[i][j] = -1;
			
			if(s[j] == 'D') grid[i][j] = 1;
			else if(s[j] == 'I') grid[i][j] = 2;
			else if(s[j] == 'M') grid[i][j] = 3;
			else if(s[j] == 'A') grid[i][j] = 4;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1 and dp[i][j] == -1){
				dfs(i,j,0,col++);
			}
		}
	}
	
	if(flag == 1){
		puts("Poor Inna!");
	}
	else{
		if(mx == 0){
			puts("Poor Dima!");
		}
		else{
			printf("%d\n", mx);	
		}
	}
	
	return 0;
}
