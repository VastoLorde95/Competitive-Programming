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

const int N = 1 << 17;

int p[N];
int t[N];
int X[N];

struct node{
	int l, r;

	node(){
		l = r = 0;
	}

	void update(int value){
		if(value == 0) r = 1; else l = 1;
	}
	
	void combine(node &left, node &right){
		l = right.l;
		r = left.r;
		
		if(right.r >= left.l){
			r += right.r - left.l;
		}
		else{
			l += left.l - right.r;
		}
	}
};

int n;
node tree[2*N];

void update(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].update(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}


int query(int log, int id = 1, int l = 0, int r = n){
	if(l+1 == r) return l;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(tree[right].l - log > 0) return query(log, right, mid, r);
	else return query(log + tree[right].r - tree[right].l, left, l, mid);
}

int XX[N];

int main(){ _
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> p[i] >> t[i];
		
		p[i]--;
		
		if(t[i] == 1){
			cin >> X[i];
			XX[p[i]] = X[i];
		}
		
		update(p[i], t[i]);
		
		if(tree[1].l == 0){
			cout << -1 << endl;
			continue;
		}
		
		int id = query(0);
		cout << XX[id] << endl;
	}
	
	return 0;
}
