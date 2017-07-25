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
	int t;
	long long r, x1, y1, x2, y2, v;
	double res;
	sd(t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld",&r,&x1,&y1,&x2,&y2,&v);
		double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		res = 0;
		if(dist >= r){
			printf("%.6lf\n",res);
		}
		else{
			res = (double)(r - dist)/v;
			printf("%.7lf\n",res);
		}
	}
	return 0;
}
