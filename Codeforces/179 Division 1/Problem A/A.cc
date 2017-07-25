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

const long long N = 1<<18;

struct node{
	long long sum;
	void assign(long long value){
		sum = value;
	}
	void update(long long value){
		sum += value;
	}
	void combine(node &left, node &right){
		sum = left.sum + right.sum;
	}
};

long long n, m, k;
long long a[N], lazy[N];
pair<long long, pair<long long, long long> > o[N];
long long cnt[N];
node tree[2*N];

// [l, r)
void build(long long id = 1, long long l = 0, long long r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	long long left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range update and  utility functions
void upd(long long id,long long l,long long r,long long x){ //	update the current node and its index in the lazy array
	lazy[id] += x;
	tree[id].update(x*(r - l));
}

void shift(long long id,long long l,long long r){ //propogate update information to the children
	long long mid = (l+r)/2;
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = 0; // passing is done, reset the index in the lazy array
}

// range update -> update(x, y, val);
void update(long long x, long long y, long long val, long long id = 1, long long l = 0, long long r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	long long left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// point query -> query(index)
long long query(long long index, long long id = 1, long long l = 0, long long r = n){
	
	if(l+1 == r){
		return tree[id].sum;
	}
	
	shift(id, l, r);
	
	long long left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) return query(index, left, l, mid);
	else return query(index, right, mid, r);
	
}

int main(){ _
	cin >> n >> m >> k;
	for(long long i = 0; i < n; i++) cin >> a[i];
	
	build();
	
	for(long long i = 1; i <= m; i++){
		long long x, y, d; cin >> x >> y >> d;
		o[i] = mp(d,mp(x,y));
	}
	for(long long i = 0; i < k; i++){
		long long x, y; cin >> x >> y;
		cnt[x]++;
		cnt[y+1]--;
	}
	for(long long i = 1; i <= m; i++){
		cnt[i] += cnt[i-1];
		update(o[i].se.fi-1, o[i].se.se, (long long) (cnt[i]*o[i].fi));
	}
	
	for(long long i = 0; i < n; i++){
		cout << query(i) << " ";
	}
	cout << "\n";
	
	return 0;
}
