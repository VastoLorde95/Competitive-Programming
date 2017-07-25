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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int t, l, flag, visited[30], i, j;
	string inp;
	sd(t);
	while(t--){
		cin>>inp;
		l = inp.length(), flag = 1;
		i = 0, j = l-1;
		while(i < j){
			if(inp[i] != inp[j]){
				if(flag){
					if(inp[i] == inp[j-1]){
						flag = 0;
						j--;
					}
					else if(inp[i+1] == inp[j]){
						flag = 0;
						i++;
					}
					else{
						flag = 2; 
						i = l;
					}
				}
				else{
					flag = 2;
					i = l;
				}
			}
			i++; j--;
		}
		
		if(flag == 1 or flag == 0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	
}
