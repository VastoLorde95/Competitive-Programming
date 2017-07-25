#include <stdio.h>

#define MAXM 1010
#define MAXS 21

int N, M, S;

unsigned int tenpow[MAXS];
unsigned int dp[MAXS][MAXM];

int main(void){
	int i, j, k;

	scanf("%d", &N);

	while (N--){
		scanf("%d %d", &M, &S);

		if (S == 1){
			printf("%d\n", 9 / M);
			continue;
		}

		tenpow[0] = 1;
		for (i = 1; i < S; i++)
			tenpow[i] = (tenpow[i-1] * 10) % M;

		for (i = 0; i < S; i++)
			for (j = 0; j < M; j++)
				dp[i][j] = 0;

		for (i = (S+1)/2; i <= S; i++)
			dp[i][0] = 1;

		for (i = (S+1)/2 - 1; i >= 0; i--)
			for (j = 0; j < M; j++)
				for (k = i == 0; k <= 9; k++)
					dp[i][j] += dp[i+1][(j + k * (i != S-i-1 ? tenpow[i] + tenpow[S-i-1] : tenpow[i])) % M];

		printf("%u\n", dp[0][0]);
	}

	return 0;
}

