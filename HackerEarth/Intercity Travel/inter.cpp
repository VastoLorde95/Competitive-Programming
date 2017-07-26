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


using namespace std;

long long MOD = 1000000007, A[51][51], R[10][51][51];
int r, n;

void mult(long long (&A)[51][51], long long (&B)[51][51]){
	long long C[51][51], val;
	memset(C, 0, sizeof(C));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			val = 0;
			for(int k = 1; k <= n; k++){
			val += (A[i][k] * B[k][j]) % MOD;
			}
			C[i][j] = (val) % MOD;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			A[i][j] = C[i][j];
	return;
}

long long expo(int row, int col, int len){
	long long ans[51][51], H[51][51];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			ans[i][j] = (i==j)? 1:0;
			H[i][j] = A[i][j];
		}
	
	while(len > 0){
		if(len%2 == 0){
			mult(H,H);
			len = len>>1;
		}
		else{
			mult(ans, H);
			mult(H,H);
			len = (len-1)>>1;
		}
	}
	return ans[row][col];
}

void init(){
	long long val;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				val = 0;
				for(int m = 1; m <= n; m++){
				val += (R[i-1][j][m] * A[m][k]);
				}
				R[i][j][k] = (val)%MOD;
			}
		}
	}
	return;
}

int main(){
	int q, p, row, col, city1, city2, len;
	memset(A, 0, sizeof(A));
	memset(R, 0, sizeof(R));
	sd(n); sd(r);
	for(int i = 0; i < r; i++){
		sd2(row,col);
		A[row][col]++;
		R[0][row][col]++;
	}
	sd(q);
	if(q<= 5){
		for(int i = 0; i < q; i++){
			sd3(city1,city2,len);
			printf("%lld\n",expo(city1, city2, len));
		}
	}
	else{
		init();
		for(int i = 0; i < q; i++){
			sd3(city1,city2,len);
			printf("%lld\n",R[len-1][city1][city2]);
		}
	}
	return 0;
}
