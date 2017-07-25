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

int n, a;
long long sum;
int main(){
	cin>> n;
	for(long long i = 1; i <= n; i++){
		cin>>a;
		sum += (i*(a-1) +1);
	}
	
	cout<< sum << endl;
	return 0;
}
