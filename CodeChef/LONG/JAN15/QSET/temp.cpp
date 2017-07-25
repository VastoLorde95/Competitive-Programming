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
	int sum;
	long long la, lb, lc, ra, rb, rc, a, b, c;
	
	void assignLeaf(int value) {
		sum = (value)%3;
		la = ra = a = lb = rb = b = lc = rc = c = 0;
		if(sum == 0){
			la = ra = a = 1;
		}
		else if(sum == 1){
			lb = rb = b = 1;
		}
		else{
			lc = rc = c = 1;
		}			
	}
	
	void merge(node& left, node& right) {
		a = (right.ra * left.la) + (right.rb * left.lc) + (right.rc * left.lb) + left.a + right.a;
		b = (right.ra * left.lb) + (right.rb * left.la) + (left.lc * right.rc) + left.b + right.b;
		c = (right.ra * left.lc) + (right.rc * left.la) + (right.rb * left.lb) + left.c + right.c;
		
		sum = (left.sum + right.sum)%3;
		
		la = right.la + ((right.sum == 0)? left.la: 0) + ((right.sum == 1)? left.lc:0) + ((right.sum == 2)? left.lb:0);
		ra = left.ra + ((left.sum == 0)? right.ra: 0) + ((left.sum == 1)? right.rc:0) + ((left.sum == 2)? right.rb:0);
		
		lb = right.lb + ((right.sum == 0)? left.lb: 0) + ((right.sum == 1)? left.la:0) + ((right.sum == 2)? left.lc:0);
		rb = left.rb + ((left.sum == 0)? right.rb: 0) + ((left.sum == 1)? right.ra:0) + ((left.sum == 2)? right.rc:0);
		
		lc = right.lc + ((right.sum == 0)? left.lc: 0) + ((right.sum == 1)? left.lb:0) + ((right.sum == 2)? left.la:0);
		rc = left.rc + ((left.sum == 0)? right.rc: 0) + ((left.sum == 1)? right.rb:0) + ((left.sum == 2)? right.ra:0);
	}
	
	/*void print(){
		cout<<a<<" "<<la<<" "<<ra<<" "<<b<<" "<<lb<<" "<<rb<<" "<<c<<" "<<lc<<" "<<rc<<" "<<sum<<endl;
	}*/
};

int n, array[150000], m, t, X, Y;
node tree[400001];
char ch;


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
		//cout<<"range "<<l<<" to "<<r<<" and the merge is ";
		//tree[i].print();
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
		//cout<<"update: range "<<lo<<" to "<<hi<<" and the merge is ";
		//tree[i].print();
		return;
	}
	int left = 2*i, right = left+1, mid = (lo+hi)/2;
	if(index <= mid)
		update(left, lo, mid, index, value);
	else
		update(right, mid+1, hi, index, value);
	tree[i].merge(tree[left], tree[right]);
	
	//cout<<"update: range "<<lo<<" to "<<hi<<" and the merge is ";
	//tree[i].print();
	
	return;
}	
	
int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		scanf(" %c",&ch);
		array[i] = ch-'0';
	}
	init(1, 0, n-1);
	
	while(m--){
		sd3(t,X,Y);
		if(t == 2)
			printf("%lld\n",query(1,0,n-1,X-1,Y-1).a);
		else{
			update(1, 0, n-1, X-1, Y);
		}
	}
	
	return 0;
}
