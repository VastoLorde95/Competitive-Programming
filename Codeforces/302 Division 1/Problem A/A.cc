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

int n, m, b, mod, a[501], dp[501][501], res;

int main(){	_
	cin >> n >> m >> b >> mod;
	
	dp[0][0] = 1;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int k = 1; k <= n; k++){
		for(int j = 1; j <= m; j++){
			for(int i = a[k]; i <= b; i++){
				dp[i][j] += dp[i-a[k]][j-1];
				if(dp[i][j] >= mod) dp[i][j] -= mod;
			}
		}
	}
	
	for(int i = 0; i <= b; i++){
		res += dp[i][m];
		if(res >= mod) res -= mod;
	}
	
	cout << res << endl;
	
	return 0;
}
