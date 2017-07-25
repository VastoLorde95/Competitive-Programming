#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb propagate_back
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

namespace ImplicitTreap{

// a dynamic 1-indexed array
// supports the following:
// insertion and deletion of elements at arbitary position
// all segment tree operations on an array in O(log n) per query INCLUDING lazy propagation!
// treaps are fucking awesome!

struct node{
	int pri, sz;	// heap priority, size of the subtreap rooted at this node
	ll val;			// value of the element in the array

	node *l, *r;

	ll sum;		// problem specific variable
	ll lazy;	// for lazy updates

	node(ll x){
		pri = rand(), sz = 1, val = x;
		l = r = NULL;
		sum = val;
		lazy = 0;
	}
};

inline int getSize(node *cur){
	return (cur)? cur->sz : 0;
}

void propagate(node *cur){
	if(!cur or !cur->lazy) return;

	ll &lazy = cur->lazy;

	cur->val += lazy;
	cur->sum += lazy * getSize(cur);

	if(cur->l) cur->l->lazy += lazy;
	if(cur->r) cur->r->lazy += lazy;

	lazy = 0;	// reset lazy variable
}

void updateSize(node *cur){
	if(!cur) return;
	cur->sz = getSize(cur->l) + 1 + getSize(cur->r);
}

void updateNode(node *cur){
	if(!cur) return;
	cur->sum = cur->val;
	propagate(cur->l);
	propagate(cur->r);

	cur->sum += (cur->l) ? cur->l->sum : 0;
	cur->sum += (cur->r) ? cur->r->sum : 0;
}

// split at the position pos, the treap rooted at current node into two treaps l and r
// arr[1 ... n] -> arr[1 ... pos], arr[pos+1 ... n]
void split(node *root, node * &l, node * &r, int pos, int add = 0){
	if(!root){
		l = r = NULL;
		return;
	}

	propagate(root);

	int cur_indx = getSize(root->l) + add + 1;
	if(cur_indx <= pos){
		split(root->r, root->r, r, pos, cur_indx);
		l = root;
	}
	else{
		split(root->l, l, root->l, pos, add);
		r = root;
	}

	updateSize(root);
	updateNode(root);
}

// merge the two treaps l and r into one treap
void merge(node * &root, node *l, node *r){
	propagate(l);
	propagate(r);

	if(!l or !r){
		root = (l)? l : r;
		return;
	}

	if(l->pri > r->pri){
		merge(l->r, l->r, r);
		root = l;
	}
	else{
		merge(r->l, l, r->l);
		root = r;
	}

	updateSize(root);
	updateNode(root);
}

ll range_query(node *treap, int x, int y){
	node *l, *mid, *r;

	split(treap, mid, r, y);	
	split(mid, l, mid, x-1);

	ll ans = mid->sum;

	merge(mid, l, mid);
	merge(treap, mid, r);

	return ans;
}

void range_update(node *treap, int x, int y, ll val){
	node *l, *mid, *r;

	split(treap, mid, r, y);	
	split(mid, l, mid, x-1);

	mid->lazy += val;

	merge(mid, l, mid);
	merge(treap, mid, r);
}
}

using namespace ImplicitTreap;

void solve(){
	int n, c;
	cin >> n >> c;
	
	node *treap = new node(0);
	for(int i = 2; i <= n; i++){
		node *nnode = new node(0);
		merge(treap, treap, nnode);
	}
	
	int t, p, q, v;
	
	while(c--){
		cin >> t >> p >> q;
		if(t == 0){
			cin >> v;
			range_update(treap, p, q, v);
		}
		else{
			cout << range_query(treap, p, q) << '\n';
		}
	}
}

int main(){ _
	srand(time(NULL));
	
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
