#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, indx;
char g[600][600];
int MOD = 1e9 + 7;
long long dp[2][600][600];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		scanf("%s", g[i]);
	}
	
	int l = n+m-1, mid, x;
	
	if(l%2 == 1){
		mid = l/2;
		for(int i = 0; i < n; i++){
			if(mid-i < m){
				x = i; break;
			}
		}
		
		for(int i = x; i < n and mid-i < m; i++){
			dp[0][i][i] = 1;
		}
	}
	else{
		mid = l/2;
		for(int i = 0; i < n; i++){
			if(mid-i < m){
				x = i; break;
			}
		}
		
//		tr2(mid,x);
		
		for(int i = x; i < n and mid-i >= 0 and mid-i < m; i++){
			if(g[i][mid-i] == g[i][mid-i-1])
				dp[0][i][i]++;
//			tr4("#",i,i,dp[0][i][i]);
			if(i-1 >= 0 and g[i][mid-i] == g[i-1][mid-i])
				dp[0][i][i-1]++;
//			tr4("#",i,i-1,dp[0][i][i-1]);
				
		}
	}
	
	
	
	for(int i = mid+1; i <= n+m-2; i++){
		indx ^= 1;
		x = n+1;
		for(int j = 0; j < n; j++){
			if(i-j < m){
				x = j; break;
			}
		}
		for(int j = x; j < n and i-j >= 0 and i-j < m; j++){
			for(int k = 0; k < n; k++){
				dp[indx][j][k] = 0;
				int tx = k, ty = (n+m-2-i)-k;
				if(ty >= 0 and ty < m){
//					tr5(i,j,i-j,tx,ty);
					if(g[j][i-j] == g[tx][ty]){
						dp[indx][j][tx] += dp[1-indx][j][tx] + dp[1-indx][j][tx+1];
						if(j-1 >= 0)
							dp[indx][j][tx] += dp[1-indx][j-1][tx] + dp[1-indx][j-1][tx+1];
						dp[indx][j][tx] %= MOD;
//						tr6(i,j,i-j,tx,ty,dp[indx][j][tx]);
					}
				}
			}
		}
	}
	
	cout << dp[indx][n-1][0] << "\n";
	
	return 0;
}
