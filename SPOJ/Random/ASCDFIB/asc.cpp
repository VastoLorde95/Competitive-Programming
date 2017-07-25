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

int t, a, b, MOD = 100000, fib[1100001], s[100000], i, j;

int main(){
	int count;
	fib[1] = 0;
	fib[2] = 1;
	for(i = 3; i <= 1100000; i++){
		fib[i] = (fib[i-1] + fib[i-2])%MOD;
	}
	sd(t);
	for(j = 1; j <= t; j++){
		for(i = 0; i < MOD; i++)
			s[i] = 0;
		sd2(a,b);
		for(i = a; i <= a+b; i++)
			s[fib[i]]++;
		printf("Case %d:",j);
		b += 1;
		if (b > 100) b = 100;
		i = 0;
		while(i < 100000 and b){
			while(s[i] > 0 and b){
				printf(" %d",i);
				s[i]--;
				b--;
			}
			i++;
		}
		printf("\n");
	}
}
