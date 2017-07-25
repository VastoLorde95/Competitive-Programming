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

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

long long n, cnt[100001], a, dp[1000001], mx, tmp1, tmp2;

int main(){
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;		
		mx = max(mx, a);
	}
	
	dp[1] = cnt[1];
	dp[2] = 2*cnt[2];
	
	tmp1 = dp[1];
	tmp2 = dp[2];
	
	for(long long i = 3; i <= mx; i++){
		dp[i] = tmp1 + (i*cnt[i]);
		tmp1 = max(tmp1, tmp2);
		tmp2 = max(tmp2, dp[i]);
	}
	
	a = mx;
	mx = 0;
	
	for(int i = 1; i <= a; i++){
		mx = max(mx, dp[i]);
	}
	
	cout << mx << "\n";
	
	return 0;
}
