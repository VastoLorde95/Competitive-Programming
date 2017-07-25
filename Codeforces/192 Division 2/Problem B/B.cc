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

int n, m, c[1001], a, b;

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		c[i] = n-1;
	}
	
	for(int i = 0; i < m; i++){
		sd2(a,b);
		c[a]--;
		c[b]--;
	}
	
	for(int i = 1; i <= n; i++){
		if(c[i] == n-1){
			cout<<n-1<<endl;
			for(int j = 1; j <= n; j++){
				if(i != j){
					cout<<i<<" "<<j<<endl;
				} 
			}
			return 0;
		}
	}
	return 0;
}
