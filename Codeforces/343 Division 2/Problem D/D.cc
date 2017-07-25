#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1<<18;

struct node{
	ll mx;
	void assign(ll value){
		mx = value;
	}
	void update(ll value){
		mx = max(mx, value);
	}
	void combine(node &left, node &right){
		mx = max(left.mx, right.mx);
	}
};

int n, a[N];
node tree[2*N];

ll vol[N];
ll id[N];
set<ll> comp;
int cnt;
map<ll, ll> f;

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

void update(int index, ll val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}


ll query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y or x >= y) return 0;
	if(x <= l && r <= y) return tree[id].mx;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return max(query(x, y, left, l, mid), query(x, y, right, mid, r));
}

int main(){ 
	sd(n);
	
	int r, h;
	for(int i = 0; i < n; i++){
		sd2(r,h);
		vol[i] = (((1ll*r)*1ll*r)*h);
		comp.insert(vol[i]);
	}
	
	foreach(it, comp){
		f[*it] = cnt++;
	}
	
	for(int i = 0; i < n; i++){
		id[i] = f[vol[i]];
	}
	
	build();
	ll ans = vol[0];
	update(id[0], vol[0]);
	for(int i = 1; i < n; i++){
		ll res = query(0,id[i]) + vol[i];
		ans = max(ans, res);
		update(id[i], res);
	}
	
	double PI = acos(-1);
	printf("%.11lf\n", PI*ans);
	
	return 0;
}
