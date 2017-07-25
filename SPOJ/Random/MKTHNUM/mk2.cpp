/*
	Using the concept of persistent segment trees and the obeservation that if number of nodes in left subtree of segment tree > k then go k, we can avoid a factor of log^2 N. Thus complexity reduces to O((M+N)log(N))
*/
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

#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111

int val[N], RM[N], maxi = 0;
map <int, int> compresser;

struct node{
	int count;
	node *left, *right;
	
	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}
		
	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);

node * node::insert(int l, int r, int w){
	if(l <= w && w < r){
		if(l+1 == r){
			return new node(this->count+1, null, null);
		}
		
		int m = (l+r)>>1;
		
		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}
	// Out of range, we can use the node of the segment tree of the parent as the current node. This is because out of range means that we don't need to update this particular range of nodes.
	return this;
}

node *root[N];

int query(node *a, node *b, int l, int r, int k){
	while(1){
		if(l+1 == r) return l;
	
		// This is the formula we derived
		int count = a->left->count - b->left->count;
		int m = (l+r)>>1;
	
		// We have enough on left, so go left
		if(count >= k)
			a = a->left, b = b->left, r = m;
		else
			a = a->right, b = b->right, l = m, k -= count;
	}
}

int main(){
	int n, m, u, v, k, ans;
	
	scanf("%d%d", &n, &m);
	
	rep(i, n){
		scanf("%d", &val[i]);
		compresser[val[i]];
	}
	
	maxi = 0;
	for( map <int, int > :: iterator it = compresser.begin(); it != compresser.end(); it++){
		compresser[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	
	// We compressed the given weights into the range [0..n)
	null->left = null->right = null;
	rep(i, n){
		root[i] = (i == 0 ? null : root[i-1])->insert( 0, maxi, compresser[val[i]] );
	}
			
	while(m--){
		//int u, val, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;
		
		ans = query(root[v],(u==0?null:root[u-1]), 0, maxi, k);
		
		// Reverse Map the values, that is, uncompress
		printf("%d\n", RM[ans]);
	}
}

