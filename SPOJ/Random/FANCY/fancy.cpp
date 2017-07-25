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
	int t, dp[31], count;
	char c, p;
	long long ans;
	string inp;
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= 30; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			dp[i] += dp[i-j];
		}
	}
	sd(t);
	while(t--){
		cin>>inp;
		ans = 1;
		p = inp[0];
		count = 1;
		for(int i = 1; i < inp.length(); i++){
			c = inp[i];
			if(c == p){
				count++;
			}
			else{
				ans *= dp[count];
				count = 1;
				p = c;
			}
		}
		ans *= dp[count];
		printf("%lld\n",ans);
		
	}
	return 0;
}
