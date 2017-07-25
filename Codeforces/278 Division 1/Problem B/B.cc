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

const long double PI = 3.1415926535897932384626433832795;

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

const int LOGN = 18;
const int N = 1 << LOGN;
const int inf = 1e9;

struct node{
	int cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt = value;
	}
	void combine(node &left, node &right){
		cnt = min(left.cnt, right.cnt);
	}
};

int n, s, l;
int a[N], lazy[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(inf);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void update(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].update(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return inf;
	if(x <= l && r <= y) return tree[id].cnt;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return min(query(x, y, left, l, mid), query(x, y, right, mid, r));
}

int sp1[LOGN][1<<LOGN], sp2[LOGN][1<<LOGN], k[1<<LOGN], o[1<<LOGN];

void sparseTable(){
	for(int i = 0; i < n; i++){
		sp1[0][i] = sp2[0][i] = a[i];
	}
	
	for(int j = 1; j < LOGN; j++){
		for(int i = 0; (i+(1<<j)-1) < n; i++){
			sp1[j][i] = max(sp1[j-1][i], sp1[j-1][i+(1<<(j-1))]);
			sp2[j][i] = min(sp2[j-1][i], sp2[j-1][i+(1<<(j-1))]);
		}
	}
	
	for(int i = 2; i <= n; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
		if(k[i] == k[i-1]) o[i] = o[i-1];
		else o[i] = ((o[i-1]+1)<<1)-1;
	}
	
	return;
}

int mxq(int x, int y){
	int l = y-x+1;
	return max(sp1[k[l]][x], sp1[k[l]][y-o[l]]);
}

int mnq(int x, int y){
	int l = y-x+1;
	return min(sp2[k[l]][x], sp2[k[l]][y-o[l]]);
}

int get(int r){
	int lo = -1, hi = r, mid;
	while(lo+1 < hi){
		mid = (lo+hi)/2;
		if(mxq(mid,r) - mnq(mid,r) > s) lo = mid;
		else hi = mid;
	}
	return hi;
}

int main(){
	sd3(n,s,l);
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	int mn = 1e9, mx = -1e9;
	for(int i = 0; i < l; i++){
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	
	if(mx - mn > s or n < l){
		puts("-1");
		return 0;
	}
	
	sparseTable();
	
	build();
	
	update(l-1, 1);
	for(int i = l; i < n; i++){
		int y = i-l;
		int x = get(i);
		x--;
		
		if(x > y){
			update(i, inf);
		}
		else{
			if(x == -1){
				update(i, 1);
				continue;
			}
			int v = query(x, y+1);
			update(i, v + 1);
		}
	}
	
	int res = query(n-1, n);
	if(res == inf) res = -1;
	printf("%d\n", res);
		
	
	return 0;
}
