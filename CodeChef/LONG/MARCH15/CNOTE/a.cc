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
	int x, y, n, k, p, c, t, flag;
	sd(t);
	while(t--){
		scanf("%d%d%d%d",&x,&y,&k,&n);
		if(x <= y){
			flag = 1;
		}
		else{
			x -= y;
			flag = 0;
		}
		for(int i = 0; i < n; i++){
			sd2(p,c);
			if(c <= k and p >= x){
				flag = 1;
			}
		}
		
		if(flag == 1){
			printf("LuckyChef\n");
		}
		else{
			printf("UnluckyChef\n");
		}
	}
	return 0; 
}
