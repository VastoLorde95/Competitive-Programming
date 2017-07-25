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

const int N = 500100;
const int M = 2;

struct node{
	node *next[M];
	int cnt;
	
	node(){
		for(int i = 0; i < M; i++) next[i] = NULL;
		cnt = 0;
	}
	
	node(node *n){
		for(int i = 0; i < M; i++) next[i] = n->next[i];
		cnt = n->cnt;
	}
	
	int lcnt(){
		if(next[0] == NULL) return 0;
		return next[0]->cnt;
	}
	
	int rcnt(){
		if(next[1] == NULL) return 0;
		return next[1]->cnt;
	}
};

const int PAD = 30;

vector<int> ntov(int x){
	vector<int> ret;
	while(x){
		ret.pb(x & 1);
		x >>= 1;
	}
	
	while(ret.size() < PAD) ret.pb(0);
	reverse(ret.begin(), ret.end());
	
	return ret;
}

void insert(node *cur, int x){
	vector<int> num = ntov(x);
	
	for(int i : num){
		cur->cnt++;
		node *nxt;
		if(cur->next[i] == NULL){
			nxt = new node();
		}
		else{
			nxt = new node(cur->next[i]);
		}
		cur->next[i] = nxt;
		cur = cur->next[i];
	}
	cur->cnt++;
}

node* go(node *n, int i){
	if(n != NULL) n = n->next[i];
	return n;
}

node *roots1[N];

int query1(int l, int r, int x){
	--l;
	vector<int> num = ntov(x);
	int ans = 0;
	
	node *a = roots1[l];
	node *b = roots1[r];
	
	for(int i : num){
		ans <<= 1;
		if(i){
			int lcnt = ((b == NULL)? 0 : b->lcnt()) - ((a == NULL)? 0 : a->lcnt());
			if(lcnt == 0){
				ans |= 1;
				a = go(a, 1); b = go(b, 1);
			}
			else{
				a = go(a, 0); b = go(b, 0);
			}
		}
		else{
			int rcnt = ((b == NULL)? 0 : b->rcnt()) - ((a == NULL)? 0 : a->rcnt());
			if(rcnt == 0){
				a = go(a, 0); b = go(b, 0);
			}
			else{
				ans |= 1;
				a = go(a, 1); b = go(b, 1);
			}
		}
	}
	
	return ans;
}

int query2(int l, int r, int x){
	--l;
	vector<int> num = ntov(x);
	int ans = 0;
	
	node *a = roots1[l];
	node *b = roots1[r];
	
	for(int i : num){
		if(i){
			int lcnt = ((b == NULL)? 0 : b->lcnt()) - ((a == NULL)? 0 : a->lcnt());
			ans += lcnt;
			a = go(a, 1); b = go(b, 1);
		}
		else{
			a = go(a, 0); b = go(b, 0);
		}
	}
	
	if(b != NULL) ans += b->cnt;
	if(a != NULL) ans -= a->cnt;
	
	return ans;
}

int query3(int l, int r, int k){
	--l;
	int ans = 0;
	
	node *a = roots1[l];
	node *b = roots1[r];
	
	for(int i = 0; i < PAD; i++){
		ans <<= 1;
		int lcnt = ((b == NULL)? 0 : b->lcnt()) - ((a == NULL)? 0 : a->lcnt());
		
		if(lcnt >= k){
			a = go(a, 0);
			b = go(b, 0);
		}
		else{
			k -= lcnt;
			a = go(a, 1);
			b = go(b, 1);
			ans |= 1;
		}
	}
	return ans;
}

int a[N];

int main(){ _
	roots1[0] = new node();
	
	int l = 0;
	
	int m;
	cin >> m;
	
	while(m--){
		int t;
		cin >> t;
		
		if(t == 0){
			int x;
			cin >> x;
			
			++l;
			
			a[l] = x ^ a[l-1];
			roots1[l] = new node(roots1[l-1]);
			insert(roots1[l], x);
			
//			dfs(roots1[l]);
		}
		else if(t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			cout << query1(l, r, x) << '\n';
		}
		else if(t == 2){
			int k;
			cin >> k;
			l -= k;
		}
		else if(t == 3){
			int l, r, x;
			cin >> l >> r >> x;
			cout << query2(l, r, x) << '\n';
		}
		else if(t == 4){
			int l, r, k;
			cin >> l >> r >> k;
			cout << query3(l, r, k) << '\n';
		}
	}
	
	return 0;
}
