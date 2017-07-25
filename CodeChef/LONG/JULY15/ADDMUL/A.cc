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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 1<<18;
long long MOD = 1e9 + 7;

struct node{
	long long sum;
	void assign(long long value){
		sum = value;
	}
	void update(long long value){
		sum = (sum + value)%MOD;
	}
	void update2(long long k){
		sum = (sum * k)%MOD;
	}
	void update3(long long value){
		sum = value;
	}
	void combine(node &left, node &right){
		sum = (left.sum + right.sum)%MOD;
	}
};

int n, q;
int a[N];
long long lazy1[N], lazy2[N], lazy3[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	lazy2[id] = 1;
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd1(int id, int l, int r, long long x){
	lazy1[id] = (lazy1[id] + x)%MOD;
	tree[id].update((x*(r-l))%MOD);
}

void upd2(int id, int l, int r, long long x){
	if(lazy1[id] > 0){
		lazy1[id] = (lazy1[id] * x)%MOD;
	}
	lazy2[id] = (lazy2[id] * x)%MOD;
	tree[id].update2(x);
}

void upd3(int id, int l, int r, long long x){
	lazy1[id] = 0, lazy2[id] = 1, lazy3[id] = x;
	tree[id].update3((x*(r-l))%MOD);
}

void shift(int id, int l, int r){
	int mid = (l+r)/2;
	if(lazy3[id] > 0){
		upd3(id * 2, l, mid, lazy3[id]);
		upd3(id * 2 + 1, mid, r, lazy3[id]);
		lazy3[id] = 0;
	}
	if(lazy2[id] > 0){
		upd2(id * 2, l, mid, lazy2[id]);
		upd2(id * 2 + 1, mid, r, lazy2[id]);
		lazy2[id] = 1;
	}
	
	upd1(id * 2, l, mid, lazy1[id]);
	upd1(id * 2 + 1, mid, r, lazy1[id]);
	lazy1[id] = 0;
}

void update(int x, int y, long long val, int type, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		if(type == 1) upd1(id, l, r, val);
		else if(type == 2) upd2(id, l, r, val);
		else if(type == 3) upd3(id, l, r, val);
		
//		tr6(id, l, r, val, type, tree[id].sum);
		
		return;
	}
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, val, type, left, l, mid);
	update(x, y, val, type, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

long long query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].sum;
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return (query(x, y, left, l, mid) + query(x, y, right, mid, r))%MOD;
}


int main(){
	sd2(n,q);
	for(int i = 0; i < n; i++) sd(a[i]);
	
	build();
	
	while(q--){
		int type, x, y, v;
		sd(type);
		if(type <= 3){
			sd3(x,y,v);
			update(x-1,y,v,type);
		}
		else{
			sd2(x,y);
			printf("%lld\n", query(x-1,y));
		}
		
//		for(int i = 0; i < n; i++){
//			tr3("check",i, query(i,i+1));
//		}
//		cout << endl;
	}
	
	return 0;
}
