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

int t, p[100000], n, a[100000], cnt;

int main(){
	sd(t);
	while(t--){
		sd(n);
		cnt = 0;
		for(int i = 0; i < n; i++){
			sd(a[i]);
			p[i] = 0;
		}		
		for(int i = 1; i < n; i++){
			if(a[i] != a[i-1]){
				if(p[i] == 0){
					p[i] = 1;
					cnt++;
				}
				
				if(p[i-1] == 0){
					p[i-1] = 1;
					cnt++;
				}
			}
		}
		
		printf("%d\n",cnt);
	}
	return 0;
}
