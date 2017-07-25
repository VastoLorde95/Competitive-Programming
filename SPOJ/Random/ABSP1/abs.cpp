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
	int t, n, fact;
	long long nums[10000], sum[10000], total;
	sd(t);
	while(t--){
		sd(n);
		if(n == 0 or n == 1){
			printf("0\n");
			continue;
		}
		for(int i = 0; i < n; i++){
			scanf("%lld",&nums[i]);
		}
		sum[n-1] = nums[n-1];
		for(int i = n-2; i >= 0; i--){
			sum[i] = sum[i+1] + nums[i];
		}
		total = 0;
		for(int i = 0; i < n-1; i++){
			total += abs((n-i-1)*nums[i] - sum[i+1]);
		}
		printf("%lld\n",total);
	}
	return 0;
}
