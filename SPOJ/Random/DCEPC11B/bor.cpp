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
	int t, i, n, p, c;
	long long result, ans;
	sd(t);
	while(t--){
		scanf("%d %d",&n, &p);
		if(n >= p){
			printf("0\n");
			continue;
		}
		result = 1;
		for(i = n + 1; i < p; i++){
			result = (result*i)	%p;
		}
		c = p-2, ans = p-1;
		while(c){
			if(c&1) ans = (result*ans)%p;
			result = (result*result)%p;
			c >>= 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
