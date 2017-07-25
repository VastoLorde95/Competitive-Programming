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
	int n, num[1000][1000], a;
	sd(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sd(num[i][j]);
		}
	}
	if(n == 2){
		printf("%d %d\n",num[0][1]/2, num[0][1]/2);
	}
	else{
		a = (num[0][1] + num[0][2] - num[1][2])/2;
		printf("%d ", a);
		for(int i = 1; i < n; i++)
			printf("%d ", num[i][0] - a); 
		printf("\n");
	}
	return 0;
}
