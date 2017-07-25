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

int n, m, a[N];

struct node{
	long long sum;
	int mx;
	void assign(int indx){
		sum = a[indx], mx = indx;
	}
	void combine(node &left, node &right){
		sum = left.sum + right.sum;
		mx = (a[left.mx] > a[right.mx])? left.mx : right.mx;
	}
};

node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(l);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

long long query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
//	tr4(x,y,l,r);
	if(x <= l && r <= y){
//		tr2("yo", tree[id].sum);
		return tree[id].sum;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return query(x, y, left, l, mid) + query(x, y, right, mid, r);
}

int query2(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return -1;
	if(x <= l && r <= y){
		return tree[id].mx;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	int i1 = query2(x, y, left, l, mid), i2 = query2(x, y, right, mid, r);
	if(i1 == -1) return i2;
	if(i2 == -1) return i1;
	if(a[i1] > a[i2]) return i1; else return i2;
}


void update(int index, int mod, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		a[l] %= mod;
		tree[id].assign(l);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, mod, left, l, mid);
	else update(index, mod, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

void update2(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		a[l] = val;
		tree[id].assign(l);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update2(index, val, left, l, mid);
	else update2(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++) sd(a[i]);
	
	build();
	
	while(m--){
		int type; sd(type);
		
		if(type == 1){
			int l, r; sd2(l,r);
//			tr3(1,l,r);
			printf("%I64d\n", query(l-1,r));
		}
		else if(type == 2){
			int l, r, x; sd3(l,r,x);
			while(true){
				int mx = query2(l-1,r);
				if(a[mx] < x) break;
				
//				tr6("try", a[mx], mx, l, r,x);	
				
				update(mx, x);
			}
		}
		else{
			int k, x; sd2(k,x);
			update2(k-1,x);
		}
	}
	return 0;
}
