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

int a, b, c, d;
double p1, p2, res;

int main(){
	cin>>a>>b>>c>>d;
	p1 = (double)(a)/(double)b;
	p2 = (double)c/(double)d;
	res = p1*(1.0/(1.0 - ((1.0-p1)*(1.0-p2)) ));
	printf("%.7lf\n",res);
	return 0;
}
