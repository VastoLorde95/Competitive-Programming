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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int n, m, x, y;
long long a[100010], res, tree[500000];

//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i] = a[l];
	}
	else{
		init(2*i, l, (l+r)/2);
		init((2*i) + 1, ((l+r)/2) + 1, r);
		long long left = tree[2*i], right = tree[(2*i)+1];

		tree[i] = max(left, right);		//Merge the children into the parent
	}
	return;
}

// O(log N)
long long query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)				//If the range we want to query is the exact range
		return tree[i];
	int mid = (l+r)/2;
	if(lo > mid)						//If only the subtree rooted at right child is repsonsible for this range
		return query((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)						//If only the subtree rooted at the left child is responsible for this range
		return query(2*i, l, mid, lo, hi);
										//If both, the left and right children are partially responsible for the range
	long long left = query(2*i, l, mid, lo, mid);	
	long long right = query((2*i)+1, mid+1, r, mid+1, hi);
	
	return max(left, right);			//Merge the results of the children into the parent
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++)
		scanf("%lld",&a[i]);	
	sd3(m,x,y);
	
	init(1, 0, n-1);
	
	for(int i = 0; i < m; i++){
		//cout<< x << " " << y << endl;
		res += query(1, 0, n-1, min(x,y), max(x,y));
		
		x = (x+7)%(n-1);
		y = (y+11)%n;
	}		

	printf("%lld\n",res);
	
	return 0;
}
