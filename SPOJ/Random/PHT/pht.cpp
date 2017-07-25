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
	long long n, a, b;
	sd(t);
	for(int i = 1; i <= t; i++){
		scanf("%lld",&n);
		a = sqrt(n);
		b = (int)sqrt(n+1);
		if(b*b == n+1 or (b+1)*(b+1) == n+1)
			printf("Case %d: %lld\n",i, a);
		else
			printf("Case %d: %lld\n",i, a-1);
			
	}
	return 0;
}
