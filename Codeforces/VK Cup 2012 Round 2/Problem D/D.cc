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

int dp[2000], palin[2000][2000], l;	//number of palindromes ending <= i
long long res = 0, sum[2000];

int main(){
	string s;
	cin>>s;
	l = s.length();
	
	for(int i = 0; i < l; i++){
		dp[i] = 1;
		palin[i][i] = 1;
	}
	for(int i = 1; i < l; i++){
		if(s[i] == s[i-1]){
			dp[i]++;
			palin[i][i-1] = 1;
		}
	}
	for(int i = 2; i < l; i++){
		for(int j = i; j < l; j++){
			if(s[j] == s[j-i] and palin[j-1][j-i+1] == 1){
				dp[j]++;
				palin[j][j-i] = 1;
			}
		}
	}

	sum[0] = dp[0];
	for(int i = 1; i < l; i++){
		sum[i] = sum[i-1] + dp[i];
	}
	
	for(int i = 0; i < l; i++){
		for(int j = i; j < l; j++){
			if(palin[j][j-i] == 1){
				res += (j-i-1 >= 0)? sum[j-i-1]: 0;
			}
		}
	}
	
	cout<<res<<endl;
	return 0;
}
