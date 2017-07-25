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

//Merge Sort Tree
struct node{
	vector<int> num;
	int s, inv;
	
	void assignLeaf(int value){
		num.clear();
		num.push_back(value);
		s = 1;
		inv = 0;
	}
	void merge(node& left, node& right){
		int i = 0, j = 0;
		num.clear();
		inv = left.inv + right.inv;
		while(i < left.s and j < right.s){
			if(left.num[i] > right.num[j]){
				num.push_back(right.num[j]);
				inv = inv + (left.s - i);
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

int t, n, array[1<<15], i;
int *res;
char word[21];
map<string, int> dic;
node tree[1<<16];


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

int main(){
	res = &(tree[1].inv);
	sd(t);
	while(t--){
		sd(n);
		dic.clear();
		for(i = 0; i < n; i++){
			scanf("%s",word);
			dic[word] = i;
		}
		for(i = 0; i < n; i++){
			scanf("%s",word);
			array[dic[word]] = i;
		}
		init(1,0,n-1);
		
		printf("%d\n",*res);
	}
	return 0;
}
