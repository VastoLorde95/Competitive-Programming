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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int n, pos[1000], c, p, flag;
	sd(n);
	while(n){
		for(int i = 0; i < n; i++)
			pos[i] = 0;
		flag = 0;
		for(int i = 0; i < n; i++){
			sd2(c,p);
			if(i+ p < n and i + p >=0){
				if(pos[i+p] == 0)
					pos[i+p] = c;
				else
					flag = 1;
			}
			else
				flag = 1;
		}
		if(flag)
			printf("-1\n");
		else{
			for(int i = 0; i < n; i++)
				printf("%d ", pos[i]);		
			printf("\n");
		}
		sd(n);
	}
	return 0;
}
