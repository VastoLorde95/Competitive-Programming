#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
#include<algorithm>
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
	int best, l, r, indx, isLeaf;
	
	void assignLeaf(int value, int i) {
		best = l = r = value;
		indx = i;
		isLeaf = 1;
	}
	
	void merge(node& left, node& right) {
		best = max(left.best, right.best);
		l = left.best;
		r = right.best;
	}
};

int T, k, n, array[1<<17], c, s, w, a, cnt;
char q[6];
node tree[1<<18];


//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(array[l], l);
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
void query(int i, int val){
	if(tree[i].isLeaf == 1){
		array[tree[i].indx] -= val;
		tree[i].best -= val;
		tree[i].l = tree[i].r = tree[i].best;
		return;
	}
	else if(tree[i].best < val)
		return;
	else{
		if(tree[i].l >= val)
			query(2*i, val);
		else
			query((2*i)+1,val);
		tree[i].merge(tree[2*i], tree[(2*i)+1]);
		return;
	}
}
	
int main(){
	sd(T);
	while(T--){
		sd(k);
		for(int i = 0; i < 100000; i++)
			array[i] = k;

		init(1, 0, 99999);

		s = 0, w = 0;
		sd(n);
		while(n){
			scanf("%s",q);
			if(q[0] == 'b'){
				scanf("%s",q);
				a = atoi(q);
				scanf("%s",q);
				c = atoi(q);
				while(a--){
					query(1,c);
					n--;
				}
			}
			else{
				c = atoi(q);
				query(1,c);
				n--;
			}
		}
		for(int i = 0; i < 100000; i++){
			if(array[i] != k){
				s++;
				w += array[i];
			}
		}
		printf("%d %d\n",s,w);	
	}	
	return 0;
}
