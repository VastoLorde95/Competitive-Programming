//implemented with bitmasks and an iterative approach

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

int n, l[300], c[300], m[300], temp, s, INF = 1000000000, res, dp[1<<9];
vector<int> factors;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++) sd(l[i]);
	for(int i = 0; i < n; i++) sd(c[i]);
	
	res = INF;
	
	for(int i = 0; i < n; i++){
		factors.clear();
		temp = l[i];
		
		for(int j = 2; j*j <= temp; j++){
			if(temp % j == 0){
				factors.push_back(j);
				while(temp % j == 0) temp /= j;
			}
		}
		if(temp > 1) factors.push_back(temp);
		
		s = factors.size();
		for(int j = 0; j < n; j++){
			m[j] = 0;
			for(int k = 0; k < s; k++){
				if(l[j] % factors[k] != 0){
					m[j] |= (1<<k);
				}
			}
		}
		
		for(int mask = 0; mask < (1<<s); mask++){
			dp[mask] = INF;
		}
		
		dp[m[i]] = c[i];
		
		for(int mask = 0; mask < (1<<s); mask++){
			for(int j = 0; j < n; j++){
				if(dp[mask] != INF)
					dp[mask | m[j]] = min(dp[mask | m[j]], dp[mask] + c[j]);
			}
		}
		
		res = min(res, dp[(1<<s)-1]);
		
	}
	
	if(res == INF)
		 cout<< -1 <<endl;
	else
		cout<< res <<endl;
	
	return 0;
}
