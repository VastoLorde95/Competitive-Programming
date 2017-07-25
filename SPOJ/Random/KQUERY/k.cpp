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

struct node{
	int val, l, r, idx;
	bool t;
};

bool operator<(const node& a, const node& b ){
	if ( a.val == b.val ){
		return a.t < b.t;
	}
	return a.val < b.val;
}
int N, Q, bit[30001], i, ans[230000], r;
node req[230000];

int get(int indx){
	int sum = 0;
	while (indx > 0){
		sum += bit[indx];
		indx -= ( indx & -indx );
	}
	return sum;
}
void update(int indx){
	while (indx <= 30000){
		bit[indx] += 1;
		indx += (indx & -indx);
	}
	return;
}
int main(){
	sd(N);
	for ( i = 0; i < N; ++i ){
		sd(req[ i ].val);
		req[i].idx = i + 1;
		req[i].t = 0;
	}
	sd(Q);
	for ( i = N; i < N + Q; ++i ){
		sd3(req[i].l,req[i].r,req[i].val);
		req[i].idx = i - N;
		req[i].t = 1;
	}

	sort( req, req + N + Q );
	
	for ( i = 0; i < N + Q; ++i ){
		if (req[i].t){
			r = get(req[i].r) - get(req[i].l - 1);
			ans[req[i].idx] = (req[i].r - req[i].l + 1 ) - r;
		}
		else{
			update(req[i].idx);
		}
	}
	for ( i = 0; i < Q; ++i ) {
		printf( "%d\n", ans[i]);
	}
	return 0;
}
