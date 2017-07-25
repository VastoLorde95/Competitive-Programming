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
	int pri;
	int val;
	int size;
	
	node *l, *r;
	
	int rev;
	
	node(int x){
		pri = rand();
		val = x;
		size = 1;
		
		l = r = NULL;
		
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
	if(cur->l) cur->l->rev ^= 1;
	if(cur->r) cur->r->rev ^= 1;
	swap(cur->l, cur->r);
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
	return ret;
}

node *merge(node *l, node *r){
	if(!l or !r) return l ? l : r;
	
	if(l->pri > r->pri){
		propagate(l);
		l->r = merge(l->r, r);
		updSize(l);
		return l;
	}
	else{
		propagate(r);
		r->l = merge(l, r->l);
		updSize(r);
		return r;
	}
}

}	// end of namespace

using namespace Treap;

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
		treap = merge(treap, nn);
	}
	
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		
		node *l, *mid, *r;
		
		LR tmp = split(treap, a);
		l = tmp.fi, mid = tmp.se;
		
		tmp = split(mid, b);
		mid = tmp.fi, r = tmp.se;
		
		mid->rev ^= 1;
		
		treap = merge(l, r);
		tmp = split(treap, c);
		
		l = tmp.fi, r = tmp.se;
		
		treap = merge(l, mid);
		treap = merge(treap, r);
		
	}
	
	inorder(treap);
	cout << '\n';
	return 0;
}
