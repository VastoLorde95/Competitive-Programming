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
	long long count;
	int s;
	
	void assignLeaf(int value){
		num.clear();
		num.push_back(value);
		count = 0, s = 1;
	}
	void merge(node& left, node& right){
		int i = 0, j = 0;
		num.clear();
		count = left.count + right.count;
		while(i < left.s and j < right.s){
			if(left.num[i] > right.num[j]){
				num.push_back(right.num[j]);
				count += (left.s - i);
				j++;
			}
			else{
				num.push_back(left.num[i]);
				i++;	
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

int t, n, array[1<<18];
node tree[1<<19];
long long *res;

void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(array[l]);
	}
	else{
		init(i<<1, l, (l+r)>>1);
		init((i<<1) + 1, ((l+r)>>1) + 1, r);
		node left = tree[i<<1], right = tree[(i<<1)+1];

		tree[i].merge(left, right);
	}
	return;
}
	
int main(){
	sd(t);
	res = &tree[1].count;
	while(t--){
		sd(n);
		for(int i = 0; i < n; i++) scanf("%d",&array[i]);
																																															
		init(1,0,n-1);
		
		printf("%lld\n",*res);
	}
	return 0;
}
