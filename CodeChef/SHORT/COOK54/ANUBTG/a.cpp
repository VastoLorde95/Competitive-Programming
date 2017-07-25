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
	int t, n, prices[1000], res;
	sd(t);
	while(t--){
		sd(n);
		res = 0;
		for(int i = 0; i < n; i++){
			sd(prices[i]);
		}
		sort(prices, prices+n);
		for(int i = n-1; i >= 0; i--){
			res += prices[i];
			if(i != 0){
				i--;
				res += prices[i];
			}
			i -= 2;
		}
		printf("%d\n",res);
		
	}
	return 0;
}
