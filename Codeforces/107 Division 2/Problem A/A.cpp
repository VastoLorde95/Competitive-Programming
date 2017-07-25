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

using namespace std;

int main(){
	int n, k, l, c, d, p, nl, np;
	cin>> n >> k >> l >> c >> d >> p >> nl >> np;
	
	int a = k *l, b  = c*d, x = n*nl, y = n * np;
	cout<< min( a/x, min(b/n, p/y) )<<endl;
	return 0;
}
