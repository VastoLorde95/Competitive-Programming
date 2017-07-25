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

struct sparseSegmentTree{
	struct node{
		node *left, *right;
		int cnt;
	
		node(){
			cnt = 0, left = NULL, right = NULL;
		}
		
		void updateNode(){
			cnt = ((left == NULL)? 0 : left->cnt) + ((right == NULL)? 0 : right->cnt);
		}
	};
	
	node *ROOT;
	int L, R;
	
	sparseSegmentTree(int _l, int _r){
		L = _l, R = _r;
		ROOT = new node();
	}
	
	void update(int id, int val, int l, int r, node *cur){
		if(l == r){
			cur->cnt += val;
			return;
		}
		
		int mid = (l + r)/2;
		
		if(id <= mid){
			if(cur->left == NULL) cur->left = new node();
			update(id, val, l, mid, cur->left);
		}
		else{
			if(cur->right == NULL) cur->right = new node();
			update(id, val, mid+1, r, cur->right);
		}
		
		cur->updateNode();	
	}
	
	int query(int x, int y, int l, int r, node *cur){
		if(y < l or x > r or cur == NULL)
			return 0;
		if(x <= l and r <= y)
			return cur->cnt;
		int mid = (l + r) / 2;
		return query(x, y, l, mid, cur->left) + query(x, y, mid+1, r, cur->right);
	}
	
	void update(int id, int val){
		update(id, val, L, R, ROOT);
	}

	int query(int x, int y){
		return query(x, y, L, R, ROOT);
	}
};

const int N = 100100;

int n;
int ans[N];
int print[N];

map<int, vector<pair<pii, int> > > q;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		int a, t, x; sd3(a,t,x);
		q[x].pb(mp(mp(t,i),a));
		if(a == 3) print[i] = 1;
	}
	
	foreach(it, q){
		vector<pair<pii, int> > &v = it->se;
		sort(v.begin(), v.end());

		sparseSegmentTree *tree = new sparseSegmentTree(1, n);
		
		for(int i = 0; i < v.size(); i++){
			int id = v[i].fi.se;
			int t = v[i].se;
			
			if(t == 1){
				tree->update(id, 1);
			}
			else if(t == 2){
				tree->update(id, -1);
			}
			else{
				ans[id] = tree->query(1, id);
			}
		}
		
		delete tree;
	}
	
	for(int i = 0; i < n; i++){
		if(print[i]) printf("%d\n", ans[i]);
	}
	
	return 0;
}
