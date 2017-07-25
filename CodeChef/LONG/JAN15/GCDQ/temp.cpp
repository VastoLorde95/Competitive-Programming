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

using namespace std;

struct node{
	int num;
	
	void assignLeaf(int value) {
		num = value;
	}
	
	void merge(node& left, node& right) {
		if(left.num == 1 or right.num == 1){
			num = 1;
		}
		else{
			num = __gcd(left.num, right.num);
		}
	}
};

int t, n, array[200000], m , X, Y;
int tree[500001];


//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i] = array[l];
		//tree[i].assignLeaf(array[l]);
	}
	else{
		init(2*i, l, (l+r)/2);
		init((2*i) + 1, ((l+r)/2) + 1, r);
		int left = tree[2*i], right = tree[(2*i)+1];

		tree[i] = __gcd(left, right);		//Merge the children into the parent
	}
	return;
}

// O(log N)
int query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)				//If the range we want to query is the exact range
		return tree[i];
	int mid = (l+r)/2;
	if(lo > mid)						//If only the subtree rooted at right child is repsonsible for this range
		return query((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)						//If only the subtree rooted at the left child is responsible for this range
		return query(2*i, l, mid, lo, hi);
										//If both, the left and right children are partially responsible for the range
	int left = query(2*i, l, mid, lo, mid);	
	int right = query((2*i)+1, mid+1, r, mid+1, hi);
	int result;
	
	result = __gcd(left, right);			//Merge the results of the children into the parent
	
	return result;
}
	
int main(){
	sd(t);
	while(t--){
		sd2(n,m);
		for(int i = 0; i < n; i++) sd(array[i]);
	
		init(1, 0, n-1);
	
		while(m--){
			sd2(X,Y);
			if(X > 1 and Y < n)
				printf("%d\n",__gcd(query(1,0,n-1,0,X-2), query(1,0,n-1,Y,n-1)));
			else if(X == 1)
				printf("%d\n",query(1,0,n-1,Y,n-1));
			else
				printf("%d\n",query(1,0,n-1,0,X-2));
		}
	}
	return 0;
}
