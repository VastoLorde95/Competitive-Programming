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
	int bl, br, b;
	
	void assignLeaf(int value) {
		bl = br= b = value;
	}
};

int n, array[1<<17], m , X, Y, temp;
node tree[1<<18][3];


//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(1);
	}
	else{
		int m = (l+r)/2;
		init(2*i, l, m);
		init((2*i) + 1, m + 1, r);
		node left = tree[2*i], right = tree[(2*i)+1];
		
		if(array[m] == array[m+1]){
			tree[i].bl = tree[2*i].bl + tree[(2*i)+1].bl*(array[l] == array[m]);
			tree[i].br = tree[(2*i)+1].br + tree[2*i].br*(array[r] == array[m+1]);
			tree[i].b = max(tree[2*i].br + tree[(2*i)+1].bl, max(tree[2*i].b, tree[(2*i)+1].b));
		}
		else{
			tree[i].bl = tree[2*i].bl;
			tree[i].br = tree[(2*i)+1].br;
			tree[i].b = max(tree[2*i].b, tree[(2*i)+1].b);
		}
	}
	return;
}

// O(log N)
int query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)				//If the range we want to query is the exact range
		return tree[i].b;
	int mid = (l+r)/2;
	if(lo > mid)						//If only the subtree rooted at right child is repsonsible for this range
		return query((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)						//If only the subtree rooted at the left child is responsible for this range
		return query(2*i, l, mid, lo, hi);
										//If both, the left and right children are partially responsible for the range
	int left = query(2*i, l, mid, lo, mid);	
	int right = query((2*i)+1, mid+1, r, mid+1, hi);
	
	if(array[mid] == array[mid+1]){
		temp = min(tree[2*i].br, mid-lo+1) + min(tree[(2*i)+1].bl, hi-mid);
		return max(temp,max(left,right));
	}
	else{
		return max(left, right);
	}
}

int main(){
	while(scanf("%d",&n) == 1 and n){
		sd(m);
		for(int i = 0; i < n; i++) sd(array[i]);
	
		init(1, 0, n-1);

		while(m--){
			sd2(X,Y);
			printf("%d\n",query(1,0,n-1,X-1,Y-1));
		}
	}
	
	return 0;
}
