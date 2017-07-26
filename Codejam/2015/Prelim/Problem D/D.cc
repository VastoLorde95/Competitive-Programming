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

int t, x, r, c;

int main(){
	sd(t);
	for(int T = 1; T <= t; T++){
		sd3(x,r,c);
		if(x == 1)
			printf("Case #%d: GABRIEL\n",T);
		else if(x == 2){
			if((r*c)%2 == 0)
				printf("Case #%d: GABRIEL\n",T);
			else
				printf("Case #%d: RICHARD\n",T);
		}
		else if(x == 3){
			if((r == 2 and c == 3) or (r == 3 and c == 2) or (r == 3 and c == 3) or (r == 3 and c == 4) or ( r == 4 and c == 3))
				printf("Case #%d: GABRIEL\n",T);
			else
				printf("Case #%d: RICHARD\n",T);				
				
		}
		else{
			if((r == 4 and c == 3) or (r == 3 and c == 4) or ( r == 4 and c == 4))
				printf("Case #%d: GABRIEL\n",T);
			else
				printf("Case #%d: RICHARD\n",T);
		}
	}
	return 0;
}
