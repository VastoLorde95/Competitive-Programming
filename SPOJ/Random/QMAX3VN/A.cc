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
	int val;		// value of the element in the array
	
	node *l, *r;
	
	int mx;
	
	node(int x){
		pri = rand(), val = x, size = 1;
		l = r = NULL;
		mx = val;
	}
};

int getSize(node *cur){
	return cur ? cur->size : 0;
}

void updSize(node *cur){
	if(!cur) return;
	cur->size = getSize(cur->l) + 1 + getSize(cur->r);
}

void updNode(node *cur){
	if(!cur) return;
	cur->mx = cur->val;
	if(cur->l){
		cur->mx = max(cur->mx, cur->l->mx);
	}
	if(cur->r){
		cur->mx = max(cur->mx, cur->r->mx);
	}
}

typedef pair<node *, node *> LR;

LR split(node *root, int pos){
	if(!root) return LR(NULL, NULL);
	
//	propagate(root);		// lazy propagation
	
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

	updSize(root);		// update the parameters of root since its children have possibly been modified	
	updNode(root);
	return ret;
}

node *merge(node *l, node *r){
	if(!l or !r) return l ? l : r;
	
	if(l->pri > r->pri){
//		propagate(l);		// lazy propagation
		l->r = merge(l->r, r);
		updSize(l);			// update the parameters of l since its children have possibly been modified	
		updNode(l);	
		return l;
	}
	else{
//		propagate(r);		// lazy propagation
		r->l = merge(l, r->l);
		updSize(r);		// update the parameters of r since its children have possibly been modified	
		updNode(r);
		return r;
	}
}

int range_query(node * &treap, int x, int y){
	node *l, *mid, *r;

	LR tmp;

	tmp = split(treap, y);	
	mid = tmp.fi, r = tmp.se;
	
	tmp = split(mid, x-1);
	l = tmp.fi, mid = tmp.se;

	int ans = mid->mx;

	treap = merge(l, mid);
	treap = merge(treap, r);

	return ans;
}

void insert(node * &treap, int x, int y){
	node *nn = new node(y);
	
	LR tmp = split(treap, x-1);
	
	treap = merge(tmp.fi, nn);
	treap = merge(treap, tmp.se);
}

}	// end of namespace

using namespace Treap;

void solve(int n){
	char c;
	int  x, y;
	
	cin >> c >> x >> y;
	node *treap = new node(x);
	
	for(int i = 2; i <= n; i++){
		cin >> c >> x >> y;
		
		if(c == 'A'){
			insert(treap, y, x);
		}
		else{
			cout << range_query(treap, x, y) << '\n';
		}
	}
}

int main(){ _
	srand(time(NULL));
	int n;
	while(cin >> n){
		solve(n);
	}
	return 0;
}
