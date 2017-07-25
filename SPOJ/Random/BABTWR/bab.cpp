#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int h[91],w[91],d[91], INF = 100000000, n;
int dp[90][90];
int partition(int left, int right){
	int p = left, pivot = h[left] * w[left];
	
	int t1 = w[left], t2 = d[left], t3 = h[left];
	for(int i = left + 1; i <= right; i++){
		if(pivot < h[i]*w[i]){
			h[p] = h[i];
			h[i] = h[p+1];
			h[p+1] = t3;
			
			w[p] = w[i];
			w[i] = w[p+1];
			w[p+1] = t1;
			
			d[p] = d[i];
			d[i] = d[p+1];
			d[p+1] = t2;
		
			p++;
			}
		}	
	return p;
}

void quicksort(int i, int k){
	if( i < k){
		int  p = partition(i, k);
		quicksort(i, p-1);
		quicksort(p+1, k);
	}
	return;
}
int recur(int prev, int i){
		if( i > 3*n)
			return 0;
		else if(dp[prev][i] > 0)
			return dp[prev][i];
		else if( prev == 0)
			dp[prev][i] =  max(recur(i, i+1) + d[i], recur(prev, i+1));
		else if((h[i] < h[prev] and w[i] < w[prev]) or(h[i] < w[prev] and w[i] < h[prev]))
			dp[prev][i] = max(recur(i, i+1) + d[i], recur(prev, i+1));
		else
			dp[prev][i] = recur(prev, i+1);			
	}
int main(){
	int i, j, a, b, c;
	h[0] = INF;
	w[0] = INF;
	d[0] = 0;
	sd(n);
	while(n>0){
		memset(dp, 0, sizeof(dp));
		j = 1;
		//for(i = 1; i<=90; i++){
		//	h[i] = 0;
		//	w[i] = 0;
		//	d[i] = 0;
		//}
		for(i = 0; i < n; i++){
			sd3(a,b,c);
			h[j] = a;
			w[j] = b;
			d[j] = c;
			j++;
			h[j] = b;
			w[j] = c;
			d[j] = a;
			j++;
			h[j] = c;
			w[j] = a;
			d[j] = b;
			j++;			
		}
		quicksort(0, 3*n);
		//for(i = 0; i <= 3*n; i++)
		//	cout<<h[i]<<" "<<w[i]<<" "<<d[i]<<" "<<h[i]*w[i]<<endl;
		cout<<recur(0, 1)<<endl;
		sd(n);
	}
	return 0;
}
