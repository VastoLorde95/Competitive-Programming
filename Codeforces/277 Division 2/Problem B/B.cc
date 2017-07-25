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

int m, n, b[100][100], a[100][100], c[100][100];

int main(){
	sd2(m,n);
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			sd(b[i][j]);
			a[i][j] = 1;
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j] == 0){
				for(int k = 0; k < n; k++){
					a[i][k] = 0;
				}	
				for(int k = 0; k < m; k++){
					a[k][j] = 0;
				}
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(a[k][j] == 1){
					c[i][j] = 1;
				}
			}
			
			for(int k = 0; k < n; k++){
				if(a[i][k] == 1){
					c[i][j] = 1;
				}
			}
		}
	}
	
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j] != c[i][j]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"YES\n";
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
