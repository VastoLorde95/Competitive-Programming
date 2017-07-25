// Modulo Sum
#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n, m, a[N];
int dp[2][N];

int main(){
	cin >> n >> m;
	if(n > m){
		printf("YES\n");
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] %= m;
	}
	
	int nxt = 0;
	for(int i = 0; i < n; i++){
		nxt ^= 1;
		for(int j = 0; j < m; j++){
			dp[nxt][j] = dp[1-nxt][j];
		}
		
		for(int j = 0; j < m; j++){
			if(dp[1-nxt][j] > 0) dp[nxt][(j+a[i])%m] = 1;
		}
		
		dp[nxt][a[i]] = 1;
	}
	
	if(dp[nxt][0] == 1) puts("YES"); else puts("NO");
	
	return 0;
}
