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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;

int main(){
	int n, m, prev, ans, status[101][101], last = -1, flag;	
	char grid[101][101];
	memset(status, 0 , sizeof status);
	sd2(n,m);
	for(int i = 0; i < n; i++){
		scanf("%s",grid[i]);
	}
	if(n == 1)
		cout<<0<<endl;
	else{
		for(int j = 0; j < m; j++){
			flag = 0;
			for(int i = 1; i < n; i++){
				if(last == -1){
					if(grid[i][j] < grid[i-1][j]){	//If you find an inversion
						ans++;
						flag = 1;
						i = n;
					}
					if(grid[i][j] == grid[i-1][j]){
						status[i][j] = 1;
					}
				}
				else{
					if(status[i][last] == 1){
						if(grid[i][j] < grid[i-1][j]){
							ans++;
							flag = 1;
							i = n;
						}
						else if(grid[i][j] == grid[i-1][j]){
							status[i][j] = 1;
						}	
					}
				}
			}
			if(flag == 0){
				last = j;
			}	
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
