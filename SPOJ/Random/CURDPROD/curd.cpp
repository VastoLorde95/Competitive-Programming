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
#define sull(x) scanf("%llu",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;
int t, n, T, q[10000];
long long p,sum,m, total;

void check(long long &val){
	total = 0;
	for(int i = 0; i < n; i++)
		total += val/q[i];
}

int main(){
	sd(t);
	while(t--){
		scanf("%d%d",&n,&T);
		m = 0;
		for(int i = 0; i < n; i++){
			sd(q[i]);
			m = (m > q[i])? m:q[i];
		}	
		long long lo = 1, hi = T*m, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			check(mid);
			if(total >= T)
				hi = mid;
			else
				lo = mid + 1; 
		}
		printf("%lld\n",hi);
	}
	return 0;
}
