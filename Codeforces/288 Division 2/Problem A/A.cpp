#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int grid[1002][1002], n, m, k, x, y;

int is_square(int i, int j){
	if(grid[i][j] == 1 and grid[i-1][j] == 1 and grid[i][j-1] == 1 and grid[i-1][j-1] == 1){
		return 1;
	}
	if(grid[i][j] == 1 and grid[i+1][j] == 1 and grid[i][j-1] == 1 and grid[i+1][j-1] == 1){
		return 1;
	}	
	if(grid[i][j] == 1 and grid[i-1][j] == 1 and grid[i-1][j+1] == 1 and grid[i][j+1] == 1){
		return 1;
	}
	if(grid[i][j] == 1 and grid[i+1][j] == 1 and grid[i][j+1] == 1 and grid[i+1][j+1] == 1){
		return 1;
	}
	return 0;
}

int main(){
	cin>> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		grid[x][y] = 1;
		if(is_square(x, y) == 1){
			cout<< i+1 << endl;
			return 0;
		}	
	}
	cout<< 0 << endl;
	return 0;
}
