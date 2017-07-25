#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int t, h, w, temp;
	cin>>t;
	while(t--){
		scanf("%d %d", &h, &w);
		int dp[h][w], maxi = 0;
		for(int i = 0; i < w; i++)
			scanf("%d",&dp[0][i]);
		if(h > 1){
			if(w>=2){
				for(int i = 1; i < h; i++){
					scanf("%d",&temp);
					dp[i][0] = max(dp[i-1][0] + temp, dp[i-1][1] + temp);
					for(int j = 1; j < w-1; j++){
						scanf("%d",&temp);
						dp[i][j] = max(max(dp[i-1][j-1] + temp, dp[i-1][j] + temp), dp[i-1][j+1] + temp);
					}
					scanf("%d",&temp);
					dp[i][w-1] =  max(dp[i-1][w-1] + temp, dp[i-1][w-2] + temp);
				}// End of taking inputs. dp[h-1] contains the answer
				for(int i = 0; i < w; i++)
					if(dp[h-1][i] > maxi)
						maxi = dp[h-1][i];
				
			}
			else{
				maxi = dp[0][0];
				for( int i = 1; i< h; i++){
					scanf("%d",&temp);
					maxi += temp;
				}
			}
		}
		else{
			for(int i = 0; i < w; i++)
				if(dp[h-1][i] > maxi)
					maxi = dp[h-1][i];
		}
		cout<<maxi<<endl;
		
	}
	return 0;
}
