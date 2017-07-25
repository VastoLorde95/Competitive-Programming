#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)

using namespace std;

const int N = 101;

int g[N][N], a, b, c, d;

inline void paint(int &x, int &y, int &dir, int tot, int col){
	while(tot > 0){
		if(g[x][y] != -1) tot--, g[x][y] = col;
		
		y += dir;
		if(y == 0) x--, y++, dir = -dir;
		else if(y == a+c+1) x--, y--, dir = -dir;
	}
}

int main(){
	sd2(a,b); sd2(c,d);
	
	bool swapped = false;

	if(b < d){
		swap(a,c); swap(b,d);
		swapped = true;
	}
	
	for(int i = d+1; i <= b; i++) fill(g[i]+a+1, g[i]+a+c+1, -1);
	
	int sx = b, sy = ((b-d) % 2 == 0)? 1 : a;
	int sdir = ((b-d) % 2 == 0)? 1 : -1;
	
	int n, x;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(x);
		paint(sx,sy,sdir,x,i);	
	}
	
	if(swapped) for(int i = 1; i <= b; i++) reverse(g[i]+1, g[i]+1+a+c);
	
	int mx = max(b,d);
	
	printf("YES\n");
	for(int i = 1; i <= mx; i++){
		for(int j = 1; j <= a+c; j++)
			printf("%c", (g[i][j] != -1)? (char)('a' + g[i][j] - 1) : '.');
		printf("\n");
	}
	
	return 0;
}
