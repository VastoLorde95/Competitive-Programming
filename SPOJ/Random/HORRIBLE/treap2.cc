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

// TODO srand(time(NULL));

// a dynamic 1-indexed array
// supports the following:
// insertion and deletion of elements at arbitary position
// all segment tree operations on an array in O(log n) per query INCLUDING lazy propagation!
// split the array at any position
// combine two arrays

namespace Treap{

struct node{
	int pri, size;	// heap priority, size of the subtreap rooted at this node
	ll val;			// value of the element in the array
	
	node *l, *r;
	
	ll sum;			// problem specific variable
	ll lazy;		// for lazy updates
	
	node(ll x){
		pri = rand(), val = x, size = 1;
		l = r = NULL;
		
		sum = val;
		lazy = 0;
	}
};

int getSize(node *cur){
	return cur ? cur->size : 0;
}

void updSize(node *cur){
	if(!cur) return;
	cur->size = getSize(cur->l) + 1 + getSize(cur->r);
}

void propagate(node *cur){
	if(!cur or !cur->lazy) return;
	cur->val += cur->lazy;
	cur->sum += cur->lazy * getSize(cur);
	
	if(cur->l) cur->l->lazy += cur->lazy;
	if(cur->r) cur->r->lazy += cur->lazy;
	
	cur->lazy = 0;
}

void updNode(node *cur){
	if(!cur) return;
	cur->sum = cur-> val;
	propagate(cur->l);
	propagate(cur->r);
	
	cur->sum += (cur->l) ? cur->l->sum : 0;
	cur->sum += (cur->r) ? cur->r->sum : 0;
}

typedef pair<node *, node *> LR;

LR split(node *root, int pos){
	if(!root) return LR(NULL, NULL);
	
	propagate(root);
	
	LR ret;
	
	int cur_size = getSize(root->l) + 1;
	if(cur_size <= pos){
		LR tmp = split(root->r, pos - cur_size);
		root->r = tmp.fi;
		ret = mp(root, tmp.se);
	}	
	else{
		LR tmp = split(root->l, pos);
		root->l = tmp.se;
		ret = mp(tmp.fi, root);
	}

	updSize(root);	
	updNode(root);
	return ret;
}

node *merge(node *l, node *r){
	if(!l or !r) return l ? l : r;
	
	if(l->pri > r->pri){
		propagate(l);
		l->r = merge(l->r, r);
		updSize(l);
		updNode(l);
		return l;
	}
	else{
		propagate(r);
		r->l = merge(l, r->l);
		updSize(r);
		updNode(r);
		return r;
	}
}

ll range_query(node * &treap, int x, int y){
	node *l, *mid, *r;

	LR tmp;

	tmp = split(treap, y);	
	mid = tmp.fi, r = tmp.se;
	
	tmp = split(mid, x-1);
	l = tmp.fi, mid = tmp.se;

	ll ans = mid->sum;

	treap = merge(l, mid);
	treap = merge(treap, r);

	return ans;
}

void range_update(node * &treap, int x, int y, ll val){
	node *l, *mid, *r;

	LR tmp;

	tmp = split(treap, y);	
	mid = tmp.fi, r = tmp.se;
	
	tmp = split(mid, x-1);
	l = tmp.fi, mid = tmp.se;

	mid->lazy += val;

	treap = merge(l, mid);
	treap = merge(treap, r);
}

}	// end of namespace

using namespace Treap;

void solve(){
	int n, c;
	cin >> n >> c;
	
	node *treap = new node(0);
	for(int i = 2; i <= n; i++){
		node *nnode = new node(0);
		treap = merge(treap, nnode);
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
