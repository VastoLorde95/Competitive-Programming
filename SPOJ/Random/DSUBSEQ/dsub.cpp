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
	int t, last[26], MOD = 1000000007, l;
	long long dp[100001];
	dp[0] = 1;
	string s;
	sd(t);
	while(t--){
		cin>>s;
		l = s.length();
		for(int i = 0; i < 26; i++)
			last[i] = -1;
		for(int i = 1; i <= l; i++){
			dp[i] = (dp[i-1]*2)%MOD;
			if(last[s[i-1] - 'A'] >= 0)
				dp[i] = (dp[i] - dp[last[s[i-1] - 'A'] - 1] + MOD)%MOD;
			last[s[i-1] - 'A'] = i;
		} 
		printf("%lld\n",dp[l]);
	}
	return 0;
}


