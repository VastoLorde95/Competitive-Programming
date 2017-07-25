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

int main(){
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	if(r1+r2 <= d){
		double res = (double)(d-r1-r2)/2;
		printf("%.6lf\n",res);
	}
	else if(d <= abs(r1-r2)){
		double res = (double)(max(r1,r2)-d-min(r1,r2))/2;	
		printf("%.6lf\n",res);
	}
	else{
		printf("%lf\n",0.0);
	}
	
	return 0;
}
