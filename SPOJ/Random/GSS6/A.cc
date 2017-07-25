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

namespace Treap{

struct node{
	int pri, size;	// heap priority, size of the subtreap rooted at this node
	int val;			// value of the element in the array
	
	node *l, *r;
	
	int sum, lsum, rsum, mx;			// problem specific variable
	
	node(int x){
		pri = rand(), val = x, size = 1;
		l = r = NULL;
		
		lsum = rsum = sum = mx = val;
	}
	
	void reset(){
		lsum = rsum = sum = mx = val;
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
	cur->reset();
	
	node *l = cur->l;
	node *r = cur->r;
	if(l and r){
		cur->lsum = max(l->lsum, max(l->sum + cur->sum, l->sum + cur->sum + r->lsum));
		cur->rsum = max(r->rsum, max(r->sum + cur->sum, r->sum + cur->sum + l->rsum));
		cur->sum = l->sum + cur->val + r->sum;
		cur->mx = max(cur->mx, max(l->mx, r->mx));
		cur->mx = max(cur->mx, max(cur->lsum, cur->rsum));
		
		cur->mx = max(cur->mx, max(l->rsum + cur->val, r->lsum + cur->val));
		cur->mx = max(cur->mx, l->rsum + cur->val + r->lsum);
	}
	else if(l){
		cur->lsum = max(l->lsum, l->sum + cur->lsum);
		cur->rsum = max(cur->rsum, cur->sum + l->rsum);
		cur->sum = cur->sum + l->sum;
		
		cur->mx = max(cur->mx, max(cur->lsum, cur->rsum));
		cur->mx = max(cur->mx, l->mx);
	}
	else if(r){
		cur->lsum = max(cur->lsum, cur->sum + r->lsum);
		cur->rsum = max(r->rsum, r->sum + cur->rsum);
		cur->sum = cur->sum + r->sum;
		
		cur->mx = max(cur->mx, max(cur->lsum, cur->rsum));
		cur->mx = max(cur->mx, r->mx);
	}
}

typedef pair<node *, node *> LR;

LR split(node *root, int pos){
	if(!root) return LR(NULL, NULL);
	
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
		l->r = merge(l->r, r);
		updSize(l);			// update the parameters of l since its children have possibly been modified	
		updNode(l);	
		return l;
	}
	else{
		r->l = merge(l, r->l);
		updSize(r);		// update the parameters of r since its children have possibly been modified	
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

	ll ans = mid->mx;

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

void del(node * &treap, int x){
	LR tmp = split(treap, x-1);
	node *l = tmp.fi, *r = tmp.se;
	
	tmp = split(r, 1);
	r = tmp.se;
	
	treap = merge(l, r);
}

void replace(node * &treap, int x, int y){
	LR tmp = split(treap, x-1);
	node *l = tmp.fi, *r = tmp.se;
	
	tmp = split(r, 1);
	r = tmp.se;
	
	tmp.fi =  new node(y);
	treap = merge(l, tmp.fi);
	treap = merge(treap, r);
}

}	// end of namespace

using namespace Treap;

int main(){
	srand(time(NULL));
	
	int n;
	sd(n);
	
	int xx;
	sd(xx);
	node *treap = new node(xx);
	for(int i = 2; i <= n; i++){
		sd(xx);
		node *nn = new node(xx);
		treap = merge(treap, nn);
	}
	

	char t;
	int x, y;
	
	int q;
	sd(q);
	while(q--){
		scanf(" %c%d", &t, &x);
		if(t == 'I'){
			sd(y);
			insert(treap, x, y);
		}
		else if(t == 'D'){
			del(treap, x);
		}
		else if(t == 'R'){
			sd(y);
			replace(treap, x, y);
		}
		else{
			sd(y);
			printf("%d\n", range_query(treap, x, y));
		}
	}
	
	return 0;
}
