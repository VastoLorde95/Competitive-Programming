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

typedef long long ll;

const int N = 1<<18;

struct node{
	ll val;
	void assign(){
		val = 0;
	}
	void update(ll value){
		val = (value > val)? value : val;
	}
	void combine(node &left, node &right){
		val = (left.val > right.val)? left.val : right.val;
	}
};

int t, n;
pair<int, int> a[N];
node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign();
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void update(int index, ll val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].update(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

ll query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].val;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return max(query(x, y, left, l, mid),query(x, y, right, mid, r));
}

set<int> c;
map<int, int> f;

int main(){
	sd(t);
	while(t--){
		sd(n);
		build();
		
		c.clear();
		f.clear();
		
		for(int i = 0; i < n; i++){
			sd(a[i].fi);
			c.insert(a[i].fi);
		}
		for(int i = 0; i < n; i++){
			sd(a[i].se);
		}
		
		int cnt = 0;
		ll ans = 0, tmp;
		
		foreach(it, c){
			f[*it] = cnt++;
		}
		
		for(int i = n-1; i >= 0; i--){
			tmp = query(f[a[i].fi]+1, n) + a[i].se;
			ans = max(ans, tmp);			
			update(f[a[i].fi], tmp);
		}
		
		printf("%lld\n", ans);
		
	}
	return 0;
}
