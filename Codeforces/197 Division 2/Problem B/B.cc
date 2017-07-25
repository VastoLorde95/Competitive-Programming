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

long long n, m, res, a, prev = 1;

int main(){
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		cin>>a;
		res += (a-prev+n)%n;
		prev = a;
	}	
	
	cout<< res << endl;
	
	return 0;
}
