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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int n, m, res, x, y;

int main(){
	sd2(n,m);
	res = min(n,m)+1;
	
	printf("%d\n", res);
	
	x = 0, y = m;
	
	for(int i = 0; i < res; i++){
		printf("%d %d\n",x, y);
		x++, y--;
	}	
	
	return 0;
}
