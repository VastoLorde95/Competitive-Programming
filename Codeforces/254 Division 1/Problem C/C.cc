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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 1<<18;

struct node{
	ll cnt;
	void assign(ll value){
		cnt = value;
	}
	void update(ll value){
		cnt += value;
	}
	void combine(node &left, node &right){
		cnt = left.cnt + right.cnt;
	}
};

int n, m;
ll lazy[N];
node tree[2*N];
set<pair<pii, int> > s;
set<pair<pii, int> >::iterator it;

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(0);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void upd(int id, int l, int r, ll x){
	lazy[id] += x;
	tree[id].update(x * (r - l));
}

void shift(int id,int l,int r){
	if(lazy[id]){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0;
	}
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

ll query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].cnt;
	
	shift(id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return query(x, y, left, l, mid) + query(x, y, right, mid, r);
}

int main(){
	sd2(n,m);
	
	build();
	
	for(int i = 0; i < n; i++) s.insert(mp(mp(i,i), i+1));
	
	vector<pair<pii, int> > v1, v2;
	int type, l, r, x, inf = 1e9;
	while(m--){
		sd3(type,l,r);
		l--, r--;
		if(type == 1){
			sd(x);
			it = s.upper_bound(mp(mp(l,inf),0));
			if(it != s.begin()) it--;
			
			v1.clear();
			v2.clear();
			
			v1.pb(mp(mp(l,r),x));
			while(it != s.end()){
				int a = it->fi.fi, b = it->fi.se, c = it->se;
				if(a < l and b > r){
					v1.pb(mp(mp(a,l-1),c));
					v1.pb(mp(mp(r+1,b),c));
					update(l,r+1,abs(x-c));
				}
				else if(a < l){
					v1.pb(mp(mp(a,l-1),c));
					update(l, b+1, abs(x-c));
				}
				else if(a <= r and b > r){
					v1.pb(mp(mp(r+1,b), c));
					update(a,r+1,abs(x-c));
				}
				else if(a <= r){
					update(a,b+1,abs(x-c));
				}
				else{
					break;
				}
				v2.pb(*it);
				it++;
			}
			
			foreach(it, v2) s.erase(*it);
			foreach(it, v1) s.insert(*it);
		}
		else{
			printf("%I64d\n", query(l, r+1));
		}
	}
	
	return 0;
}
