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
	int n, i, temp, nodes[1000000], ans;
	int l1;
	sd(n);
	while(n){
		for(i = 0; i < n; i++){
			sd(nodes[i]);
		}
		temp = n, i = 1, ans = 0;
		while(i < temp){
			temp -= i;
			i = i << 1;
		}
		if(i > 1) i = i >> 1;
		
		l1 = i - (temp+1)/2;
		
		for(i = n-temp; i < n; i++){
			ans += nodes[i];
		}
		for(i = 1; i <= l1; i++){
			ans += nodes[n-temp-i];
		}
		printf("%d\n",ans);
		sd(n);
	}
	return 0;
}
