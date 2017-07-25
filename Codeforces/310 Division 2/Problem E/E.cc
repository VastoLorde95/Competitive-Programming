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

const int N = 1<<20;

struct node{
	int mx;
	void assign(int val){
		mx = 0;
	}
	void update(int val){
		mx = max(mx, val);
	}
	void combine(node &left, node &right){
		mx = max(left.mx, right.mx);
	}
};

int n, q, x, y, f[N], comp;
char op;
set<int> c;
map<int,int> m;
vector<pair<int, pair<int, int> > > qr;

node tree1[2*N], tree2[2*N];
int lazy1[N], lazy2[N];

void build(int id = 1, int l = 0, int r = comp){
	if(l+1 == r){
		tree1[id].assign(0);
		tree2[id].assign(0);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree1[id].combine(tree1[left], tree1[right]);
	tree2[id].combine(tree2[left], tree2[right]);
	return;
}

void upd1(int id,int l,int r,int x){
	lazy1[id] = max(lazy1[id], x);
	tree1[id].update(x);
}

void shift1(int id,int l,int r){
	int mid = (l+r)/2;
	upd1(id * 2, l, mid, lazy1[id]);
	upd1(id * 2 + 1, mid, r, lazy1[id]);
	lazy1[id] = 0;
}

void update1(int x, int y, int val, int id = 1, int l = 0, int r = comp){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd1(id, l, r, val);
		return;
	}
	
	shift1(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update1(x, y, val, left, l, mid);
	update1(x, y, val, right, mid, r);
	
	tree1[id].combine(tree1[left], tree1[right]);
	return;
}

node query1(int index, int id = 1, int l = 0, int r = comp){
	if(l+1 == r) return tree1[id];

	shift1(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) return query1(index, left, l, mid);
	else return query1(index, right, mid, r);
}

//
void upd2(int id,int l,int r,int x){
	lazy2[id] = max(lazy2[id], x);
	tree2[id].update(x);
}

void shift2(int id,int l,int r){
	int mid = (l+r)/2;
	upd2(id * 2, l, mid, lazy2[id]);
	upd2(id * 2 + 1, mid, r, lazy2[id]);
	lazy2[id] = 0;
}

void update2(int x, int y, int val, int id = 1, int l = 0, int r = comp){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd2(id, l, r, val);
		return;
	}
	
	shift2(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update2(x, y, val, left, l, mid);
	update2(x, y, val, right, mid, r);
	
	tree2[id].combine(tree2[left], tree2[right]);
	return;
}

node query2(int index, int id = 1, int l = 0, int r = comp){
	if(l+1 == r) return tree2[id];

	shift2(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) return query2(index, left, l, mid);
	else return query2(index, right, mid, r);
}

int main(){
	sd2(n,q);
	for(int i = 0; i < q; i++){
		scanf(" %d %d %c",&y,&x,&op);
//		tr3(x,y,op);
		if(op == 'U') qr.pb(mp(0,mp(x,y))); 
		else qr.pb(mp(1,mp(x,y)));
		
		c.insert(x); 
		c.insert(y);
	}
	
	foreach(it, c){
		m[*it] = comp;
		f[comp++] = *it;
	}
	
	build();
	
	for(int i = 0; i < q; i++){
		if(qr[i].fi == 0){
			x = qr[i].se.fi, y = qr[i].se.se;
			int xx = m[x], yy = m[y];
			node nd = query2(yy);
			
			printf("%d\n", x - nd.mx);
			update1(m[nd.mx], xx+1, y);
			update2(yy, yy+1, x);
		}
		else{
			x = qr[i].se.fi, y = qr[i].se.se;
			int xx = m[x], yy = m[y];
			node nd = query1(xx);
			
			printf("%d\n", y - nd.mx);
			update2(m[nd.mx], yy+1, x);
			update1(xx, xx+1, y);
		}
	}
	
	return 0;
}
