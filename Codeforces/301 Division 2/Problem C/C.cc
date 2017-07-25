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

using namespace std;

int n, m, grid[502][502], visited[502][502], r1, c1, r2, c2;
string s;

int inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] == 0 and visited[x][y] == 0)
		return 1;
	return 0;
}

int inrange2(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m)
		return 1;
	return 0;
}

int bfs(int x, int y, int a, int b){

	if(x == r2 and y == c2){
		if(grid[x][y] == 1)
			return 1;
		else{
			if(inrange(x+1,y) == 1) return 1;
			if(inrange(x-1,y) == 1) return 1;
			if(inrange(x,y+1) == 1) return 1;
			if(inrange(x,y-1) == 1) return 1;
			
			return 0;
		}
	}
	
	if(visited[x][y] == 1 or grid[x][y] == 1)
		return 0;
	
	visited[x][y] = 1;
	
	if(x+1 == r2 and y == c2 and bfs(x+1, y, x, y) == 1)
		return 1;
	if(x-1 == r2 and y == c2 and bfs(x-1, y, x, y) == 1)
		return 1;
	if(x == r2 and y+1 == c2 and bfs(x, y+1, x, y) == 1)
		return 1;
	if(x == r2 and y-1 == c2 and bfs(x, y-1, x, y) == 1)
		return 1;
	
	if(inrange(x+1,y) == 1 and bfs(x+1, y, x, y) == 1) return 1;
	if(inrange(x-1,y) == 1 and bfs(x-1, y, x, y) == 1) return 1;
	if(inrange(x,y+1) == 1 and bfs(x, y+1, x, y) == 1) return 1;
	if(inrange(x,y-1) == 1 and bfs(x, y-1, x, y) == 1) return 1;

}

int main(){
	sd2(n,m);
	
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == 'X') grid[i+1][j+1] = 1;
		}
	}
	
	sd2(r1,c1);
	sd2(r2,c2);
	
	if(r1 == r2 and c1 == c2 and n == 1 and m == 1){
		printf("NO\n");
		return 0;
	}
	
	int x = r1, y = c1;
	
	if(inrange2(x+1,y) == 1 and bfs(x+1, y, x, y) == 1){
		printf("YES\n");
		return 0;
	}
	
	memset(visited, 0, sizeof visited);
	
	if(inrange2(x-1,y) == 1 and bfs(x-1, y, x, y) == 1){
		printf("YES\n");
		return 0;
	}
	
	memset(visited, 0, sizeof visited);
	
	if(inrange2(x,y+1) == 1 and bfs(x, y+1, x, y) == 1){
		printf("YES\n");
		return 0;
	}
	
	memset(visited, 0, sizeof visited);
	
	if(inrange2(x,y-1) == 1 and bfs(x, y-1, x, y) == 1){
		printf("YES\n");
		return 0;
	}
	else{	
		printf("NO\n");
	}
	
	return 0;
}
