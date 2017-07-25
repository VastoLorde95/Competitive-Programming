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

int n, w[170][170];
double a[170][170], b[170][170];

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>w[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = (double)(w[i][j] + w[j][i])/2;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b[i][j] = (double)w[i][j] - a[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%.6lf ", a[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%.6lf ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
