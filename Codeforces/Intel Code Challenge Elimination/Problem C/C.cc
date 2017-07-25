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

const int N = 1 << 19;
const ll INF = (1ll << 50);

struct node{
	ll sum, leftsum, rightsum, mx;
	void assign(ll value){
		sum = leftsum = rightsum = mx = value;
	}
	void update(ll value){
		sum = leftsum = rightsum = mx = value;
	}
	void combine(node &left, node &right){
		sum = left.sum + right.sum;
		
		leftsum = max(left.leftsum, left.sum + right.leftsum);
		rightsum = max(right.rightsum, right.sum + left.rightsum);
		
		mx = max(left.mx, right.mx);
		mx = max(mx, max(leftsum, rightsum));
		mx = max(mx, sum);
		mx = max(mx, left.rightsum + right.leftsum);
		
		if(mx < -INF) mx = -INF;
		if(sum < -INF) sum = -INF;
		if(leftsum < -INF) leftsum = -INF;
		if(rightsum < -INF) rightsum = -INF;
	}
};

ll n, a[N];
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


int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	build();
	
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		x--;
		update(x, -INF);
		cout << max(tree[1].mx, 0ll) << '\n';
	}
	
	return 0;
}
