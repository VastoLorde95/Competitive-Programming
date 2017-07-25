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

int n1, n2, k1, k2;
long long dp[101][101][201][2], MOD = 100000000;

int main(){ _
	cin >> n1 >> n2 >> k1 >> k2;
	
	for(int i = 1; i <= min(n1,k1); i++)
		dp[i][0][i][0] = 1;
	for(int i = 1; i <= min(n2,k2); i++)
		dp[0][i][i][1] = 1;
	
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			for(int k = max(i+j-k1,1); k < i+j; k++){
				if(k-j >= 0) (dp[i][j][i+j][0] += dp[k-j][j][k][1]) %= MOD;
			}
			for(int k = max(i+j-k2,1); k < i+j; k++){
				if(k-i >= 0) (dp[i][j][i+j][1] += dp[i][k-i][k][0]) %= MOD;
			}
		}
	}
	
	cout << (dp[n1][n2][n1+n2][0] + dp[n1][n2][n1+n2][1]) %MOD << endl;

	return 0;
}
