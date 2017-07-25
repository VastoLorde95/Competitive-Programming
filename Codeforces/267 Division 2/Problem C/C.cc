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

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

long long dp[2][5001], p[5001], sum[5001];

int n, m, k, indx;

int main(){
	_
	cin>> n >> m >> k;
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		cin>>p[i];
		sum[i] = p[i] + sum[i-1];
	}
	
	dp[0][0] = dp[1][0] = -1;
	
	for(int i = 1; i <= n; i++){
		if(i < m){
			dp[0][i] = dp[0][i-1];
		}
		else{
			dp[0][i] = max(dp[0][i-1], sum[i] - sum[i-m]);
		}
	}
	indx = 0;
	for(int i = 2; i <= k; i++){
		indx = 1 - indx;
		for(int j = 1; j <= n; j++){
			if(j < m){
				dp[indx][j] = dp[1-indx][j-1];
			}
			else{
				dp[indx][j] = max(dp[indx][j-1], dp[1-indx][j-m] + sum[j] - sum[j-m]);
			}
		}
	}
	//indx = 1 - indx;
	if(dp[indx][n] == -1) cout<<0<<endl;
	else cout<<dp[indx][n]<<endl;
	
	return 0;
}
