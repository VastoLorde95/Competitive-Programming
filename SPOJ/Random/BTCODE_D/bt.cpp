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
	int t, m, n, A[100][100], B[100][100];
	long long C[100][100];
	long long sum, max;
	sd(t);
	while(t--){
		sd2(m,n);
		for(int i = 0; i< m; i++){
			for(int j = 0; j < n; j++){
				sd(A[i][j]);
			}
		}
		for(int i = 0; i< m; i++){
			for(int j = 0; j < n; j++){
				sd(B[i][j]);
			}
		}
		for(int i = 0; i< m; i++){
			for(int j = 0; j < n; j++){
				scanf("%lld",&C[i][j]);
			}
		}
		sum = 0;
		for(int i = 0; i< m; i++){
			max = 0;
			for(int j = 0; j < n; j++){
				if(A[i][j] >= B[i][j]){
					if(B[i][j] * C[i][j] > max)
						max = B[i][j] * C[i][j];
				}
				else{
					if(A[i][j] * C[i][j] > max)
						max = A[i][j] * C[i][j];
				}
			}
			sum += max;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
