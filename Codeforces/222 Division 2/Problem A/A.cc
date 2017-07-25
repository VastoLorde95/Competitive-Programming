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

int n, m, tot, k, cnt, grid[502][502];
string s;

void bfs(int x, int y){
	
	if(x < 0 or x >= n or y < 0 or y >= m)
		return;
	if(cnt == tot-k){
		return;
	}
	if(grid[x][y] == 3 or grid[x][y] == 2){
		return;
	}
	
	grid[x][y] = 3;
	
	//cout << x << " " << y << " " << grid[x][y] << endl;
	
	cnt++;
	
	bfs(x+1,y);
	bfs(x-1,y);
	bfs(x,y+1);
	bfs(x,y-1);
	
	return;
}

int main(){
	sd3(n,m,k);
	
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '.'){
				grid[i][j] = 1;
				tot++;
			}
			else{
				grid[i][j] = 2;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1){
				//cout << i << " " << j << endl;
				bfs(i, j);
				i = n, j = m;
				break;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//cout << grid[i][j] << " " << i << " " << j << endl;
			if(grid[i][j] == 1){
				printf("X");
			}
			else if(grid[i][j] == 2){
				printf("#");
			}
			else{
				//cout << "dude" << endl;
				printf(".");
			}
		}
		printf("\n");
	}
	
	return 0;
}
