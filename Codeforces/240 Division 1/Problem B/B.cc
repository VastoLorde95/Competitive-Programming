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

long long dp[2001][2001], MOD = 1000000007, sum;
int n, k;

int main(){
	sd2(n,k);
	
	for(int i = 1; i <= n; i++){
		dp[1][i] = 1;
	}
	
	for(int i = 1; i < k; i++){
		for(int j = 1; j <= n; j++){
			for(int l = j; l <= n; l += j){
				(dp[i+1][l] += dp[i][j]) %= MOD;
			}
		}
	}
	
	for(int i = 1; i <= n; i++) (sum += dp[k][i]) %= MOD;
	
	tr(sum);
	
	return 0;
}
