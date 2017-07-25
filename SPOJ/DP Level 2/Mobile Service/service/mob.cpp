#include <stdio.h>

#define min(a, b) a<b ? a:b
#define max(a, b) a>b ? a:b
#define INF 1<<28

int main(){
	int t, n, m, i, j, k, idx;
	int c[200][200], DP[2][200][200], r[1000];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &c[i][j]);
				
		for(i = 0; i < m; i++){
			scanf("%d", &r[i]);
			r[i]--;
			}
			
		//Base Case
		idx = 0;
		for(j = 0; j < n; j++)
			for(k = j+1; k < n; k++)
				DP[0][j][k] = INF;
				
		for(j = 0; j < 3; j++)
			for(k = j+1; k < 3; k++)
				if(j != r[0] && k != r[0])
					DP[0][j][k] = c[3-j-k][r[0]];
					
		for(i = 1; i < m; i++){
			idx = 1 - idx;
			for(j = 0; j < n; j++)
				for(k = j+1; k < n; k++)
					DP[idx][j][k] = INF;
					
			for(j = 0; j < n; j++)
				for(k = j+1; k < n; k++)
					if(j != r[i] && k != r[i])
						DP[idx][j][k] = DP[1-idx][j][k] + c[r[i-1]][r[i]];
						
			for(j = 0; j < n; j++)
				for(k = j+1; k < n; k++){
				
					if(j != r[i] && r[i-1] != r[i] && j < r[i-1])
						DP[idx][j][r[i-1]] = min(DP[idx][j][r[i-1]], DP[1-idx][j][k]+c[k][r[i]]);
					else if(j != r[i] && r[i-1] != r[i] && j > r[i-1])
						DP[idx][r[i-1]][j] = min(DP[idx][r[i-1]][j], DP[1-idx][j][k]+c[k][r[i]]);
						
					if(k != r[i] && r[i-1] != r[i] && k < r[i-1])
						DP[idx][k][r[i-1]] = min(DP[idx][k][r[i-1]], DP[1-idx][j][k]+c[j][r[i]]);
					else if(k != r[i] && r[i-1] != r[i] && k > r[i-1])
						DP[idx][r[i-1]][k] = min(DP[idx][r[i-1]][k], DP[1-idx][j][k]+c[j][r[i]]);
						
					}
		}
		
		i = INF;
			for(j = 0; j < n; j++)
				for(k = j+1; k < n; k++)
					i=min(i, DP[idx][j][k]);
		printf("%d\n", i);
		}
	return 0;
	}
