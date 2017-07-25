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
	vector<int> num;
	int s;
	
	void assignLeaf(int value){
		num.push_back(value);
		s = 1;
	}
	void merge(node& left, node& right){
		int i = 0, j = 0;
		while(i < left.s and j < right.s){
			if(left.num[i] < right.num[j]){
				num.push_back(left.num[i]);
				i++;
			}
			else{
				num.push_back(right.num[j]);
				j++;
			}
		}
		while(i < left.s){
			num.push_back(left.num[i]);
			i++;
		}
		
		while(j < right.s){
			num.push_back(right.num[j]);
			j++;
		}
		s = num.size();
	}
};

int n, m, array[1<<17], x, y, z, found, cur, res;
node tree[1<<18];


//	l and r represent the range node i is responsible for. A single call init(1, 0, n-1) builds the segment tree in O(N) time
void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(array[l]);
	}
	else{
		init(i*2, l, (l+r)/2);
		init((i*2) + 1, ((l+r)/2) + 1, r);
		node left = tree[i*2], right = tree[(i*2)+1];

		tree[i].merge(left, right);		//Merge the children into the parent
	}
	return;
}

// Returns the no of numbers less than a given number in the range x to y. If that is equal to k-1 and if the given number lies in this range then that number is our answer.
int query(int i, int l, int r){
	if(x > r or y < l){
		return 0;
	}
	if(x <= l and y >= r){
		int lo = 0, hi = tree[i].s - 1, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			if(tree[i].num[mid] >= cur)
				hi = mid;
			else
				lo = mid + 1;
		}
		if(tree[i].num[lo] == cur)
			found = 1;
		else if(tree[i].num[lo] < cur)
			lo += 1;
		return lo;
	}
	else{
		int mid = (l+r)/2;
		return query(i*2, l, mid) + query((i*2)+1, mid+1,r);
	}
}
	
int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++) sd(array[i]);
	
	init(1, 0, n-1);
	while(m--){
		sd3(x,y,z);
		x--;
		y--;
		int lo = 0, hi = tree[1].s-1, mid;
		while(lo <= hi){	
		// We check if a given number is present in the queried range and if present
		// wether the number of numbers smaller than it is equal to k-1.
			found = 0;
			mid = (lo+hi)/2;
			cur = tree[1].num[mid];
			res = query(1, 0, n-1);

			if(res == (z-1) and found == 1){
				printf("%d\n",cur);
				break;
			}
			else if(res > (z-1)){
				hi = mid - 1;
			}
			else{
				lo = mid + 1;
			}
		}
	}
	
	return 0;
}
