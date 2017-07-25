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
	int n, s = 1, x, l[50], r[50], ans = 0;
	sd2(n,x);
	sd2(l[0],r[0]);
	ans += (r[0] - l[0] + 1);
	for(int i = 1; i < n; i++){
		sd2(l[i], r[i]);
		ans += ((l[i] - r[i-1] + 1)%x + (r[i] - l[i]));
	}
	cout<<ans<<endl;
	return 0;
}
