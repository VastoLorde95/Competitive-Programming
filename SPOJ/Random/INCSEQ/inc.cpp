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
#define MAX 100002

using namespace std;

/*
get(tnum, i) represents the number of increasing sequences of length tnum and smaller than i

Proof of correctness -  An update operation will traverse upwards in the tree. Only ranges which contain numbers greater than the 
index i are affected by the update. This is what is required since the number of increasin sequnces of length k and highed element i have to be counted in the number of seqeunces with length k and highest element i+1 as well. Moreover when we obtain get(k, i), we will perform an update as update(k+1, i, get(k,i)). This is because the number of increasing sequences of length k+1 and maximum value i is the sum of get(k, i-1) and get(k-1, i). The BIT autmoatically accounts for get(k, i-1) for all j > i-1.
*/
int bit[51][MAX], num[10000], MOD = 5000000, dp[51];

int get(int tnum, int indx){
	int sum = 0;
	while(indx > 0){
		sum = (sum + bit[tnum][indx])%MOD;
		indx -= (indx & -indx);
	}
	return sum;
}

void update(int tnum, int indx, int val){
	while(indx < MAX){
		bit[tnum][indx] = (bit[tnum][indx] + val)%MOD;
		indx += (indx & -indx);
	}
	return;
}

int main(){
	int n, k;	
	sd2(n,k);
	for(int i = 0; i < n; i++) sd(num[i]);
	
	memset(bit, 0, sizeof(bit));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++)
			dp[j] = get(j, num[i]);
		
		update(0, num[i]+1, 1);
		for(int j = 1; j < k; j++){
			update(j, num[i]+1, dp[j-1]);
		}
	}
	
	printf("%d\n",get(k-1,MAX-1));
}
