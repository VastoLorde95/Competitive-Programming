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
	int count;
	void assignLeaf(int value) {
		count += value;
	}
	
	void merge(node& left, node& right) {
		count = left.count + right.count;
	}
};

int n, array[30000], m , X, Y, indx = 0, result[200000], i;
map<int, int> last_pos;
pair<pair<int,int>, int> q[200000];
node tree[70001];


//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(array[l]);
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
void update(int i, int lo, int hi, int index, int value){
	if (lo == hi){
		tree[i].assignLeaf(value);
		return;
	}
	int left = 2*i, right = left+1, mid = (lo+hi)/2;
	if(index <= mid)
		update(left, lo, mid, index, value);
	else
		update(right, mid+1, hi, index, value);
	tree[i].merge(tree[left], tree[right]);	
	return;
}	
	
int main(){
	sd(n);
	for(i = 0; i < n; i++) sd(array[i]);
	
	sd(m);
	for(i = 0; i < m; i++){
		sd2(X,Y);
		q[i] = make_pair(make_pair(Y-1,X-1),i);
	}
	
	sort(q, q+m);
	
	for(i = 0; i < n; i++){
		update(1, 0, n-1, i, 1);
		
		if(last_pos.find(array[i]) != last_pos.end()) update(1, 0, n-1, last_pos[array[i]], -1);
		
		last_pos[array[i]] = i;
		
		while(indx < m and q[indx].first.first == i){
			result[q[indx].second] = query(1, 0, n-1, q[indx].first.second, q[indx].first.first).count;
			indx++;
		}
		
	}
	
	for(i = 0; i < m; i++)
		printf("%d\n",result[i]);
	
	return 0;
}
