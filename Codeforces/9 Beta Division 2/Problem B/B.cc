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

long long n, v1, v2, p, xs, ys;
long long x[100];
double mn = 0, dist, eps = 1e-9;
int main(){
	cin>> n >> v1 >> v2;
	for(int i = 0; i < n; i++){
		cin>> x[i];
	}
	cin>> xs >> ys;
	for(int i = 1; i < n; i++){
	
		double a = ((double)x[i])/((double)(v1));
		double b = (double)sqrt(((x[i]-xs)*(x[i]-xs)) + ((ys)*(ys)))/(double)(v2);	
		double d = (double)sqrt(((x[i]-xs)*(x[i]-xs)) + ((ys)*(ys)));
		
		if(mn == 0){
			mn = a+b;
			p = i;
			dist = d;
		}
		else if(fabs(a+b - mn) < eps){
			if(d < dist){
				dist = d;
				p = i;
			}
		}
		else if(a+b < mn){
			mn = a+b;
			p = i;
			dist = d;
		}
		
		//printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,mn,d);
	}
	
	cout<< p+1 << endl;
	return 0;
}
