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

int n, k, a[100001];

int main(){
	sd2(n, k);
	for(int i = 1; i <= n+n; i++){
		a[i] = i;
	}
	
	int j = 1;
	
	for(int i = 0; i < k; i++){
		swap(a[j], a[j+2]);
		j += 4;
	}
	
	for(int i = 1; i <= n+n; i++){
		printf("%d ",a[i]);
	}
	
	printf("\n");
	return 0;
}
