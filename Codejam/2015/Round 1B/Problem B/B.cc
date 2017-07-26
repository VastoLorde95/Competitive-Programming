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

int t, r, c, n, res, tot, num, grid[16][16];

int check(int mask){
	int cur = 0, cnt = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if( (mask&(1<<cur)) > 0){
				grid[i][j] = 1;
			}
			cur++;
		}
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 1; j < c; j++){
			if(grid[i][j] == 1 and grid[i][j-1] == 1){
				cnt++;
			}
		}
	}
	
	for(int i = 1; i < r; i++){
		for(int j = 0; j < c; j++){
			if(grid[i][j] == 1 and grid[i-1][j] == 1){
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main(){
	sd(t);
	for(int T = 1; T <= t; T++){
		sd3(r,c,n);
		
		res = 10000;	
		tot = r*c;
		
		for(int mask = 0; mask < (1<<tot); mask++){
			num = 0;
			for(int i = 0; i < tot; i++){
				if( (mask&(1<<i)) > 0){
					num++;
				}			
			}
			
			if(num == n){
				memset(grid, 0, sizeof(grid));
				res = min(res, check(mask));
			}
		}
		
		printf("Case #%d: %d\n", T, res);
			
	}
	return 0;
}
