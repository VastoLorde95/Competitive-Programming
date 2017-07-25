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

const int N = 1<<19;

int a, b;

struct node{
	int cnt1, cnt2;
	void assign(int value){
		cnt1 = cnt2 = value;
	}
	void update(int value){
		cnt1 += value;
		cnt2 += value;
		if(cnt1 > b) cnt1 = b;
		if(cnt2 > a) cnt2 = a;
	}
	void combine(node &left, node &right){
		cnt1 = left.cnt1 + right.cnt1;
		cnt2 = left.cnt2 + right.cnt2;
	}
};

int n, k, q;
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(0);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// point update -> update(index, value);
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

// range query -> query(x, y);
pii query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return mp(0,0);
	if(x <= l && r <= y) return mp(tree[id].cnt1, tree[id].cnt2);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	pii p1 = query(x, y, left, l, mid), p2 = query(x, y, right, mid, r);
	return mp(p1.fi+p2.fi, p1.se+p2.se);
}


int main(){
	sd2(n,k);
	sd2(a,b);
	sd(q);
	
	build();
	
	int type, x, y;
	while(q--){
		sd(type);
		if(type == 1){
			sd2(x,y);
			x--;
			update(x, y);
		}
		else{
			sd(x);
			x--;
			int ans = 0;
			if(x > 0){
				ans = query(0,x).fi;
			}
			if(x+k < n){
				ans += query(x+k, n).se;
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
