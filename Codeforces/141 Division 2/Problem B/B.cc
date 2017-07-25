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

int n1, n2, m1, m2, res, cnt, n, m, x, y;
int a[50][50], b[50][50];
string s;

int main(){
	sd2(n1,m1);
	for(int i = 0; i < n1; i++){
		cin>> s;
		for(int j = 0; j < m1; j++){
			a[i][j] = (int)(s[j]-'0');
		}
	}
	
	sd2(n2,m2);
	
	for(int i = 0; i < n2; i++){
		cin>> s;
		for(int j = 0; j < m2; j++){
			b[i][j] = (int)(s[j]-'0');
		}
	}
	
	n = max(n1, n2);
	m = max(m1, m2);
	
	for(int i = -n; i <= n; i++){
		for(int j = -m; j <= m; j++){
			cnt = 0;
			for(int k = 0; k < n1; k++){
				for(int l = 0; l < m1; l++){
					if(k+i >= 0 and k+i < n2  and l+j >= 0 and l+j < m2){
						//cout<< a[k][l] << " " << b[k+i][l+j] << endl;
						if(a[k][l] == b[k+i][l+j] and a[k][l] == 1){
							cnt++;
						//	cout<< "yo" << endl;
						}
					}
				}
			}
			
			//cout<< i << " " << j << " " << cnt << endl;
			
			if(cnt > res){
				res = cnt;
				x = i;
				y = j;
			}
			
		}
	}
	
	printf("%d %d\n",x, y);
	
	return 0;
}
