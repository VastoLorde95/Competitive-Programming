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

const int N = 500500;

int n;
int a[N];

struct node{
	node *left, *right;
	int cnt;
	
	node(){
		left = right = NULL;
		cnt = 0;
	}
	
	node(node *n){
		left = n->left, right = n->right;
		cnt = n->cnt;
	}
};

node *root[N];

void update(node *cur, int pos, int val, int l = 1, int r = n){
	cur->cnt += val;
	if(l == r) return;
	
	int mid = (l+r)/2;
	if(pos <= mid){
		if(cur->left == NULL) cur->left = new node();
		else cur->left = new node(cur->left);
		update(cur->left, pos, val, l, mid);
	}
	else{
		if(cur->right == NULL) cur->right = new node();
		else cur->right = new node(cur->right);	
		update(cur->right, pos, val, mid+1, r);
	}
}

// (l, r]
void get(int l, int r, ll &ans){
	if(l + 1 >= r) return;
	
	node *root1 = root[l];
	node *root2 = root[r];
	
	int q = (root2->cnt - root1->cnt + 1) / 2;
	
	ans += root2->cnt - root1->cnt;
	
	int x = 1, y = n;
	while(x < y){
		int lcnt = 0;
		
		int mid = (x + y) / 2;
		
		if(root1 != NULL and root1->left != NULL) lcnt -= root1->left->cnt;
		if(root2 != NULL and root2->left != NULL) lcnt += root2->left->cnt;
		
		if(lcnt >= q){ // go left
			if(root1 != NULL) root1 = root1->left;
			if(root2 != NULL) root2 = root2->left;
			
			y = mid;
		}
		else{ 		  // go right
			if(root1 != NULL) root1 = root1->right;
			if(root2 != NULL) root2 = root2->right;
			
			q -= lcnt;
			x = mid + 1;
		}
	}

	x = a[x];
	
	get(l, x-1, ans);
	get(x, r, ans);
}

int rmap[N];

int main(){ _
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		rmap[a[i]] = i;
	}
	
	root[0] = new node();
	for(int i = 1; i <= n; i++){
		root[i] = new node(root[i-1]);
		update(root[i], rmap[i], 1);
	}
	
	ll ans = 0;
	
	get(0, n, ans);
	
	cout << ans << endl;
	
	return 0;
}
