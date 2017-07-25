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
	int n, m, A[500][500], B[500][500], dp[500][500], temp;		//A and B are the cummulative sums of Y and B
	sd2(n,m);
	while(n > 0 and m > 0){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				sd(temp);
				A[i][j] = (j)? temp + A[i][j-1]: temp;
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				sd(temp);
				B[i][j] = (i)? temp + B[i-1][j]: temp;
			}
		}
		
		dp[0][0] = max(A[0][0], B[0][0]);
		
		for(int i = 1; i < m; i++)
			dp[0][i] = max(A[0][i], B[0][i] + dp[0][i-1]);
			
		for(int i = 1; i < n; i++)
			dp[i][0] = max(A[i][0] + dp[i-1][0], B[i][0]);
			
		for(int i = 1; i < n; i++)
			for(int j = 1; j < m; j++)
				dp[i][j] = max(A[i][j] + dp[i-1][j], B[i][j] + dp[i][j-1]);
		
		printf("%d\n", dp[n-1][m-1]);	
		sd2(n,m);	
	}
	return 0;
}
