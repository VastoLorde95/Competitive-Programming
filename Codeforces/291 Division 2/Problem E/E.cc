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

long long MOD = 1000000007, a[101], dp[101], b[101][101], res[101][101], ans = 0;
int n, xx, d;

void mult(long long x[101][101], long long y[101][101], int flag){
	long long temp[101][101];
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			temp[i][j] = 0;
			for(int k = 0; k < 101; k++){
				temp[i][j] += (x[i][k] * y[k][j])%MOD;
				if(temp[i][j] >= MOD) temp[i][j] -= MOD;
			}
		}
	}
	if(flag == 0){
		for(int i = 0; i < 101; i++){
			for(int j = 0; j < 101; j++){
				res[i][j] = temp[i][j];	
			}
		}
	}
	else{
		for(int i = 0; i < 101; i++){
			for(int j = 0; j < 101; j++){
				b[i][j] = temp[i][j];	
			}
		}
	}
	return;
}

void exp(int n){
	for(int i = 0; i < 101; i++) res[i][i] = 1;
	while(n > 0){
		if(n&1) mult(res, b, 0);
		mult(b, b, 1);
		n >>= 1;
	}
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			b[i][j] = res[i][j];
		}	
	}
	return;
}


int main(){
	sd2(n, xx);	
	
	for(int i = 0; i < n; i++){
		sd(d);
		a[d]++;
	}
	
	dp[0] = 1;
	
	for(int i = 1; i <= 100; i++){
		for(int j = 0; j <= i; j++){
			dp[i] += (dp[i-j]*a[j])%MOD;
			if(dp[i] >= MOD) dp[i] -= MOD;
		}
	}
	
	for(int i = 1; i < 100; i++){
		b[i][i-1] = 1;
	}
	
	for(int i = 0; i < 100; i++){
		b[i][99] = b[i][100] = a[100-i];
	}
	
	b[100][100] = 1;

	if(xx <= 100){
		for(int i = 0; i <= xx; i++){
			ans += dp[i];
		}
		cout<< (ans)%MOD <<endl;
	}
	
	else{
		exp(xx-100);
		for(int i = 0; i < 100; i++){
			ans += (dp[i+1] * b[i][100])%MOD;
			if(ans >= MOD) ans -= MOD;
		}
		for(int i = 0; i <= 100; i++){
			ans += dp[i];
			if(ans >= MOD) ans -= MOD;
		}
		cout<< ans <<endl;
	}
	return 0;
}
