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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

struct node{	//right is 1 and left is 0
	node *left, *right;
	int left_count, right_count;
};	

node *ROOT;

void insert(node *cur, int num){
	for(int i = 17; i >= 0; i--){	//if ith significant bit is 1 go to the right child
		if(((num>>i)&1) > 0){
			cur->right_count++;
			if(cur->right == NULL){
				node *temp = new node;
				cur->right = temp;
			}
			cur = cur->right;
		}
		else{						//if ith significant bit is 0 go to the left child
			cur->left_count++;
			if(cur->left == NULL){
				node *temp = new node;
				cur->left = temp; 
			}
			cur = cur->left;
		}
	}
	return;
}

int query(node *cur, int q, int k){	
	int res = 0, b1, b2;
	for(int i = 17; i >= 0; i--){
		b1 = (k>>i)&1;
		b2 = (q>>i)&1;
		if(b1){
			if(b2){
				res += cur->right_count;
				if(cur->left == NULL) return res;
				cur = cur->left;
			}
			else{
				res += cur->left_count;
				if(cur->right == NULL) return res;
				cur = cur->right;
			}
		}
		else{
			if(b2){
				if(cur->right == NULL) return res;
				cur = cur->right;
			}
			else{
				if(cur->left == NULL) return res;
				cur = cur->left;
			}
		}
	}
	return res;
}

int main(){
	int t, n, k, num, val;
	long long ans;
	sd(t);
	while(t--){
		sd2(n,k);
		ROOT = new node;	
		val = ans = 0;
		insert(ROOT, 0);
		for(int i = 0; i < n; i++){
			sd(num);
			val ^= num;
			ans +=  (long long) query(ROOT, val, k);
			insert(ROOT, val);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

