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

int T, n, u, l, r, val, q, indx;
long long t[10001];

long long get(int i){
	long long sum = 0;
	while(i > 0){
		sum += t[i];
		i = i - (i&(-i));
	}
	return sum;
}

void update(int i, int val){
	while( i <= n){
		t[i] += val;
		i = i + (i&(-i));
	}
	return;
}

void range_update(int left, int right, int val){
	update(left, val);
	update(right+1, -val);
	return;
}

int main(){
	sd(T);
	while(T--){
		memset(t, 0, sizeof(t));
		sd2(n,u);
		for(int i = 0; i < u; i++){
			sd3(l,r,val);
			range_update(l+1,r+1,val);
		}
		sd(q);
		for(int i = 0; i < q; i++){
			sd(indx);
			printf("%lld\n",get(indx+1));
		}
	}
	return 0;
}
