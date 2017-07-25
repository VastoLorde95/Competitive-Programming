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

long long a, b, res;

int main(){
	res = 0;
	cin>> a >> b;
	while(true){
		res += a/b;
		a %= b;
		if(a < b) swap(a,b);
		if(a == 0 or b == 0) break;
	}
	cout<< res << endl;
	return 0;
}
