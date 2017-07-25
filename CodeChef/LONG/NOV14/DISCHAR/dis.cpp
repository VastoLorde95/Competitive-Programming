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
	int t, l, count, visited[30];
	string inp;
	sd(t);
	while(t--){
		memset(visited, 0, sizeof(visited));
		cin>>inp;
		l = inp.length(), count = 0;
		for(int i = 0; i < l && count <= 25; i++){
			if(visited[inp[i] -'a'] == 0){
				count++;
				visited[inp[i] -'a'] = 1;
			}
		}
		printf("%d\n",count);
	}
	
}
