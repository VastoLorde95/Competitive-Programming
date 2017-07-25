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

const int N = 1 << 18;
const ll MOD = 1e9 + 7;

ll res[2][2];

void mul(ll a[][2], ll b[][2]){
	res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD; 
	res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	
	a[0][0] = res[0][0], a[0][1] = res[0][1];
	a[1][0] = res[1][0], a[1][1] = res[1][1];
	
	return;
}

void fast(ll m[][2], ll b){
	ll ret[2][2];
	ret[0][0] = ret[1][1] = 1, ret[1][0] = ret[0][1] = 0;
	
	while(b){
		if(b&1) mul(ret, m);
		mul(m, m);
		b >>= 1;
	}
	
	m[0][0] = ret[0][0];
	m[0][1] = ret[0][1];
	m[1][0] = ret[1][0];
	m[1][1] = ret[1][1];
}

ll tmp[2][2];

struct node{
	int sum1 = 0, sum2 = 0;
	bool small = false;
	
	void assign(int value){
		if(value == 1){
			small = true;
			sum1 = 1, sum2 = 0;
		}
		else{
			small = false;
			tmp[0][0] = tmp[0][1] = tmp[1][0] = 1, tmp[1][1] = 0;
		
			fast(tmp, value-1);
		
			sum1 = tmp[0][0];
			sum2 = tmp[0][1];
		}
	}
	void update(ll &v1, ll &v2){
		if(small){
			small = false;
			sum1 = v1;
			sum2 = v2;
			return;
		}
		int t1 = (v1 * sum1 + v2 * sum2) % MOD;
		int t2 = (v1 * sum2 + v2 * (sum1-sum2)) % MOD; if(t2 < 0) t2 += MOD;
		sum1 = t1, sum2 = t2;
	}
	
	void combine(node &left, node &right){
		sum1 = (left.sum1 + right.sum1); if(sum1 >= MOD) sum1 -= MOD;
		sum2 = (left.sum2 + right.sum2); if(sum2 >= MOD) sum2 -= MOD;
	}
};

int n, m, a[N];
ll lazy[N];
ll f1[N][2][2], f2[N][2][2];
node tree[N];

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

void upd(int id,int l,int r, ll a, ll b){
	tree[id].update(a, b);
	lazy[id] = 1;
	
	mul(f1[id], tmp);
	mul(f2[id], tmp);
}

void reset(ll m[][2]){
	m[0][0] = m[1][1] = 1;
	m[1][0] = m[0][1] = 1;
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(lazy[id] and l+1 < r){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, f1[id][0][0], f2[id][0][1]);
		upd(id * 2 + 1, mid, r, f1[id][0][0], f2[id][0][1]);
		lazy[id] = 0,
		
		reset(f1[id]);
		reset(f2[id]);
	}
}

void update(int x, int y, ll a, ll b, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, a, b);
		return;
	}
	
	shift(id, l, r); // pass the updates to the children
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(x, y, a, b, left, l, mid); 
	update(x, y, a, b, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].sum1;
	
	shift(id, l, r);	//use this with lazy propogation
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	ll tot = query(x, y, left, l, mid) + query(x, y, right, mid, r);
	if(tot >= MOD) tot -= MOD;
	
	return tot;
}

int main(){ _
	for(int i = 0; i < N; i++){
		reset(f1[i]);
		reset(f2[i]);
	}	
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	build();

	int t, l, r, x;
	while(m--){
		cin >> t >> l >> r;
		l--, r--;
		
		if(t == 1){
			cin >> x;
			tmp[0][0] = tmp[0][1] = tmp[1][0] = 1, tmp[1][1] = 0;
			fast(tmp, x);
			
			update(l, r+1, tmp[0][0], tmp[0][1]);
		}
		else{
			cout << query(l, r+1, tmp[0][0], tmp[0][1]) << '\n';
		}
	}	
	
	return 0;
}
