/*
 Solution for CodeChef problem http://codechef.com/problems/MGCHGYM
 Using Implict Treaps
*/

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

namespace Treap{

const int K = 10;
const int N = 100100;

int wpos[N];
int posw[K];

struct node{
	int pri, size, val;	// heap priority, size of the subtreap rooted at this node
	
	node *l, *r;
	
	vector<int> m;
	int rev;
	
	node(int x){
		pri = rand(), val = x, size = 1;
		l = r = NULL;
		
		m.resize(K, 0);
		
		m[wpos[x]] = 1;
		rev = 0;
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
	if(!cur or !cur->rev) return;
	cur->rev ^= 1;
	
	swap(cur->l, cur->r);
	if(cur->l) cur->l->rev ^= 1;
	if(cur->r) cur->r->rev ^= 1;
}

void updNode(node *cur){
	if(!cur) return;
	cur->m.clear();
	cur->m.resize(K, 0);
	cur->m[wpos[cur->val]] = 1;
	
	propagate(cur->l);
	propagate(cur->r);
	
	if(cur->l){
		for(int i = 0; i < K; i++){
			cur->m[i] += cur->l->m[i];
		}
	}
	if(cur->r){
		for(int i = 0; i < K; i++){
			cur->m[i] += cur->r->m[i];
		}
	}
}

typedef pair<node *, node *> LR;

LR split(node *root, int pos){
	if(!root) return LR(NULL, NULL);
	
	propagate(root);		// lazy propagation
	
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
		propagate(l);		// lazy propagation
		l->r = merge(l->r, r);
		updSize(l);			// update the parameters of l since its children have possibly been modified	
		updNode(l);	
		return l;
	}
	else{
		propagate(r);		// lazy propagation
		r->l = merge(l, r->l);
		updSize(r);		// update the parameters of r since its children have possibly been modified	
		updNode(r);
		return r;
	}
}

const int M = 100100;

bool range_query(node * &treap, int x, int y, int w){
	node *l, *mid, *r;

	LR tmp;

	tmp = split(treap, y);	
	mid = tmp.fi, r = tmp.se;
	
	tmp = split(mid, x-1);
	l = tmp.fi, mid = tmp.se;

	vector<int> &m = mid->m;
//	unordered_map<int, int> &m = mid->m;

	bitset<M> b;
	b[0] = 1;
	 
	for(int i = 0; i < K; i++){
		if(!posw[i]) break;
//		tr(i, posw[i], m[i]);
		
		int k = min(w / posw[i], m[i]);
		
		int cur = 1;
		while(cur <= k){
			b |= b << (posw[i] * cur);
			k -= cur;
			cur <<= 1;
			if(b[w]) break;
		}
		
		if(k){
			b |= b << (posw[i] * k);
		}
		
		if(b[w]) break;
	}

	int ans = b[w];	

	treap = merge(l, mid);
	treap = merge(treap, r);

	return ans;
}

int point_update(node *root, int pos, int val){
	propagate(root);		// lazy propagation
	
	int ret;
	
	root->m[wpos[val]]++;
	
	int cur_size = getSize(root->l) + 1;
	if(cur_size < pos){
		ret = point_update(root->r, pos - cur_size, val);
		root->m[wpos[ret]]--;
	}	
	else if(cur_size > pos){
		ret = point_update(root->l, pos, val);
		root->m[wpos[ret]]--;
	}
	else{
		int old = root->val;
		root->val = val;
		
		root->m[wpos[old]]--;
		
		return old;
	}

	updSize(root);		// update the parameters of root since its children have possibly been modified	
	
	return ret;
}

void range_update(node * &treap, int x, int y){
	node *l, *mid, *r;

	LR tmp;

	tmp = split(treap, y);	
	mid = tmp.fi, r = tmp.se;
	
	tmp = split(mid, x-1);
	l = tmp.fi, mid = tmp.se;

	mid->rev ^= 1;			// lazy updates

	treap = merge(l, mid);
	treap = merge(treap, r);
}	

}	// end of namespace

using namespace Treap;

int n, q;
int w[N];

int t[N], x[N], y[N], ww[N];

int main(){ _
	srand(time(NULL));
	cin >> n >> q;
	
	set<int> d;

	for(int i = 1; i <= n; i++){
		cin >> w[i];
		d.insert(w[i]);
	}
	
	for(int i = 1; i <= q; i++){
		cin >> t[i] >> x[i] >> y[i];
		if(t[i] == 1){
			d.insert(y[i]);
		}
		else if(t[i] == 3){
			cin >> ww[i];
		}
	}
	
	int kk = 0;
	foreach(it, d){
		posw[kk] = *it;
		wpos[*it] = kk++;
	}
	
	node *treap = new node(w[1]);
	for(int i = 2; i <= n; i++){
		node *nn = new node(w[i]);
		treap = merge(treap, nn);
	}
	
	for(int i = 1; i <= q; i++){
		if(t[i] == 1)
			point_update(treap, x[i], y[i]);
		else if(t[i] == 2)
			range_update(treap, x[i], y[i]);
		else{
			if(range_query(treap, x[i], y[i], ww[i]))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	
	return 0;
}
