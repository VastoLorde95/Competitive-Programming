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

using namespace std;

struct node{
	int val;
	int ind;
	
	void assignLeaf(int value, int index) {
		val = value;
		ind = index;
	}
	
	void merge(node& left, node& right) {
		if(left.val <= right.val){
			val = left.val;
			ind = left.ind;
		}
		else if(left.val > right.val){
			val = right.val;
			ind = right.ind;
		}
	}
};

struct node2{
	int len;
	int lmax, rmax, mx;
	
	int l1, r1;
	int l2, r2;
	int l3, r3;
	
	
	void assignLeaf(int value, int index){
		len = 1;
		if(value == 1){
			lmax = rmax = 1; mx = 1;
			l1 = r1 = index;
			l2 = r2 = index;
			l3 = r3 = index;
		}
		else{
			lmax = rmax = -1; mx = -1;
			l1 = r1 = -1;
			l2 = r2 = -1;
			l3 = r3 = -1;
		}
	}
	
	void merge(node2& left, node2& right) {
		len = left.len + right.len;
		
		if(left.mx > 0 and right.mx > 0){
		
			if(left.lmax == left.len){
				lmax = left.lmax + right.lmax;
				l1 = left.l1;
				r1 = right.r1;
			}
			else{
				lmax = left.lmax;
				l1 = left.l1;
				r1 = left.r1;
			}
		
			if(right.rmax == right.len){
				rmax = right.rmax + left.rmax;
				l2 = left.l2;
				r2 = right.r2;
			}
			else{
				rmax = right.rmax;
				l2 = right.l2;
				r2 = right.r2;
			}
		
			mx = 0;
			if(lmax > mx){
				mx = lmax;
				l3 = l1;
				r3 = r1;
			}
		
			if(left.mx > mx){
				mx = left.mx;
				l3 = left.l3;
				r3 = left.r3;
			}
		
			if(left.rmax + right.lmax > mx){
				mx = left.rmax + right.lmax;
				l3 = left.l2;
				r3 = right.r1;
			}
		
			if(right.mx > mx){
				mx = right.mx;
				l3 = right.l3;
				r3 = right.r3;
			}
		
			if(rmax > mx){
				mx = rmax;
				l3 = l2;
				r3 = r2;
			}
		}
		else if(left.mx > 0){
			lmax = left.lmax; rmax = -1;
			
			mx = left.mx;
			
			l1 = left.l1;
			r1 = left.r1;
			
			l2 = r2 = -1;
			
			l3 = left.l3; 
			r3 = left.r3;
		}
		else if(right.mx > 0){
			lmax = -1;
			rmax = right.rmax;
			
			mx = right.mx;
			
			l1 = r1 = -1;
			
			l2 = right.l2;
			r2 = right.r2;
			
			l3 = right.l3;
			r3 = right.r3;
		}
		else{
			lmax = rmax = -1; mx = -1;
			l1 = r1 = -1;
			l2 = r2 = -1;
			l3 = r3 = -1;
		}
	}
};

int n, q, arr[1<<17], X, Y;
node tree[1<<18];
node2 tree2[1<<18];

//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(arr[l],l);
	}
	else{
		init(2*i, l, (l+r)/2);
		init((2*i) + 1, ((l+r)/2) + 1, r);
		node left = tree[2*i], right = tree[(2*i)+1];

		tree[i].merge(left, right);		//Merge the children into the parent
	}
	return;
}

void init2(int i, int l, int r){
	if(l == r){
		tree2[i].assignLeaf(arr[l],l);
	}
	else{
		init2(2*i, l, (l+r)/2);
		init2((2*i) + 1, ((l+r)/2) + 1, r);
		node2 left = tree2[2*i], right = tree2[(2*i)+1];

		tree2[i].merge(left, right);		//Merge the children into the parent
	}
	return;
}

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

node2 query2(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)				//If the range we want to query is the exact range
		return tree2[i];
	int mid = (l+r)/2;
	if(lo > mid)						//If only the subtree rooted at right child is repsonsible for this range
		return query2((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)						//If only the subtree rooted at the left child is responsible for this range
		return query2(2*i, l, mid, lo, hi);
										//If both, the left and right children are partially responsible for the range
	node2 left = query2(2*i, l, mid, lo, mid);	
	node2 right = query2((2*i)+1, mid+1, r, mid+1, hi);
	node2 result;
	
	result.merge(left, right);			//Merge the results of the children into the parent
	return result;
}
	
//Call using update(1, 0, N-1, index, value) for a point update in O(log N)
void update(int i, int lo, int hi, int index, int value){
	if (lo == hi){
		tree[i].assignLeaf(value,lo);
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

void update2(int i, int lo, int hi, int index, int value){
	if (lo == hi){
		tree2[i].assignLeaf(value,lo);

//		cout << endl;
//		cout << "Showing node " << lo << " " << hi << endl;
//		cout << tree2[i].len << " " << tree2[i].lmax << " " << tree2[i].rmax << " " << tree2[i].mx << endl;
//		cout << tree2[i].l1 << " " << tree2[i].r1 << endl;
//		cout << tree2[i].l2 << " " << tree2[i].r2 << endl;
//		cout << tree2[i].l3 << " " << tree2[i].r3 << endl;
//		cout << endl;
		return;
	}
	int left = 2*i, right = left+1, mid = (lo+hi)/2;
	if(index <= mid)
		update2(left, lo, mid, index, value);
	else
		update2(right, mid+1, hi, index, value);
	tree2[i].merge(tree2[left], tree2[right]);
	
//	cout << endl;
//	cout << "Showing node " << lo << " " << hi << endl;
//	cout << tree2[i].len << " " << tree2[i].lmax << " " << tree2[i].rmax << " " << tree2[i].mx << endl;
//	cout << tree2[i].l1 << " " << tree2[i].r1 << endl;
//	cout << tree2[i].l2 << " " << tree2[i].r2 << endl;
//	cout << tree2[i].l3 << " " << tree2[i].r3 << endl;
//	cout << endl;
	
	return;
}	
	
int main(){
	sd2(n,q);
	for(int i = 0; i < n; i++) sd(arr[i]);
	
	init(1, 0, n-1);
	init2(1, 0, n-1);
	
	
	int type;
	while(q--){
		sd(type);
		if(type == 1){
//			cout << "number 111" << endl;
			sd2(X,Y);
			X--, Y--;
			node res = query(1, 0, n-1, X, Y);
//			printf("This is %d\n", res.val);
			if(res.val > 1){
				printf("%d %d %d\n", res.val, res.ind+1, res.ind+1);
			}
			else if(res.val == 0){
				printf("%d %d %d\n", 0, X+1, Y+1);
			}
			else{
				node2 res2 = query2(1, 0, n-1, X, Y);
				printf("%d %d %d\n", 1, res2.l3+1, res2.r3+1);
			}
		}
		else{
			sd2(X,Y);
			X--;
			update(1, 0, n-1, X, Y);
			update2(1, 0, n-1, X, Y);
		}
	}
	
	return 0;
}
