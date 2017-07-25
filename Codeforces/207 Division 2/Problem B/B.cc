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

int n, m, col[100001], a, b, c;

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd3(a,b,c);
		if(col[a] == 0 and col[b] == 0 and col[c] == 0){
			col[a] = 1;
			col[b] = 2;
			col[c] = 3;
		}
		else if(col[a] > 0){
			if(col[a] == 1){
				col[b] = 2;
				col[c] = 3;
			}
			else if(col[a] == 2){
				col[b] = 1;
				col[c] = 3;
			}
			else if(col[a] == 3){
				col[b] = 1;
				col[c] = 2;
			}
		}
		
		else if(col[b] > 0){
			if(col[b] == 1){
				col[a] = 2;
				col[c] = 3;
			}
			else if(col[b] == 2){
				col[a] = 1;
				col[c] = 3;
			}
			else if(col[b] == 3){
				col[a] = 1;
				col[c] = 2;
			}
		}
		
		else if(col[c] > 0){
			if(col[c] == 1){
				col[b] = 2;
				col[a] = 3;
			}
			else if(col[c] == 2){
				col[b] = 1;
				col[a] = 3;
			}
			else if(col[c] == 3){
				col[b] = 1;
				col[a] = 2;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(col[i] == 0) printf("1 ");
		else printf("%d ",col[i]);
	}
	
	return 0;
}
