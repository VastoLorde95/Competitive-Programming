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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	

int main(){
	int x1, y1, x2, y2, n, ans = 0;
	long long a, b, c, r1, r2;
	sd2(x1,y1);
	sd2(x2,y2);
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		r1 = (a*x1) + (b*y1) + c;
		r2 = (a*x2) + (b*y2) + c;
		if((r1 > 0 and r2 < 0) or ( r1 < 0 and r2 > 0)){
			ans++;
		} 
	} 
	cout<<ans<<endl;
	return 0;
}
