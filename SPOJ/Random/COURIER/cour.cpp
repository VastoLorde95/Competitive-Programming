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

int t, n, m, b, graph[101][101],u, v, num, coun, d, z, MASK, dp[1<<12][101], orders[12][2], INF = 10001;

int tsp(int prev, int mask){
	if(dp[mask][prev] < INF) return dp[mask][prev];
	
	int dist = INF, flag = 0;
	for(int i = 0; i < coun; i++){
		if(!(mask & (1<<i))){
			flag = 1;
			dist = min(dist, graph[prev][orders[i][0]] + graph[orders[i][0]][orders[i][1]] + tsp(orders[i][1], mask | (1<<i)));
		}
	}
	if(!flag){
		dp[mask][prev] = graph[prev][b];
		return dp[mask][prev];
	}
	dp[mask][prev] = dist;
	return dist;
}

int main(){
	sd(t);
	while(t--){
		sd3(n,m,b);
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				graph[i][j] = 10001;
			}
			graph[i][i] = 0;
		}
		
		for(int i = 0; i < m; i++){
			sd3(u,v,d);
			graph[u][v] = min(graph[u][v], d);
			graph[v][u] = graph[u][v];
			
		}
		
		//Floyd-Warshall Algorithm
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					//if(graph[i][j] > graph[i][k] + graph[k][j]){
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					//}
				}
			}
		}
		
		sd(z);
		coun = 0;

		for(int i = 0; i < z; i++){
			sd3(u,v,num);
			while(num--){
				orders[coun][0] = u;
				orders[coun][1] = v;
				coun++;
			}
		}
		/*for(int i = 0; i < 1<<n; i++){
			for(int j = 0; j < n; j++){
				dp[i][j] = INF;
			}
		}*/
		memset(dp, INF, sizeof(dp));
				
		cout<<tsp(b, 0)<<endl; //Travelling salesman problem
		
	}
	return 0;
}

