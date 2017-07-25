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

int n, m, p, a, b, x, y, z, tickets[8], graph[31][31], INF = 10000000;

double dp[31][256], eps = 1e-9;

void calculate(){
	double time, ans = INF;
	int MASK = 1<<n;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < MASK; j++){
			dp[i][j] = INF;
		}
	}
	dp[a][0] = 0;
	for(int mask = 0; mask < MASK; mask++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				for(int ticket = 0; ticket < n; ticket++){
					if((mask>>ticket)&1 != 0) continue;
					if(graph[i][j] == INF) continue;
					if(abs(dp[i][mask]-INF) <= eps ) continue;
					time = dp[i][mask] + (graph[i][j]/(1.0*tickets[ticket]));
					if(dp[j][mask|(1<<ticket)] > time){
						dp[j][mask|(1<<ticket)] = time;
					}
				}
			}
		}
	}
	for(int mask = 0; mask < MASK; mask++){
		ans = min(ans, dp[b][mask]);
	}
	if(ans < INF-1)
		printf("%.6f\n",ans);
	else
		printf("Impossible\n");
	return;
}
	
int main(){
	sd3(n,m,p);
	sd2(a,b);
	while(n+m+p+a+b != 0){
		
		for(int i = 0; i < n; i++) sd(tickets[i]);
		
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				graph[i][j] = INF;
			}
		}		
				
		for(int i = 0; i < p; i++){
			sd3(x,y,z);
			graph[x][y] = z;
			graph[y][x] = z;
		}
		
		calculate();
		
		sd3(n,m,p);
		sd2(a,b);
	}
	return 0;
}
