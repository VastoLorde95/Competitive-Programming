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

int n, a[1000], mn = 2000;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	mn = min(mn, min(a[0], a[n-1]));
	
	for(int i = 2; i < n-1; i++){
		mn = min(mn, max(a[i], a[i-1]));
	}
	
	printf("%d\n", mn);
	
	return 0;
}
