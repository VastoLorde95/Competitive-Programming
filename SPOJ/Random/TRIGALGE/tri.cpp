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
	double x, a, b, c;
	sd(t);
	while(t--){
		scanf("%lf %lf %lf",&a,&b,&c);
		x = c/a;
		for(int i = 0; i < 10; i++){
			x = x - (((a*x) + (b*sin(x)) - c)/(a+(b*cos(x))));
		}
		printf("%.6lf\n",x);
	}
	return 0;
}
