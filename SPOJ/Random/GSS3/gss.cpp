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
	int prefixMaxSum, suffixMaxSum, maxsum, sum;
	
	void assignLeaf(int value) {
		prefixMaxSum = suffixMaxSum = maxsum = sum = value;
	}
	
	void merge(node& left, node& right){
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max(right.suffixMaxSum, left.suffixMaxSum + right.sum);
		maxsum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxsum, max(right.maxsum, left.suffixMaxSum + right.prefixMaxSum))));
	}
};

int n, array[50000], m , X, Y, type;
node tree[150001];
	
void init(int i, int l, int r){
	if(l == r){
		tree[i].prefixMaxSum = array[l];
		tree[i].suffixMaxSum = array[l];
		tree[i].maxsum = array[l];
		tree[i].sum = array[l];
	}
	else{
		init(2*i, l, (l+r)/2);
		init((2*i) + 1, ((l+r)/2) + 1, r);
		
		node left = tree[2*i], right = tree[(2*i)+1];
		//Merge the children to form the parent node i
		tree[i].merge(left, right);
	}
	return;
}

node query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)
		return tree[i];
	int mid = (l+r)/2;
	if(lo > mid)
		return query((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)
		return query(2*i, l, mid, lo, hi);
	
	node left = query(2*i, l, mid, lo, mid);
	node right = query((2*i)+1, mid+1, r, mid+1, hi);
	node result;
	
	result.merge(left,right);
	
	return result;
}


void update(int stIndex, int lo, int hi, int index, int value) {
	if (lo == hi) {
		tree[stIndex].prefixMaxSum = value;
		tree[stIndex].suffixMaxSum = value;
		tree[stIndex].maxsum = value;
		tree[stIndex].sum = value;
		return;
	}
	int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
	if (index <= mid)
		update(left, lo, mid, index, value);
	else
		update(right, mid+1, hi, index, value);
	tree[stIndex].merge(tree[left], tree[right]);
}
	
int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(array[i]);
	
	init(1, 0, n-1);
	
	sd(m);
	while(m--){
		sd3(type,X,Y);
		if(type == 1)
			printf("%d\n",query(1,0,n-1,X-1,Y-1).maxsum);
		else if(type == 0){
			update(1, 0, n-1, X-1, Y);
			}
	}
	
	return 0;
}
