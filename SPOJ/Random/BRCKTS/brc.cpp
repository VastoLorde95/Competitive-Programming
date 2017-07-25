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
	int uOpen, uClosed;
	
	void assignLeaf(int open, int closed ) {
		uOpen = open;
		uClosed = closed;
	}
	
	void merge(node& left, node& right) {
		if(right.uClosed > left.uOpen){
			uOpen = right.uOpen;
			uClosed = left.uClosed + (right.uClosed - left.uOpen);
		}
		else{
			uOpen = (left.uOpen - right.uClosed) + right.uOpen;
			uClosed = left.uClosed;
		}
	}
};

int n, m, x;
string array;
node tree[100001];

//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		if(array[l] == '('){
			tree[i].assignLeaf(1, 0);
		}
		else{
			tree[i].assignLeaf(0, 1);			
		}
		return;
	}
	else{
		init(2*i, l, (l+r)/2);
		init((2*i) + 1, ((l+r)/2) + 1, r);
		node left = tree[2*i], right = tree[(2*i)+1];

		tree[i].merge(left, right);		//Merge the children into the parent
	}
	return;
}

// O(log N)
node query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)				//If the range we want to query is the exact range
		return tree[i];
	int mid = (l+r)/2;
	if(lo > mid)						//If only the subtree rooted at right child is repsonsible for this range
		return query((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)						//If only the subtree rooted at the left child is responsible for this range
		return query(2*i, l, mid, lo, hi);
										//If both, the left and right children are partially responsible for the range
	node left = query(2*i, l, mid, lo, mid);	
	node right = query((2*i)+1, mid+1, r, mid+1, hi);
	node result;
	
	result.merge(left, right);			//Merge the results of the children into the parent
	return result;
}
	
//Call using update(1, 0, N-1, index, value) for a point update in O(log N)
void update(int i, int lo, int hi, int index){
	if (lo == hi){
		if(array[index] == '('){
			array[index] = ')';
			tree[i].assignLeaf(0, 1);
		}
		else{
			array[index] = '(';
			tree[i].assignLeaf(1, 0);			
		}
		return;
	}
	int left = 2*i, right = left+1, mid = (lo+hi)/2;
	if(index <= mid)
		update(left, lo, mid, index);
	else
		update(right, mid+1, hi, index);
	tree[i].merge(tree[left], tree[right]);
	return;
}	
	
int main(){
	int t = 1;
	while(t <= 10){
		printf("Test %d:\n",t);
		sd(n);
		cin>>array;
	
		init(1, 0, n-1);
	
		sd(m);	// Number of operations
		while(m--){
			//cin>>debug;
			sd(x);
			//cout<<m<<endl;
			if(x > 0){
				update(1, 0, n-1, x-1);
			}
			else{
				if(tree[1].uOpen == 0 and tree[1].uClosed == 0)
					printf("YES\n");
				else{
					printf("NO\n");
				}
			}
			
		}
		t++;
	}
	return 0;
}
