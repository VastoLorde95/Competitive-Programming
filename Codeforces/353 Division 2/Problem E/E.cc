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

const int N = 1<<18;

int n, a[N];

struct node{
	int cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt = value;
	}
	void combine(node &left, node &right){
		if(a[left.cnt] >= a[right.cnt]) cnt = left.cnt;
		else cnt = right.cnt;
	}
};

node tree[2*N];

void update(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return -1;
	if(x <= l && r <= y) return tree[id].cnt;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	int x1 = query(x, y, left, l, mid);
	int x2 = query(x, y, right, mid, r);
	if(x1 == -1) return x2;
	if(x2 == -1) return x1;
	else if(a[x1] >= a[x2]) return x1;
	else return x2;
}


ll dp[N];

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		sd(a[i]);
	}
	a[n] = -1;
	
	for(int i = 1; i < n; i++) update(i, i);
	
	for(int i = n-1; i > 0; i--){
		int x = query(i+1, a[i]+1);
		dp[i] = a[i] - i;
		if(x != -1){
			dp[i] += dp[x] - (a[i]-x) + (n - a[i]);
		}
	}
	
	cout << accumulate(dp+1, dp+n+1, 0ll) << endl;
	return 0;
}
