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

int n, m, grid[25][25], mx;
string s;

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			grid[i][j] = s[j]-'0';
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int x = 0; x <= n-i; x++){
				for(int y = 0; y <= m-j; y++){
					int flag = 1;
					
					for(int a = x; a < x+i; a++){
						for(int b = y; b < y+j; b++){
							//if(i == 4 and  j == 4){
							//	cout<< a << " " << b << endl;
							//}
							if(grid[a][b] == 1){
								flag = 0;
								a = n;
								b = n;
								break;
							}
						}
					}
					
					if(flag){
						///cout<< i << " " << j << endl;
					 	mx = max(mx, i+i+j+j);
					 	x = n;
					 	y = n;
					 	break;
					}
				}
			}
		}
	}
	
	cout << mx << endl;
	
	return 0;
}
