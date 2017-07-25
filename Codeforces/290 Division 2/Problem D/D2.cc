//implemented by computing all possible gcd

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

int n, a[300], b[300], temp;
map<int, int> dp;

void init(){
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(map<int, int>::iterator it = dp.begin(); it != dp.end(); it++){
			temp = __gcd(a[i], (*it).first);
			if(dp.find(temp) != dp.end()) dp[temp] = min(dp[temp], (*it).second + b[i]);
			else dp[temp] = b[i] + (*it).second; 
		}
	}
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	for(int i = 0; i < n; i++){
		sd(b[i]);
	}
	init();
	if(dp.find(1) == dp.end()){
		cout<<-1<<endl;
		return 0;
	}
	cout<<dp[1]<<endl;
	return 0;
}
