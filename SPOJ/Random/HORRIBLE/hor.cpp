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

#define sd(x) scanf("%lld",&x);
#define sd2(x,y) scanf("%lld %lld",&x,&y);
#define sd3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define sull2(x,y) scanf("%ull %ull",&x,&y);
#define sull3(x,y,z) scanf("%ull %ull %ull",&x,&y,&z);

using namespace std;

long long t1[100001], t2[100001];
long long n;
long long get(long long t[100001],long long i){
	long long sum = 0;
	while(i > 0){
		sum += t[i];
		i = i - (i&(-i));
	}
	return sum;
}

void update(long long t[100001],long long i, long long val){
	while( i <= n){
		t[i] += val;
		i = i + (i&(-i));
	}
	return;
}

void range_update(long long left, long long right, long long val){
	update(t1, left, val);
	update(t1, right+1, -val);
	update(t2, left, val*(left-1));
	update(t2, right+1, -val*right);
	return;
}

long long query(long long b){
	return get(t1,b)* b - get(t2,b);
}

int main(){
	long long T, c, type, p, q, val;
	sd(T);
	while(T--){
		sd2(n,c);
		for(long long i = 0; i <= n; i++){
			t1[i] = 0;
			t2[i] = 0;
		}
		for(long long i = 0; i < c; i++){
			sd(type);
			if(type){
				sd2(p,q);
				printf("%lld\n",query(q)-query(p-1));
			}
			else{
				sd3(p,q,val);
				range_update(p,q,val);
			}
		}
		
	}
	return 0;
}
