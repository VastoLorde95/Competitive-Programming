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

int x, y, n, a, b;
double tmp, f1, f2, f3, mn = 1000000, eps = 1e-9;

int main(){
	sd3(x,y,n);
	
	f1 = ((double)(x)) / ((double)(y));
	
	//cout<< f1 << endl;
	
	for(int i = 1; i <= n; i++){
		tmp = ((double)(x))/((double)(y));
		tmp *= i;
		f2 = ((double)(ceil(tmp))) / ((double)(i));
		f3 = ((double)(floor(tmp))) / ((double)(i));
		
		//cout<< (int) ceil(tmp) << "/" << i << " = " << f2 << endl;
		//cout<< (int) floor(tmp) << "/" << i << " = " << f3 << endl;
		
		if(fabs(f1-f3) < mn and fabs(fabs(f1-f3) - mn) > eps){
			mn = fabs(f1-f3);
			a = (int) floor(tmp);
			b = i;
		}
		if(fabs(f1-f2) < mn and fabs(fabs(f1-f2) - mn) > eps){
			mn = fabs(f1-f2);
			a = (int) ceil(tmp);
			b = i;
		}
	
	}
	
	cout<< a << "/" << b << endl;
	
	return 0;
}
