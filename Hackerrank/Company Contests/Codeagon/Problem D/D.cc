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

int n, m, x, y, z;
int dp[300][300][300];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd3(x,y,z);
		dp[101+x][101+y][101+z] += 1;
	}
	
	
	for(int i = -100; i <= 100; i++){
		for(int j = -100; j <= 100; j++){
			for(int k = -100; k <= 100; k++){
				if(k == -100) continue;
				dp[101+i][101+j][101+k] += dp[101+i][101+j][101+k-1];
			}
		}
	}
	
	
	for(int i = -100; i <= 100; i++){
		for(int j = -100; j <= 100; j++){
			for(int k = -100; k <= 100; k++){
				if(j == -100) continue;
				dp[101+i][101+j][101+k] += dp[101+i][101+j-1][101+k];
			}
		}
	}
	
//	for(int i = -100; i <= 100; i++){
//		for(int j = -100; j <= 100; j++){
//			for(int k = -100; k <= 100; k++){
//				if(k == -100) continue;
//				dp[101+k][101+i][101+j] += dp[101+k-1][101+i][101+j];
//			}
//		}
//	}
	
	
//	tr(dp[109][109][109]);	
	sd(m);
	while(m--){
		int x1, x2, y1, y2, z1, z2;
		sd3(x1,y1,z1);
		sd3(x2,y2,z2);
		x1 += 3;
		y1 += 3;
		z1 += 3;
		
//		tr6(x1,y1,z1,z2,y2,z2);
		
		if(x2-x1 < 0 or y2-y1 < 0 or z2-z1 < 0){
			printf("0\n");
		}
		else{
			int ans = 0;
			for(int i = x1; i <= x2; i++){
//				tr4(i,y2,z2,(dp[101+i][101+y2][101+z2] - dp[101+i][101+y2][101+z1-1] - dp[101+i][101+y1-1][101+z2] + dp[101+i][101+y1-1][101+z1-1]));
				ans += (dp[101+i][101+y2][101+z2] - dp[101+i][101+y2][101+z1-1] - dp[101+i][101+y1-1][101+z2] + dp[101+i][101+y1-1][101+z1-1]);
//				ans += (dp[101+i][101+y1][101+z1] - dp[101+i][101+y1][101+z2-1] - dp[101+i][101+y2-1][101+z1] + dp[101+i][101+y2-1][101+z2-1]);
			}
			printf("%d\n", ans);
		}
		
	}
	
	
	
	return 0;
}
