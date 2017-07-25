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

const int N = 1<<18;

struct node{
	long long val;
	void assign(long long value){
		val = value;
	}
	void update(long long value){
		val = value;
	}
	void combine(node &left, node &right){
		val = max(left.val, right.val);
	}
};

int n, m;
long long a[N], lazy[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	lazy[id] = -1;
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(int id,int l,int r,long long x){ //	update the current node and its index in the lazy array
	lazy[id] = x;
	tree[id].update(x);
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(lazy[id] == -1) return; // nothing to pass
	int mid = (l+r)/2;
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = -1; // passing is done, reset the index in the lazy array
}

// range update -> update(x, y, val);
void update(int x, int y, long long val, int id = 1, int l = 0, int r = n){
//	tr4(x,y,l,r);
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
//		tr2("Updating",tree[id].val);
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

// range query -> query(x, y);
long long query(int x, int y, int id = 1, int l = 0, int r = n){
//	tr4(x,y,l,r);
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y){
//		tr2("Returning",tree[id].val);
		return tree[id].val;
	}
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return max(query(x, y, left, l, mid), query(x, y, right, mid, r));
}

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	build();
	
	cin >> m;
	while(m--){
		int w, h; cin >> w >> h;
		
		long long btm = query(0, w);
		cout << btm << "\n";
		
		
		update(0, w, btm+h);
	}
	
	return 0;
}
