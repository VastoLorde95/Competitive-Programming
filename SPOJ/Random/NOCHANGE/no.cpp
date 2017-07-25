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
	int x, k, values[5];
	sd2(x,k);
	bool dp[x+1];
	memset(dp, false,sizeof(dp));
	dp[0] = true;
	for(int i = 0; i < k; i ++){
		sd(values[i]);
		if(i>0)
			values[i] += values[i-1]; 
	}
	for(int i = 0; i < k; i++){
		for(int j = values[i]; j <= x; j++){
			dp[j] |= dp[j-values[i]];
		}  
	}
	if(dp[x] == true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

