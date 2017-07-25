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

const int N = 1<<17;

struct node{
	long long s1, s2;
	void assign(long long value){
		s1 = value*value, s2 = value;
	}
	void update(long long value, int k){
		s1 = s1 + value*s2*2 + value*value*k;
		s2 = s2 + value*k;
	}
	
	void update2(long long val, int k){
		s1 = val*val*k;
		s2 = val*k;
	}
	
	void combine(node &left, node &right){
		s1 = left.s1 + right.s1;
		s2 = left.s2 + right.s2;
	}
};

int t, n, q;
int a[N], lazy[N], lazy2[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		lazy[id] = lazy2[id] = 0;
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(int id,int l,int r, long long x){ //	update the current node and its index in the lazy array
	lazy[id] += x;
	tree[id].update(x, r-l);
}

void shift(int id,int l,int r){ //propogate update information to the children
	int mid = (l+r)/2;
	
	if(lazy2[id] > 0){
		tree[id*2].update2(lazy2[id], mid-l);
		lazy[id*2] = 0;
		tree[id*2 + 1].update2(lazy2[id], r-mid);
		lazy[id*2 + 1] = 0;
	}
	
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	
	lazy[id] = 0; // passing is done, reset the index in the lazy array
	lazy2[id] = 0;
}

// range update -> update(x, y, val);
void update(int x, int y, long long val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void update2(int x, int y, long long val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		lazy2[id] = x;
		lazy[id] = 0;
		tree[id].update2(val, r-l);
		
//		tr3(l, r, tree[id].s1);
		
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update2(x, y, val, left, l, mid);
	update2(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
long long query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].s1;
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return query(x, y, left, l, mid) + query(x, y, right, mid, r);
}

int main(){
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case %d:\n",i);
		sd2(n,q);
		for(int i = 0; i < n; i++){
			sd(a[i]);
		}
		
		build();
		int type, x, y, val;
		while(q--){
			sd3(type, x, y);
			if(type == 2){
				printf("%lld\n", query(x-1,y));
			}
			else if(type == 1){
				sd(val);
				update(x-1,y,val);
			}
			else{
				sd(val);
				update2(x-1,y,val);
			}
		}
	}
	return 0;
}
