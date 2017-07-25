#include <iostream>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);

using namespace std;

const int N = 501;

int n, a[N], dp[N][N];

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++) dp[i][i] = 1;
	
	for(int i = 1; i < n; i++) dp[i-1][i] = (a[i] == a[i-1])? 1 : 2;
	
	for(int i = 2; i < n; i++){
		for(int j = 0; j+i < n; j++){
			dp[j][j+i] = i+1;
			if(a[j] == a[j+i]) dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i-1]);
			
			for(int k = j; k <= j+i; k++) dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i]);
		}
	}
	
	cout << dp[0][n-1] << '\n';
	
	return 0;
}
