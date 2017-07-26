#include <bits/stdc++.h>
using namespace std;

struct sparseSegmentTree{
	struct node{
		node *left, *right;
		int cnt;
	
		node(){
			cnt = 0, left = NULL, right = NULL;
		}
		
		void updateNode(){
			cnt = ((left == NULL)? 0 : left->cnt) + ((right == NULL)? 0 : right->cnt);
		}
	};
	
	node *ROOT;
	int L, R;	// interval is closed from both sides i.e. [L,R]
	
	sparseSegmentTree(int l, int r){
		L = l, R = r;
		ROOT = new node();
	}
	
	// point update
	void update(int id, int val, int l, int r, node *cur){
		if(l == r){
			cur->cnt += val;
			return;
		}
		
		int mid = (l + r) >> 1;
		
		if(id <= mid){
			if(cur->left == NULL) cur->left = new node();
			update(id, val, l, mid, cur->left);
		}
		else{
			if(cur->right == NULL) cur->right = new node();
			update(id, val, mid+1, r, cur->right);
		}
		
		cur->updateNode();	
	}
	
	// range query
	int query(int x, int y, int l, int r, node *cur){
		if(y < l or x > r or cur == NULL) return 0;
		if(x <= l and r <= y) return cur->cnt;
		int mid = (l + r) >> 1;
		return query(x, y, l, mid, cur->left) + query(x, y, mid+1, r, cur->right);
	}
	
	void update(int id, int val){
		update(id, val, L, R, ROOT);
	}
	
	int query(int x, int y){
		return query(x, y, L, R, ROOT);
	}
};

int main(){
	
	return 0;
}
