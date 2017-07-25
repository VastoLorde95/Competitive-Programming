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

int n, x, y, grid[2001][2001], f;
vector<pair<pair<int, int>, int> > res;
int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		sd2(x,y);
		grid[x][y] = 1;
	}
	
	for(int k = 1; k < n; k++){
		for(int j = 1; j < n-k+1; j++){
			f = 0;
			for(int i = 1; i <= n-k+1; i++){
				if(grid[i][j] == 1) f = 1;
			}
			if(f == 0){
				f = n-k+1;
				res.pb(mp(mp(2,f),j));
				for(int i = 1; i <= n; i++){
					swap(grid[i][j], grid[i][f]);
				}
				break;
			}
		}
		
		for(int i = 1; i < n-k+1; i++){
			f = 0;
			for(int j = 1; j <= n-k+1; j++){
				if(grid[i][j] == 1) f = i;
			}
			if(f > 0){
				f = n-k+1;
				res.pb(mp(mp(1,f),i));
				for(int j = 1; j <= n; j++){
					swap(grid[i][j], grid[f][j]);
				}
				break;
			}
		}
		
	}
	
	printf("%d\n", (int) res.size());
	
	for(int i = 0; i < res.size(); i++){
		printf("%d %d %d\n", res[i].fi.fi, res[i].fi.se, res[i].se);
	}
	
	return 0;
}
