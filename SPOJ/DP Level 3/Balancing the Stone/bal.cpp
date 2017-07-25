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
	int t, N, L, D; long long W[1000000];
	long long dp[2][2];	// 0 means without carry, 1 means with carry
	string input;
	sd(t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		sd3(N,L,D);
		cin>>input;
		int i;
		for(i = 0; i < L; i++)
			W[L-i-1] = input[i] - '0';
		for(; i < N; i++){
			W[i] = 0;
		}
		int indx = 0;
		i = 0;
		while(W[i] == 0){
			i++;
		} 
		//cout<<i<<endl;
		dp[indx][0] = 1;
		dp[indx][1] = 1;
		i++;
		for(; i < N; i++){
			indx = 1 - indx;
			if(W[i] == 0){
			
				dp[indx][0] = dp[1-indx][0]; 
				dp[indx][1] = (i == N-1)?dp[1-indx][1] % D:(dp[1-indx][1] * 2) % D;
			}
			else{
				dp[indx][0] = dp[1-indx][0];
				dp[indx][1] = (i == N-1)?dp[indx][1]:(dp[1-indx][0] + dp[1-indx][1])%D;
			}
		//	cout<<<<W[i]<<endl;
		}
		cout<<(dp[indx][0] + dp[indx][1])%D<<endl;
	}	
	return 0;
}
