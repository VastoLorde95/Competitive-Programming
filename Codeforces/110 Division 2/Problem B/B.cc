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

int n;
int r[1000];
double pi = 3.1415926536f, a;

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>r[i];
	}
	
	sort(r, r+n);
	
	if(n%2 == 0){
		for(int i = 1; i < n; i+=2){
			a += pi*(r[i]*r[i] - r[i-1]*r[i-1]);
		}
	}
	else{
		a = pi*r[0]*r[0];
		for(int i = 2; i < n; i+=2){
			a += pi*(r[i]*r[i] - r[i-1]*r[i-1]);
		}
	}
	
	printf("%.6lf\n",a);
	return 0;
}
