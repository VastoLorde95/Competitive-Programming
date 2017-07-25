#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int M = 30;
const int N = 1 << 17;
const int INF = 1 << M;

struct node{
	int x;
	int id[M];
	node(){ memset(id, 0, sizeof id); }
	void assign(int num, int pos){
		x = num;
		for(int i = 0; i < M; i++) id[i] = ((x&(1<<i)) > 0)? pos : INF;
	}
	void update(int bit){
		id[bit] = INF;
		x ^= (1 << bit);
	}
	void combine(node &left, node &right, int bit = -1){
		if(bit == -1){
			for(int i = 0; i < M; i++) id[i] = min(left.id[i], right.id[i]);
		}
		else{
			id[bit] = min(left.id[bit], right.id[bit]);
		}
		x = min(left.x, right.x);
	}
};

int n, q, a[N];
node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		return tree[id].assign(a[l], l);
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void update(int index, int bit, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		return tree[id].update(bit);
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, bit, left, l, mid);
	else update(index, bit, right, mid, r);
	
	tree[id].combine(tree[left], tree[right], bit);
}

int query(int x, int y, int bit, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return INF;
	if(x <= l && r <= y) return tree[id].id[bit];
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return min(query(x, y, bit, left, l, mid), query(x, y, bit, right, mid, r));
}

int query2(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return INF;
	if(x <= l && r <= y) return tree[id].x;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return min(query2(x, y, left, l, mid), query2(x, y, right, mid, r));
}

int main(){
	sd2(n,q);
	
	for(int i = 0; i < n; i++) sd(a[i]);
	
	build();
	
	while(q--){
		int t, l, r; sd3(t,l,r);
		l--, r--;
		if(t == 0){
			printf("%d\n", query2(l, r+1));	
		}
		else{
			int x; sd(x);
			for(int i = 0; i < M; i++){
				if(x&(1<<i)) continue;
				int j = l;
				while(j <= r){
					if(a[j]&(1<<i)){
						a[j] ^= (1<<i);
						update(j, i);
						j++;
					}
					else j = query(j, r+1, i);
				}
			}
		}
	}
	return 0;
}
