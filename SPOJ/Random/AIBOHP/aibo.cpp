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
#include<sstream>

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
	string s1;
	int t, dp[2][6101], l, indx;
	sd(t);
	while(t--){
		cin>>s1;
		l = s1.length();
		for(int i = 0; i <= l; i++){
			dp[0][i] = 0;
		}
		indx = 0;
		for(int i = 1; i <= l; i++){
			indx = 1 - indx;
			for(int j = 1; j <= l; j++){
				if(s1[i-1] == s1[l-j]){
					dp[indx][j] = dp[1-indx][j-1] + 1;
				}
				else{
					dp[indx][j] = max(dp[1-indx][j], dp[indx][j-1]);
				}
			}
		}	
		cout<<l - dp[indx][l]<<endl;
	}
	return 0;
}
