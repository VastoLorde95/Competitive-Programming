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

int n, p[51], x, y, res[51][51];

int main(){
	cin>>n;
	for(int i = 0; i < ((n*(n-1))/2)-1; i++){
		cin>> x >> y;
		p[x]++;
		p[y]++;
		res[x][y] = 1;
		res[y][x] = -1;
	}
	
	for(int i = 1; i <= n; i++){
		if(p[i] != n-1){
			for(int j = 1; j <= n; j++){
				if(i != j and res[i][j] == 0){
					for(int k = 1; k <= n; k++){
						if(i != k and j != k){
							if(res[i][k] == 1 and res[j][k] == -1){
								cout << i << " " << j << endl;
								return 0;
							}
							else if( res[i][k] == -1 and res[j][k] == 1){
								cout << j << " " << i << endl;
								return 0;
							}
						}
					}
					
					cout<< i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
