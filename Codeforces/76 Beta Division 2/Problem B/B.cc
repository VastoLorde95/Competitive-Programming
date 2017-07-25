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

int f[6][6], a, b, m;

int main(){
	sd(m);
	for(int i = 0; i < m; i++){
		sd2(a,b);
		f[a][b] = f[b][a] = 1;
	}	
	
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			for(int k = 1; k <= 5; k++){
				if( i != j and j != k and k != i){
					if( f[i][j] and f[j][k] and f[k][i]){
						cout<< "WIN\n";
						return 0;
					}
					
					if( !f[i][j] and !f[j][k] and !f[k][i]){
						cout<< "WIN\n";
						return 0;
					}
				}
			}
		}
	}
	
	cout<< "FAIL\n";
	
	return 0;
}
