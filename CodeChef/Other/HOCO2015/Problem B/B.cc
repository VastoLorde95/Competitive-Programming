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
	int mn, mx;
	void assign(int value){
		mx = value;
		mn = value;
	}
	void combine(node &left, node &right){
		mn = min(left.mn, right.mn);
		mx = max(left.mx, right.mx);
	}
};

int n, q, a[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

node query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y){
		node ret;
		ret.mn = 1e9;
		ret.mx = 0;
		return ret;
	}
	if(x <= l && r <= y) return tree[id];
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	node res, leftn = query(x, y, left, l, mid), rightn = query(x, y, right, mid, r);
	res.combine(leftn, rightn);
	return res;
}

int main(){
	sd2(n,q);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	build();
	while(q--){
		int x, y;
		sd2(x,y);
		node p = query(x,y+1);
		printf("%d\n", p.mx-p.mn);
	}
	return 0;
}
