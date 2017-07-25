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

int tree[1024][1024], mat[1024][1024], N;

void add(int x, int y, int value){
	for (int i = x; i < N; i |= i + 1)
		for (int j = y; j < N; j |= j + 1)
			tree[i][j] += value;
}

int sum(int x, int y){
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			res += tree[i][j];
	return res;
}

int main(){
	int T, x1, y1, x2, y2;
	
	sd(T);

	while(T--){
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				tree[i][j] = mat[i][j] = 0;

		char cmd[10];
		
		while (scanf(" %s", cmd) == 1 && cmd[0] != 'E') {
		
			if (cmd[1] == 'E'){
				int x, y, num;
				scanf("%d %d %d", &x, &y, &num);
				if (mat[x][y] != num){
					add(x, y, num-mat[x][y]);
					mat[x][y] = num;
				}
			}
			else{
			
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			
			printf("%d\n", sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
			}
		}
	}
}
