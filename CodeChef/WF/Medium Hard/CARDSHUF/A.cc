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

namespace ImplicitTreap{

// TODO srand(time(NULL));

// a dynamic 1-indexed array
// supports the following:
// insertion and deletion of elements at arbitary position
// all segment tree operations on an array in O(log n) per query INCLUDING lazy propagation!
// split the array at any position
// combine two arrays

struct node{
	int pri, sz;	// heap priority, size of the subtreap rooted at this node
	ll val;			// value of the element in the array

	node *l, *r;
	bool rev;

	node(ll x){
		pri = rand(), sz = 1, val = x;
		l = r = NULL;
		rev = false;
	}
};

inline int getSize(node *cur){
	return (cur)? cur->sz : 0;
}

void updateSize(node *cur){
	if(!cur) return;
	cur->sz = getSize(cur->l) + 1 + getSize(cur->r);
}

void propagate(node *cur){
	if(!cur or !cur->rev) return;

	if(cur->l){
		cur->l->rev = !cur->l->rev;
	}
	if(cur->r){
		cur->r->rev = !cur->r->rev;
	}

	swap(cur->l, cur->r);

	cur->rev = false;	// reset lazy variable
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
}

// merge the two treaps l and r into one treap
void merge(node * &root, node *l, node *r){
//	assert(l != r);
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
}

}	// end of namespace ImplicitTreap

using namespace ImplicitTreap;

void inorder2(node *cur){
	if(!cur) return;
	
	inorder2(cur->l);
	cout << cur->val << ' ';
	inorder2(cur->r);
}

void inorder(node *cur){
	propagate(cur);
	if(!cur) return;
	
	inorder(cur->l);
	cout << cur->val << ' ';
	inorder(cur->r);
}

int main(){ _
	srand(time(0));
	int n, m;
	cin >> n >> m;
	
	node *treap = new node(1);
	for(int i = 2; i <= n; i++){
		node * nn = new node(i);
		merge(treap, treap, nn);
	}
	
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		
		node *l = NULL, *mid = NULL, *r = NULL;	
			
		split(treap, l, mid, a);
		treap = NULL;
		
		split(mid, mid, r, b);
		
		mid->rev = !mid->rev;
		
		merge(treap, l, r);
		l = NULL;
		r = NULL;
		
		split(treap, l, r, c);
		treap = NULL;
		
		merge(treap, l, mid);
		l = NULL;
		mid = NULL;
		
		merge(treap, treap, r);
		r = NULL;
	}
	
	inorder(treap);
	cout << '\n';
	return 0;
}
