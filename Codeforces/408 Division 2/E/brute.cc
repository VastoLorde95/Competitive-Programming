#include <stdio.h>
 
int A[1005], B[1005];
int dp[2][1005][55][55];
 
int max(int a, int b){ return a > b ? a : b; }
 
int main(){
    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);
    if(k == 0){ printf("0"); return 0; }
    if(p > 2*((n+k-1)/k)) p = 2*((n+k-1)/k);
    int r;
    scanf("%d", &r);
    for(int i=0; i<r; i++){
        int x;
        scanf("%d", &x);
        A[x] = 1;
    }
    int s;
    scanf("%d", &s);
    for(int i=0; i<s; i++){
        int x;
        scanf("%d", &x);
        B[x] = 1;
    }
    for(int i=0; i<2; i++) for(int j=0; j<1005; j++) for(int k=0; k<55; k++) for(int p=0; p<55; p++) dp[i][j][k][p] = -1e9;
    dp[0][0][0][0] = 0;
    for(int i=1; i<=n; i++){
        int cur = i&1, prev = !cur;
        // A only
        // - From nothing
        for(int j=1; j<=p; j++) dp[cur][j][k-1][0] = max(dp[cur][j][k-1][0], dp[prev][j-1][0][0] + A[i]);
        // - From something
        for(int j=1; j<=p; j++) for(int a=0; a<k-1; a++) dp[cur][j][a][0] = max(dp[cur][j][a][0], dp[prev][j][a+1][0] + A[i]);
 
        // B only
        // - From nothing
        for(int j=1; j<=p; j++) dp[cur][j][0][k-1] = max(dp[cur][j][0][k-1], dp[prev][j-1][0][0] + B[i]);
        // - From something
        for(int j=1; j<=p; j++) for(int b=0; b<k-1; b++) dp[cur][j][0][b] = max(dp[cur][j][0][b], dp[prev][j][0][b+1] + B[i]);
 
        // A and B
        // - From some A
        for(int j=1; j<=p; j++) for(int a=0; a<k-1; a++) dp[cur][j][a][k-1] = max(dp[cur][j][a][k-1], dp[prev][j-1][a+1][0] + (A[i]|B[i]));
        // - From some B
        for(int j=1; j<=p; j++) for(int b=0; b<k-1; b++) dp[cur][j][k-1][b] = max(dp[cur][j][k-1][b], dp[prev][j-1][0][b+1] + (A[i]|B[i]));
        // - From some A and B
        for(int j=2; j<=p; j++) for(int a=0; a<k-1; a++) for(int b=0; b<k-1; b++) dp[cur][j][a][b] = max(dp[cur][j][a][b], dp[prev][j][a+1][b+1] + (A[i]|B[i]));
 
        // None
        for(int j=0; j<=p; j++) dp[cur][j][0][0] = max(dp[cur][j][0][0], dp[prev][j][0][0]);
 
        for(int j=0; j<=p; j++) for(int a=0; a<k; a++) for(int b=0; b<k; b++) dp[prev][j][a][b] = -1e9;
    }
    int res = -1e9;
    for(int i=0; i<=p; i++) for(int j=0; j<k; j++) for(int a=0; a<k; a++) res = max(res, dp[n&1][i][j][a]);
    printf("%d\n", res);
    return 0;
}

