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

int n, m, q;
int grid[501][501], row[501];

int main(){
	sd3(n,m,q);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x; sd(x);
			grid[i][j] = x;
		}
	}
	
	for(int i = 1; i <= n; i++){
		int mx = 0, cur = 0;
		for(int j = 1; j <= m; j++){
			if(grid[i][j] == 1){
				cur++;
				mx = max(mx, cur);
			}
			else{
				cur = 0;
			}
		}
		row[i] = mx;
	}
	
	while(q--){
		int x, y;
		sd2(x,y);
		grid[x][y] = 1-grid[x][y];
		int mx = 0, cur = 0;
		for(int j = 1; j <= m; j++){
			if(grid[x][j] == 1){
				cur++;
				mx = max(mx, cur);
			}
			else{
				cur = 0;
			}
		}
		row[x] = mx;
		for(int i = 1; i <= n; i++){
			mx = max(mx, row[i]);
		}
		
		printf("%d\n", mx);
		
	}
	
	return 0;
}
