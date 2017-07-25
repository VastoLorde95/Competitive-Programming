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

int n, l, a[1000], mx;

int main(){
	cin>>n>>l;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}	
	sort(a, a+n);
	mx = 2*a[0];
	for(int i = 1; i < n; i++){
		mx = max(mx, a[i]-a[i-1]);
	}
	if(a[n-1] != l)
		mx = max(mx, 2*(l-a[n-1]));
	
	double res = (double)(mx)/2;
	
	printf("%lf\n",res);
	
	return 0;
}
