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

int n, h[100000], res, hh;

int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(h[i]);
	res = h[0]+1;
	for(int i = 1; i < n; i++){
		hh = min(h[i], h[i-1]);
		res += (h[i-1] - hh) + 1;
		if(hh == h[i]){
			res++;
		}
		else{
			res += h[i]-h[i-1]+1;
		}
	}
	
	cout<< res <<endl;
	
	return 0;
}
