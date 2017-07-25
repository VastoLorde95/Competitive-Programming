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
	int t;
	long long a, b, sum, diff, n;
	sd(t);	
	while(t--){
		scanf("%lld %lld %lld", &a, &b, &sum);
		n = (sum*2)/(a+b);
		diff = (b-a)/(n-5);
		a = a - 2*diff;
		printf("%lld\n%lld ",n,a);
		for(long long i = 1; i < n; i++){
			a += diff;
			printf("%lld ",a);
		}
		printf("\n");
	}
	return 0;
}
