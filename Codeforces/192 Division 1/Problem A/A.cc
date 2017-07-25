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

int n, grid[101][101], cnt;
bool row, col;
vector<pair<int, int> > res;
string s;

int main(){	
	sd(n);
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			if(s[j] == 'E') grid[i+1][j+1] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		row = true;
		for(int j = 1; j <= n; j++){
			if(grid[i][j] != 1)
				row = false;		
		}
		if(row) break;
	}
	
	for(int i = 1; i <= n; i++){
		col = true;
		for(int j = 1; j <= n; j++){
			if(grid[j][i] != 1)
				col = false;		
		}
		if(col) break;
	}
	
	if(row and col){
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(grid[i][j] == 0){
				res.pb(mp(i, j));
				break;
			}
		}
	}
	
	if(res.size() != n){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(grid[j][i] == 0){
					printf("%d %d\n",j, i);
					break;
				}
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			printf("%d %d\n", res[i].fi, res[i].se);
		}
	}
	
	return 0;
}
