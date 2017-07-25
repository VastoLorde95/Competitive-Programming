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
#define MAX 20003

using namespace std;

long long bit[101][MAX];
int num[100];

long long get(int tnum, int indx){
	long long sum = 0;
	while(indx > 0){
		sum += bit[tnum][indx];
		indx -= (indx & -indx);
	}
	return sum;
}

void update(int tnum, int indx, long long val){
	while(indx < MAX){
		bit[tnum][indx] = (bit[tnum][indx] + val);
		indx += (indx & -indx);
	}
	return;
}

int main(){
	int n, k;	
	sd2(n,k);
	while(n != 0 or k != 0){
		for(int i = 0; i < n; i++) sd(num[i]);
	
		memset(bit, 0, sizeof(bit));
	
		for(int i = 0; i < n; i++){
			update(0, num[i]+10001, 1);
			for(int j = 1; j < k; j++){
				update(j, num[i]+10001, get(j-1, num[i]+10000));
			}
		}
		printf("%lld\n",get(k-1,MAX-1));	
		sd2(n,k);
	}
}
