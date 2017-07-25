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
#define fi first
#define se second

using namespace std;

int t, m, k, n, x, y, cnt;
int trans[201][201], a[200000], mn[200000], minn;
vector<int> moves[201];

int main(){
	sd(t);
	while(t--){
		sd3(m,k,n);
		
		for(int i = 1; i <= m; i++){
			moves[i].clear();
			mn[i] = 1000;
			for(int j = 1; j <= m; j++){
				trans[i][j] = 0;
			}
			trans[i][i] = 1;
		}
		
		minn = 1000, cnt = 0;
		
		for(int i = 0; i < k; i++){
			sd2(x,y);
			trans[x][y] = trans[y][x] = 1;
		}
		
		for(int k = 1; k <= m; k++){
			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= m; j++){
					trans[i][j] = (trans[i][k] & trans[k][j]);
				}
			}
		}
		
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				if(trans[i][j])
					moves[i].push_back(j);
			}
			
			sort(moves[i].begin(), moves[i].end());
		}
		
		for(int i = 0; i < n; i++){
			sd(a[i]);
		}
		
		for(int i = n-1; i >= 0; i--){
			minn = min(minn, a[i]);
			mn[i] = minn;
		}
		
		for(int i = 0; i < n; i++){
			if(a[i] > mn[i]){
				if(moves[a[i]].size() > 0 and moves[a[i]][0] <= mn[i]){
					// NOT POSSIBLE	
				}
				else{
					
				}
			}
		}
		
		
		
		
		
	}
	return 0;
}
