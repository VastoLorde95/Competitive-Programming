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

long long a[3], res, mx;

int main(){
	
	for(int i = 0; i < 3; i++) cin>>a[i];
	
	sort(a, a+3);
	
	if(a[2] >= 2*(a[1]+a[0]))
		cout << a[0] + a[1] << "\n";
	else
		cout << (a[0]+a[1]+a[2])/3 << "\n";
	
	
	return 0;
}
