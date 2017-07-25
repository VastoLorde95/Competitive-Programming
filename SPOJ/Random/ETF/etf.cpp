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
#include<queue>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int fi(int n){
	int result = n;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			result -= result/i;
			while(n%i == 0) n /= i;
		}
	}
	if(n > 1) result -= result/n;
	return result;
}


int main(){
	int t, n;
	sd(t);
	while(t--){
		sd(n);
		printf("%d\n",fi(n));
	}
}
