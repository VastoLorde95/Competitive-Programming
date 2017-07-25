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

using namespace std;

int n, d, dp[30002][500], gems[30002], p, res, last = -1;

int main(){
	memset(dp, -1, sizeof dp);
	memset(gems, 0, sizeof gems);
	sd2(n,d);
	for(int i = 0; i < n; i++){
		sd(p);
		if(p >= d){
			last = max(last, p);
			gems[p]++;
		}
	}
	res = dp[d][250] = gems[d];
	for(int i = d; i <= last; i++){
		for(int j = 0; j <= 500; j++){
			if(dp[i][j] >= 0){
				res = max(res, dp[i][j]);
				if(d+j-250-1 > 0 and i+d+j-250-1 <= last){
					dp[i+d+j-250-1][j-1] = max(dp[i+d+j-250-1][j-1], gems[i+d+j-250-1] + dp[i][j]);
				}
				if(i+d+j-250 <= last){
					dp[i+d+j-250][j] = max(dp[i+d+j-250][j], gems[i+d+j-250] + dp[i][j]);
				}
				if(i+d+j-250+1 <= last){
					dp[i+d+j-250+1][j+1] = max(dp[i+d+j-250+1][j+1], gems[i+d+j-250+1] + dp[i][j]);
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
