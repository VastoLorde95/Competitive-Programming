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
	int n, d[101], a, b, res = 0;
	sd(n);
	for(int i = 1; i < n; i++){
		sd(d[i]);
	}
	sd2(a,b);
	for(int i = a; i < b; i++){
		res += d[i];
	}
	
	cout<< res <<endl;
	return 0;
}
