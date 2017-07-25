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
	int val;
	void assign(int value){
		val = value;
	}
	void update(int value){
		val = value;
	}
	void combine(node &left, node &right){
		val = left.val;
	}
};

int n, m, a[N], b[N], lazy[N];
bool pass[N];
node tree[2*N];
vector<pair<int, pair<int, int> > > queries;

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(-1);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(int id,int l,int r,int x){ //	update the current node and its index in the lazy array
	lazy[id] = x; pass[id] = true;
	tree[id].update(x);
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(!pass[id]) return;
	int mid = (l+r)/2;
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = 0; // passing is done, reset the index in the lazy array
	pass[id] = false;
}

// range update -> update(x, y, val);
void update(int x, int y, int val, int id = 1, int l = 0, int r = n){
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

int query(int index, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		return tree[id].val;;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) return query(index, left, l, mid);
	else return query(index, right, mid, r);
}

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++) sd(a[i]);
	for(int i = 0; i < n; i++) sd(b[i]);
	for(int i = 0; i < N; i++) pass[i] = false;
	
	build();
	
	int cnt = 0;
	while(m--){
		int t; sd(t);
		if(t == 1){
			int x, y, k; sd3(x, y, k);
			x--, y--;
			queries.pb(mp(k, mp(x,y)));
			update(y, y+k, cnt);
			cnt++;
		}
		else{
			int x, y; sd(x); x--;
			y = query(x); 
			
			if(y == -1) printf("%d\n", b[x]); else printf("%d\n", a[queries[y].se.fi + x-queries[y].se.se]);
		}	
	}
	
	return 0;
}
