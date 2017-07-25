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

const int N = 100100;
const int INF = 1e9;

struct FenwickRMQ{
	vector<int> tree;
	vector<int> v;
	int n;
	
	void add(int x){
		v.pb(x);
	}
	
	void init(){
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end())	- v.begin());
		n = v.size();
		tree.resize(n+1, INF);
	}
	
	int id(int x){
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	
	int query(int x) {
		int res = INF;
		for(x = id(x); x; x -= x & -x) res = min(res, tree[x]);
		return res;
	}

	void update(int x, int v) {
		for(x = id(x); x <= n; x += x & -x) tree[x] = min(tree[x], v);
	}	
	
};

FenwickRMQ segmentTree[2*N];

int n, d, k;
vector<pair<pii, int> > segments[N];

int l[N], r[N];
int ans[N];

void build(int x, int v){
	for(x += d; x; x >>= 1) segmentTree[x].add(v);
}

void update(int x, int y, int v){
	for(x += d; x; x >>= 1){
		segmentTree[x].update(y, v);
	}
}

int get(int x, int y){
	int res = INF;
	for(int p = x + d, q = y + d; p < q ; p >>= 1, q >>= 1){
		if((p&1)) res = min(res, segmentTree[p++].query(y));
		if((q&1)) res = min(res, segmentTree[--q].query(y));
	}
	return res;
}

int query(int x, int y, int len){
	if(y-x+1 < len) return 0;
	int id = get(x, y);
	if(id == INF) return 0;
	int ret = r[id] - l[id] + 1;
	return ret + query(x, l[id]-1, len) + query(r[id]+1, y, len);
}

int main(){
	sd3(n,d,k);
	
	for(int i = 1; i <= n; i++){
		sd2(l[i], r[i]);
		segments[r[i] - l[i] + 1].pb(mp(mp(l[i],r[i]),i));
		build(l[i], r[i]);
	}		
	
	for(int i = 1; i <= d; i++){
		sort(segments[i].begin(), segments[i].end());
	}
	
	for(int i = 0; i < 2*N; i++){
		segmentTree[i].init();
	}

	for(int i = d; i; i--){
		if(segments[i].empty()){
			ans[i] = ans[i+1];
			continue;
		}
		
		foreach(it, segments[i]){
			int x = it->fi.fi, y = it->fi.se, v = it->se;
			update(x, y, v);
		}
		
		ans[i] = query(1, d, i);
	}
			
	while(k--){
		int x; sd(x);
		printf("%d\n", ans[x]);
	}	
		
	return 0;
}
