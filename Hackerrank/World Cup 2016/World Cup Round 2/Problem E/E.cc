#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int N = 1<<19;

struct node{
	int cnt, indx;
	void assign(int value, int id){
		cnt = value;
		indx = id;
	}
	
	void update(int val){
		cnt += val;
	}
	
	void combine(node &left, node &right){
		if(left.cnt >= right.cnt){
			cnt = left.cnt;
			indx = left.indx;
		}
		else{
			cnt = right. cnt;
			indx = right.indx;
		}
	}
};

int n, a[N], lazy[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].cnt = 0;
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(int id,int l,int r, int x){ //	update the current node and its index in the lazy array
	lazy[id] += x;
	tree[id].update(x);
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(lazy[id]){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0; // passing is done, reset the index in the lazy array
	}
}

// point update -> update(index);
void update(int index, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(0, index);
		return;
	}
		
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, left, l, mid);
	else update(index, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

// range update -> update(x, y);
void update2(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, 1);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update2(x, y, left, l, mid);
	update2(x, y, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
pair<int,int> query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return mp(0,0);
	if(x <= l && r <= y) return mp(tree[id].cnt, tree[id].indx);
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	pair<int, int> p1 = query(x, y, left, l, mid), p2 = query(x, y, right, mid, r);
	if(p1.fi >= p2.fi) return p1;
	return p2;
}

int main(){
	sd(n);
	
	if(n == 1){
		printf("Cool Array\n"); return 0;
	}
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	int res = -1;
	
	int start = -1, end = -1;
	
	build();
	
	update(a[0]-1);
	update2(a[0]-1, n);
	
	for(int i = 1; i < n; i++){
		update(a[i]-1);
		update2(a[i]-1, n);
		pair<int,int> p = query(a[i],n);
		
		tr3(i, p.fi, p.se);
		
		if(p.fi > res){
			start = p.se+1, end = i+1; res = p.fi;
		}
	}
	
	if(res == -1){
		printf("Cool Array\n"); return 0;
	}
	else{
		printf("%d %d\n", start, end);
	}
	
	return 0;
}
