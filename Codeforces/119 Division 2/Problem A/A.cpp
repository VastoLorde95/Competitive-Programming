// Cut Ribbon
#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, dp[4001];

int main(){
	cin >> n >> a >> b >> c;
	
	// base case
	dp[a] = dp[b] = dp[c] = dp[n] = 1;
	
	for(int i = 1; i <= n; i++){
		if(i >= a and dp[i-a] > 0)
			dp[i] = max(dp[i], dp[i-a] + 1);
		if(i >= b and dp[i-b] > 0)
			dp[i] = max(dp[i], dp[i-b] + 1);
		if(i >= c and dp[i-c] > 0)
			dp[i] = max(dp[i], dp[i-c] + 1);
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
