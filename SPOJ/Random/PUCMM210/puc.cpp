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

long long sum[1000001], MOD = 1000000003;

int main(){
	int t, n;
	long long temp;
	sum[1] = 1;
	for(long long i = 2; i <= 1000000; i++){
		temp = ((i*(i+1))/2)%MOD;
		sum[i] = (sum[i-1] + (temp*temp)%MOD)%MOD;
	}
	sd(t);
	while(t--){
		sd(n);
		printf("%lld\n",sum[n]);
	}
	return 0;
}
