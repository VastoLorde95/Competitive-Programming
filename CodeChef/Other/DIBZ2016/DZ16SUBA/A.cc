#include <bits/stdc++.h>
 
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
 
#define func __FUNCTION__
#define line __LINE__
 
using namespace std;
 
template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}
 
template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}
 
void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}
 
const int N = 1<<20;
const int M = 30;
 
int n, q;
int a[N], p[N];
 
struct node{
	int cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt = value;
	}
	void combine(node &left, node &right){
		cnt = left.cnt|right.cnt;
	}
};

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

// range query -> query(x, y);
int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].cnt;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return (query(x, y, left, l, mid)|query(x, y, right, mid, r));
}
 
int MOD = 1e9 + 7;
 
int main(){
	sd2(n, q);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}

	build();
	
	p[0] = 1;
	for(int i = 1; i < N; i++){
		p[i] = 2*p[i-1];
		if(p[i] >= MOD) p[i] -= MOD;
	}	
	
	int t, l, r;
	for(int i = 0; i < q; i++){
		sd3(t,l,r);
		if(t == 1){
			int ans = 0;
			int res = query(l-1,r);

			for(int j = 0; j < M; j++){
				if((res&p[j]) > 0){
					ans += p[j+r-l];
					if(ans >= MOD) ans -= MOD;
				}
			}			
			
			printf("%d\n", ans);
		}
		else
			update(l-1, r);
	}
	
	return 0;
}
