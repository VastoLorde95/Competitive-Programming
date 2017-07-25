#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int LOGN = 17;
const int N = 1 << LOGN;

struct node{
	vector<int> v;
	void assign(vector<int> &vv){
		v = vv;
	}
	
	void combine(node &left, node &right){
		vector<int> &x = left.v;
		vector<int> &y = right.v;
		int i = 0, j = 0;
		while(i != x.size() and j != y.size()){
			if(x[i] < y[j]) v.pb(x[i++]);
			else v.pb(y[j++]);
		}
		
		if(i == x.size()){
			v.insert(v.end(), y.begin() + j, y.end());
		}
		else if(j == y.size()){
			v.insert(v.end(), x.begin() + i, x.end());
		}
	}
};

int n;
node tree1[2*N], tree2[2*N];

vector<int> a[N], b[N];

void build(int id = 1, int l = 1, int r = n){
	if(l == r){
		tree1[id].assign(a[l]);
		tree2[id].assign(b[l]);
		return;
	}
	
	int mid = (l + r) >> 1;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	
	tree1[id].combine(tree1[2*id], tree1[2*id+1]);
	tree2[id].combine(tree2[2*id], tree2[2*id+1]);
}

int query1(int x, int y, int id = 1, int l = 1, int r = n){
	if(y < l or r < x) return 0;
	if(x <= l and r <= y){
		return upper_bound(tree1[id].v.begin(), tree1[id].v.end(), y) - tree1[id].v.begin();
	}
	
	int mid = (l + r) >> 1;
	return query1(x, y, 2 * id, l, mid) + query1(x, y, 2 * id + 1, mid+1 , r);
}

int query2(int x, int y, int id = 1, int l = 1, int r = n){
	if(y < l or r < x) return 0;
	if(x <= l and r <= y){
		return upper_bound(tree2[id].v.begin(), tree2[id].v.end(), y) - tree2[id].v.begin();
	}
	
	int mid = (l + r) >> 1;
	return query2(x, y, 2 * id, l, mid) + query2(x, y, 2 * id + 1, mid+1 , r);
}

int q, nxt[N], vis[N];
vector<int> cycles;

void dfs(int x, int c){
	if(vis[x]){
		if(vis[x] != c) return;
		cycles.pb(x);
		return;
	}
	vis[x] = c;
	dfs(nxt[x], c);
}

int main(){
	sd2(n,q);
	
	for(int i = 1; i <= n; i++) sd(nxt[i]);
	
	for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, i);
	
	for(int i = 1; i <= n; i++){
		int x = i, y = nxt[i];
		if(x > y) swap(x,y);
		a[x].pb(y);
	}
	
	foreach(it, cycles){
		int mn = 1e9, mx = 0, i = *it;
		do{
			mn = min(mn, i);
			mx = max(mx, i);
			i = nxt[i];
		} while(i != *it);
		
		b[mn].pb(mx);
	}
	
	for(int i = 1; i <= n; i++){
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
	}
	
	build();
	
	int l, r;
	while(q--){
		sd2(l,r);
		printf("%d\n", r - l + 1 - query1(l,r) + query2(l, r));
	}
	
	return 0;
}
