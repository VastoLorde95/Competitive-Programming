#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 1 << 17;

struct node{
	bool inc, dec;
	int mx;
	ll sum;
	int left, right;
	
	void assign(int value){
		inc = dec = true;
		mx = sum = value;
		left = right = value;
	}
	void update(int value){
		inc = dec = true;
		mx = sum = value;
		left = right = value;
	}
	void combine(node &left, node &right){
		sum = left.sum + right.sum;
		mx = max(left.mx, right.mx);
		
		inc = (left.right <= right.left and left.inc and right.inc);
		dec = (left.right >= right.left and left.dec and right.dec);
		
		this->left = left.left;
		this->right = right.right;
		
	}
};

int n, m, a[N];
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

// point update -> update(index, value);
void update(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

int mxquery(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].mx;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return max(mxquery(x, y, left, l, mid), mxquery(x, y, right, mid, r));
}

ll sumquery(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].sum;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return sumquery(x, y, left, l, mid) + sumquery(x, y, right, mid, r);
}

node incquery(int x, int y, int id = 1, int l = 0, int r = n){
	node ret;
	if(x >= r or l >= y){
		ret.left = 1e9;
		ret.right = -1e9;
		ret.inc = true;
		return ret;
	}
	if(x <= l && r <= y) return tree[id];
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	node a = incquery(x, y, left, l, mid), b = incquery(x, y, right, mid, r);
	
	ret.combine(a, b);
	
	return ret;
}

node decquery(int x, int y, int id = 1, int l = 0, int r = n){
	node ret;
	if(x >= r or l >= y){
		ret.right = 1e9;
		ret.left = -1e9;
		ret.dec = true;
		return ret;
	}
	if(x <= l && r <= y) return tree[id];
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	node a = decquery(x, y, left, l, mid), b = decquery(x, y, right, mid, r);
	
	ret.combine(a, b);
	
	return ret;
}

int main(){ _
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	build();
	
	while(m--){
		char c;
		cin >> c;
		
		int x, y;
		cin >> x >> y;
		
		if(c == 'U'){
			update(x-1, y);
		}
		else if(c == 'M'){
			cout << mxquery(x-1, y) << '\n';
		}
		else if(c == 'S'){
			cout << sumquery(x-1, y) << '\n';
		}
		else if(c == 'I'){
			cout << ((incquery(x-1, y).inc)? 1 : 0) << '\n';
		}
		else if(c == 'D'){
			cout << ((decquery(x-1, y).dec)? 1 : 0) << '\n';
		}
	}
	
	
	return 0;
}
