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

int n, m, d[3000];

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		sd(d[i]);
	}
	
	sort(d, d+m);
	
	if(d[0] == 1 or d[m-1] == n){
		printf("NO\n");
		return 0;
	}
	
	for(int i = 2; i < m; i++){
		if(d[i-2]+1 == d[i-1] and d[i-1] + 1 == d[i]){
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	
	return 0;
}
