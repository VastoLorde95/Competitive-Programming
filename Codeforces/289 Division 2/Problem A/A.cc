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
	int n, m = 1, table[10][10];
	sd(n);
	for(int i = 0; i < n; i++){
		table[0][i] = table[i][0] = 1;
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			table[i][j] = table[i-1][j] + table[i][j-1];
			m = max(m, table[i][j]);
		}
	}
	cout<<m<<endl;
	return 0;
}
