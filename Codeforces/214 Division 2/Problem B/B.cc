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

int n, k, a[100000], mn = 1000000000, res, s;

int main(){
	sd2(n,k);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	for(int i = 0; i < k; i++){
		s = a[i];
		int j = (i+k)%n;
		for(; j != i; (j += k) %= n){
			s += a[j];
		}
		
		if(s < mn){
			mn = s;
			res = i;
		}
	}	
	
	
	printf("%d\n",res+1);
	
	return 0;
}
