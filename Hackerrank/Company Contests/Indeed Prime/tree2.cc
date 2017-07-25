#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

// segment seg_tree1

struct min_node{
	int min_val;
	int interval;
	
	void assignLeaf(int value, int index) {
		min_val = value;
		interval = index;
	}
	
	void merge(min_node& left, min_node& right) {
		if(left.min_val <= right.min_val){
			min_val = left.min_val;
			interval = left.interval;
		}
		else if(left.min_val > right.min_val){
			min_val = right.min_val;
			interval = right.interval;
		}
	}
};

struct one_node{
	int interval_length, leftmax, rightmax, totalmax, l1, r1, l2, r2, l3, r3;
	void assignLeaf(int value, int index){
		interval_length = 1;
		if(value == 1){
			leftmax = rightmax = 1; totalmax = 1;
			l1 = r1 = index; l2 = r2 = index; l3 = r3 = index;
		}
		else{
			leftmax = rightmax = 0; totalmax = 0;
			l1 = r1 = -1; l2 = r2 = -1; l3 = r3 = -1;
		}
	}
	
	void merge(one_node& left, one_node& right) {
		interval_length = left.interval_length + right.interval_length;
		
		if(left.totalmax > 0 and right.totalmax > 0){
		
			if(left.leftmax == left.interval_length and right.leftmax > 0){
				leftmax = left.leftmax + right.leftmax; l1 = left.l1; r1 = right.r1;
			}
			else{
				leftmax = left.leftmax; l1 = left.l1; r1 = left.r1;
			}
		
			if(right.rightmax == right.interval_length and left.rightmax > 0){
				rightmax = right.rightmax + left.rightmax; l2 = left.l2; r2 = right.r2;
			}
			else{
				rightmax = right.rightmax; l2 = right.l2; r2 = right.r2;
			}
		
			totalmax = 0;
			if(leftmax > totalmax){
				totalmax = leftmax; l3 = l1; r3 = r1;
			}
		
			if(left.totalmax > totalmax){
				totalmax = left.totalmax; l3 = left.l3; r3 = left.r3;
			}
		
			if(left.rightmax + right.leftmax > totalmax){
				totalmax = left.rightmax + right.leftmax; l3 = left.l2;
				if(l3 == -1) l3 = right.l1;
				r3 = right.r1;
				if(r3 == -1) r3 = left.r2;
			}
		
			if(right.totalmax > totalmax){
				totalmax = right.totalmax; l3 = right.l3; r3 = right.r3;
			}
		
			if(rightmax > totalmax){
				totalmax = rightmax; l3 = l2; r3 = r2;
			}
		}
		else if(left.totalmax > 0){
			leftmax = left.leftmax; rightmax = 0;
			
			totalmax = left.totalmax;
			
			l1 = left.l1; r1 = left.r1;
			l2 = r2 = -1;
			l3 = left.l3; r3 = left.r3;
		}
		else if(right.totalmax > 0){
			leftmax = 0;
			rightmax = right.rightmax;
			totalmax = right.totalmax;
			l1 = r1 = -1;
			l2 = right.l2; r2 = right.r2;
			l3 = right.l3; r3 = right.r3;
		}
		else{
			leftmax = rightmax = 0; totalmax = 0;
			l1 = r1 = -1; l2 = r2 = -1;	l3 = r3 = -1;
		}
	}
};

const int N = 1<<18;

int n, q, arr[N], x, y;
min_node seg_tree1[N*2];
one_node seg_tree2[N*2];

void initialize1(int i, int l, int r){
	if(l == r) seg_tree1[i].assignLeaf(arr[l],l);
	else{
		initialize1(2*i, l, (l+r)>>1); initialize1((2*i) + 1, ((l+r)>>1) + 1, r);
		min_node left = seg_tree1[2*i], right = seg_tree1[(2*i)+1];

		seg_tree1[i].merge(left, right);		
	}
	return;
}

void initialize2(int i, int l, int r){
	if(l == r){
		seg_tree2[i].assignLeaf(arr[l],l);
	}
	else{
		initialize2(2*i, l, (l+r)>>1); initialize2((2*i) + 1, ((l+r)>>1) + 1, r);
		one_node left = seg_tree2[2*i], right = seg_tree2[(2*i)+1];

		seg_tree2[i].merge(left, right);
	}
	return;
}

min_node query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)	return seg_tree1[i];
	
	int mid = (l+r)>>1;
	if(lo > mid) return query((i<<1)+1, mid+1, r, lo, hi);
	if(hi <= mid) return query(i<<1, l, mid, lo, hi);
										
	min_node left = query(i<<1, l, mid, lo, mid), right = query((i<<1)+1, mid+1, r, mid+1, hi);
	min_node result; result.merge(left, right);			
	
	return result;
}

one_node query2(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi) return seg_tree2[i];
	
	int mid = (l+r)>>1;
	if(lo > mid) return query2((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid) return query2(2*i, l, mid, lo, hi);
	
	one_node left = query2(i<<1, l, mid, lo, mid), right = query2((i<<1)+1, mid+1, r, mid+1, hi);
	one_node result; result.merge(left, right);			
	
	return result;
}
	
void updateMinNode(int i, int lo, int hi, int index, int value){
	if (lo == hi){
		seg_tree1[i].assignLeaf(value,lo);
		return;
	}
	int left = 2*i, right = left+1, mid = (lo+hi)>>1;
	if(index <= mid) updateMinNode(left, lo, mid, index, value); else updateMinNode(right, mid+1, hi, index, value);
	seg_tree1[i].merge(seg_tree1[left], seg_tree1[right]);
	return;
}	

void updateOneNode(int i, int lo, int hi, int index, int value){
	if (lo == hi){
		seg_tree2[i].assignLeaf(value,lo);
		return;
	}
	int left = 2*i, right = left+1, mid = (lo+hi)>>1;
	if(index <= mid) updateOneNode(left, lo, mid, index, value); else	updateOneNode(right, mid+1, hi, index, value);
	seg_tree2[i].merge(seg_tree2[left], seg_tree2[right]);
	return;
}	
	
int main(){
	sd2(n,q);
	for(int i = 0; i < n; i++){
		sd(arr[i]);
	}
	
	initialize1(1, 0, n-1); initialize2(1, 0, n-1);
	
	int tt;
	while(q--){
		sd(tt);
		if(tt == 1){
			sd2(x,y); x--, y--;
			min_node res = query(1, 0, n-1, x, y);
			if(res.min_val > 1)	printf("%d %d %d\n", res.min_val, res.interval+1, res.interval+1);
			else if(res.min_val == 0) printf("%d %d %d\n", 0, x+1, y+1);
			else{
				one_node res2 = query2(1, 0, n-1, x, y);
				printf("%d %d %d\n", 1, res2.l3+1, res2.r3+1);
			}
		}
		else{
			sd2(x,y); x--;
			updateMinNode(1, 0, n-1, x, y);
			updateOneNode(1, 0, n-1, x, y);
		}
	}
	
	return 0;
}
