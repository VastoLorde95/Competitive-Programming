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

int m, n, t[50001][5], a[50000][5];

int main(){
	sd2(m,n);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			sd(a[i][j]);
		}
	}
	
	t[0][0] = 0;
	
	for(int i = 1; i < n; i++){
		t[0][i] = t[0][i-1] + a[0][i-1];
	}
	
	for(int i = 1; i <= m; i++){
		t[i][0] = t[i-1][0] + a[i-1][0];
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			t[j][i] = max(t[j-1][i], t[j][i-1]) + a[j-1][i];
		}
	}
	
	for(int i = 1; i <= m; i++)
		cout<< t[i][n-1] << " ";
	cout<<endl;
	return 0;
}
