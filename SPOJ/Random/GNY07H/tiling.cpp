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
	int n, w;
	int a[101], b[101], c[101];
	sd(n);
	a[0] = 1;
	a[1] = 1;
	b[0] = 0;
	b[1] = 1;
	c[0] = 0;
	c[1] = 1;
	
	for(int i = 2; i <= 100; i++){
		a[i] = a[i-1] + a[i-2] + b[i-1] + 2*c[i-1];
		b[i] = a[i-1] + b[i-2];
		c[i] = a[i-1] + c[i-1];
	}
	for(int i = 1; i <= n; i++){
		sd(w);
		printf("%d %d\n",i,a[w]);
	}
	return 0;
}
