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

int n, b, a, mn, res;

int main(){
	sd3(n,b,a);
	res = b, mn = a;
	for(int i = 1; i < n; i++){
		sd(a);
		res = max(res, (b/mn)*a + b%mn);
		mn = min(mn, a);
	}
	
	printf("%d\n",res);
	
	return 0;
}
