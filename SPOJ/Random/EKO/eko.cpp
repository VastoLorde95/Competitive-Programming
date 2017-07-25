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

int trees[1000000];
long long n, m;
long long check(long long h){
	long long total = 0;
	for(long long i = 0; i < n; i++){
		if(trees[i] > h)
			total += (trees[i] - h);	
	}
	return total;
}

int main(){
	long long res;
	scanf("%lld %lld",&n,&m);
	long long max = 0;
	for(long long i = 0; i < n; i++){
		sd(trees[i]);
		if(trees[i] > max)
			max = trees[i];
	}
	long long low = 0, high = max, mid, height = 0;
	while(low <= high){
		mid = (low+high)/2;
		res = check(mid);
		if(res > m){
			low = mid + 1;
			if(mid > height)
				height = mid;
			}
		else if(res < m)
			high = mid - 1;
		else{
			height = mid;
			break;
		}
	}
	cout<<height<<endl;
	return 0;
}
