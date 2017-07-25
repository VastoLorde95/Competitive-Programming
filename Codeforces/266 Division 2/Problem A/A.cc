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
	int n, m, a, b, c;
	double x;
	cin>> n >> m >> a >> b;
	x = (double)b/m;
	if(x >= a){
		cout<< n * a << endl;
	}
	else{
		c = (n/m)*b + min((n%m)*a, b);
		cout<< c <<endl;
	}
	
	return 0;
}
