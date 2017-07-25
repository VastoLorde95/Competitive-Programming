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

const int N = 1 << 20;
const int INF = 1e9;

struct node{
	int l1, l2, mx;
	void assign(int value){
		l1 = l2 = value;
		mx = max(l1, l2);
	}
	void update(int value, int type){
		if(type == 0) l1 = value;
		else l2 = value;
		mx = max(l1, l2);
	}
	void combine(node &left, node &right){
		mx = max(left.mx, right.mx);
		mx = max(mx, left.l1 + right.l2);
		
		l1 = max(left.l1, right.l1);
		l2 = max(left.l2, right.l2);
	}
};

int n, m, cnt;
node tree[2*N];

void build(int id = 1, int l = 0, int r = cnt){
	if(l + 1 == r) return tree[id].assign(0);
	
	int left = id << 1, right = left + 1, mid = (l+r) >> 1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void update(int index, int val, int type, int id = 1, int l = 0, int r = cnt){
	if(l + 1 == r) return tree[id].update(val, type);
	
	int left = id << 1, right = left + 1, mid = (l+r) >> 1;
	
	if(index < mid) update(index, val, type, left, l, mid);
	else update(index, val, type, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

int h[N];
int ans[N];

set<int> comp;
map<int, int> f;

vector<pii> queries[N];

pii backup[N];
int l[N], prevl[N];

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		sd(h[i]);
		comp.insert(h[i]);
	}
	
	for(int i = 1; i <= m; i++){
		int a, b;
		sd2(a, b);
		queries[a].pb(mp(b,i));
		comp.insert(b);
	}
	
	foreach(it, comp) f[*it] = ++cnt;
	
	for(int i = 1; i <= n; i++) h[i] = f[h[i]];
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < queries[i].size(); j++)
			queries[i][j].fi = f[queries[i][j].fi];
	

	vector<int> lis1(n + 1, +INF);
	vector<int> lis2(n + 1, -INF);
	
	for(int i = n; i > 0; i--){
		int j = upper_bound(lis2.begin(), lis2.end(), h[i]) - lis2.begin(); j--;
		int k = upper_bound(lis2.begin(), lis2.end(), INF) - lis2.begin();
		
		backup[i] = mp(lis2[j], j);
		prevl[i] = l[h[i]];
		l[h[i]] = k - j;
		lis2[j] = h[i];
	}
	
	build();
	
	for(int i = 1; i <= cnt; i++){
		update(i-1, l[i], 1);
	}
	
	
	for(int i = 1; i <= n; i++){
		int next_val = backup[i].fi;
		int indx = backup[i].se;
		int cur_val = lis2[indx];
		int k = upper_bound(lis2.begin(), lis2.end(), INF) - lis2.begin();
		
		if(cur_val != -INF){
			l[cur_val] = prevl[i];
			update(cur_val-1, l[cur_val], 1);
		}
		if(next_val != -INF){
			l[next_val] = k-indx;
			update(next_val-1, k-indx, 1);
		}
		lis2[indx] = next_val;
		
		for(int j = 0; j < queries[i].size(); j++){
			int x = queries[i][j].fi, id = queries[i][j].se;
			
			int len1 = lower_bound(lis1.begin(), lis1.end(), x) - lis1.begin();
			int len2 = upper_bound(lis2.begin(), lis2.end(), x) - lis2.begin();
			int len3 = upper_bound(lis2.begin(), lis2.end(), INF) - lis2.begin();
			len2 = (len3 - len2);
			
			ans[id] = max(len1 + len2 + 1, tree[1].mx);
		}
		
		int j = lower_bound(lis1.begin(), lis1.end(), h[i]) - lis1.begin();
		lis1[j] = h[i];
		update(h[i]-1, j+1, 0);
		
	}
	
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	
	return 0;
}
