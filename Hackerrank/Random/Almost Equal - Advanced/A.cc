#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;
const int M = 330;

const int MAXN = 3*N;
int tree[MAXN]; // Careful, indexing begins from 1.

int query(int idx){
    int sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

struct quer{
	int l, r, id;
	bool operator<(const quer &q) const{
		if(l/M != q.l/M) return l/M < q.l/M; return r < q.r;
	}
};

struct height{int x, y, z;};

int n, k;
ll ans;
height h[N];
ll res[N];
quer q[N];

set<int> comp;
map<int,int> f;

void add(int x){
	ans += query(h[x].y) - query(h[x].z);
	update(h[x].x, 1);
}

void rem(int x){
	update(h[x].x, -1);
	ans -= query(h[x].y) - query(h[x].z);
}

int main(){
	sd2(n,k);
	
	for(int i = 0; i < n; i++){
		sd(h[i].x);
		h[i].y = h[i].x + k;
		h[i].z = h[i].x - k - 1;
		comp.insert(h[i].x);
		comp.insert(h[i].y);
		comp.insert(h[i].z);
	}
	
	int cnt = 1;
	foreach(it, comp) f[*it] = cnt++;
	
	for(int i = 0; i < n; i++){
		h[i].x = f[h[i].x];
		h[i].y = f[h[i].y];
		h[i].z = f[h[i].z];
	}
	
	int m, l, r;
	sd(m);
	for(int i = 0; i < m; i++){
		sd2(l,r);
		q[i].l = l, q[i].r = r, q[i].id = i;
	}	
	
	sort(q, q+m);
	
	l = q[0].l, r = l-1;
	while(r < q[0].r) add(++r);
	
	for(int i = 0; i < m; i++){
		int ll2 = q[i].l, rr = q[i].r;
		
		while(l < ll2) rem(l++);
		while(l > ll2) add(--l);
		while(r < rr) add(++r);
		while(r > rr) rem(r--);
		res[q[i].id] = ans;
	}
	
	for(int i = 0; i < m; i++){
		printf("%lld\n", res[i]);
	}
	
	return 0;
}
