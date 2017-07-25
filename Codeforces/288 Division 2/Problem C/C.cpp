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
#define print(x) printf("%d\n",x);
using namespace std;

int main(){
	int m, t, r, w, tot = 0, dp[1000], cnt, add;
	memset(dp, 0, sizeof(dp));
	sd3(m,t,r);
	if(r > t){
		print(-1);
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		sd(w);
		cnt = add = 0;
		for(int i = 400 + w-1; i >= 400 + w-t; i--){
			if(dp[i] == 1){
				cnt++;
			}
		}
		if(cnt >= r){
			continue;
		}
		for(int i = 400 + w-1; i >= 400 + w-t and cnt < r; i--){
			if(dp[i] != 1){
				cnt++;
				add++;
				dp[i] = 1;
			}	
		}
		if(cnt < r){
			print(-1);
			return 0;
		}	
		tot += add;
	}
	print(tot);
	
	
	return 0;
}
