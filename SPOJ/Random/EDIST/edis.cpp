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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int t,temp, dp[2][2001], l1, l2, indx;
	
	string a, b;
	sd(t);
	while(t--){
		cin>>a;
		cin>>b;
		l1 = a.length();
		l2 = b.length();
		
		indx = 0;
		
		temp = min(l1,l2);
		l1 = max(l1,l2);
		l2 = temp;
		for(int i = 0; i <=  l2; i++){
			dp[0][i] = i;
		}
		for(int i = 1; i <= l1; i++){
			indx = 1-indx;
			for(int j = 0; j <= l2; j++){
				if(j == 0){
					dp[indx][j] = i;
				}
				else if(a[i-1] == b[j-1]){
					dp[indx][j] = dp[1-indx][j-1];
				}
				else{
					dp[indx][j] = min(min(dp[1-indx][j],dp[indx][j-1]),dp[1-indx][j-1]) + 1;
				}
			}
		}
		printf("%d\n",dp[indx][l2]);
		
	}	
	return 0;
}
