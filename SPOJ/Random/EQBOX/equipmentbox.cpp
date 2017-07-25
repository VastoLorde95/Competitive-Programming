#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;


bool check(long long a, long long b, long long x, long long y)
{
	if (x < a && y < b) return true;
	if (x >= a && y >= b) return false;
	double beta = atan2(y, x);
	double alpha = asin(b / sqrt(x * x + y * y)) - beta;
	if (alpha < 0) return false;
	double p = y * sin(alpha), q = sqrt(x * x + y * y - b * b);
	if (2 * p + q - a >= 0) return false;
	else return true;
}
int main()
{
	int T, a, b, x, y;
	scanf("%d", &T);
	for (int ti = 0; ti < T; ++ti) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		if (check(max(a, b), min(a, b), max(x, y), min(x, y)))
			puts("Escape is possible.");
		else puts("Box cannot be dropped.");
}
}
