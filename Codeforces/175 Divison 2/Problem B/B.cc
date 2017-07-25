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

int cur, n, s, t, cnt, pos[100001], visited[1000001];

int main(){
	sd3(n,s,t);
	for(int i = 1; i <= n; i++){
		sd(pos[i]);
	}
	
	if(s == t){
		printf("0\n");
		return 0;
	}
	
	cur = pos[s];
	visited[s] = 1;
	cnt = 1;
	
	while(true){
		if(visited[cur] == 1){
			printf("-1\n");
			return 0;
		}
		if(cur == t){
			printf("%d\n",cnt);
			return 0;
		}
		cur = pos[cur];
		cnt++;
	}	
	
	return 0;
}
