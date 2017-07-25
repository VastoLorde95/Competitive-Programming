#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

double dp[102][102][102], res;
int r, s, p;

int main(){
	sd3(r,s,p);
	
	dp[r][s][p] = 1.0;
	
	for(int i = r; i >= 0; i--){
		for(int j = s; j >= 0; j--){
			for(int k = p; k >= 0; k--){
				int d = (i*j) + (j*k) + (k*i);
				if(d == 0) continue;
				if(i-1 >= 0){
					double p = (double)(i*k)/((double)(d));
					dp[i-1][j][k] += dp[i][j][k]*p;
				}
				if(j-1 >= 0){
					double p = (double)(i*j)/((double)(d));
					dp[i][j-1][k] += dp[i][j][k]*p;
				}
				if(k-1 >= 0){
					double p = (double)(j*k)/((double)(d));
					dp[i][j][k-1] += dp[i][j][k]*p;
				}
			}
		}
	}
	
	for(int i = 1; i <= r; i++){
		res += dp[i][0][0];
	}
	printf("%.17lf ", res);
	
	res = 0;
	for(int i = 1; i <= s; i++){
		res += dp[0][i][0];
	}
	printf("%.17lf ", res);
	
	res = 0;
	for(int i = 1; i <= p; i++){
		res += dp[0][0][i];
	}
	printf("%.17lf\n", res);
	return 0;
}
