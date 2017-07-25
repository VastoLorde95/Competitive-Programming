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


int t, n, k;
double dp[1001][1001], p[1001];

int main(){
	sd(t);
	for(int T = 1; T <= t; T++){
		sd2(n,k);
		for(int i = 1; i <= n; i++){
			scanf("%lf", p+i);
		}
		
		dp[0][0] = 1;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= k; j++){
				dp[i][j] = dp[i-1][j]*(1-p[i]);
				if(j > 0)
					dp[i][j] += dp[i-1][j-1]*p[i];
//				tr3(i,j,dp[i][j]);
			}
		}
		
		printf("Case %d: %.2lf\n", T, dp[n][k]);

	}
	return 0;
}
