#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int MAXN = 1<<18;
int tree[MAXN]; // Careful, indexing begins from 1.
int n, Q, k, a[MAXN], root;
vector<pair<pair<int, int>, int > > qq;
pair<int, int> q[MAXN];

long long ans, res[MAXN];

int query(int idx){
    int sum = 0;
    while(idx > 0){
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

void add(int x){
	ans += query(a[x] + k) - query(a[x]-k-1);
	update(a[x], 1);
}

void remove(int x){
	update(a[x], -1);
	ans -= query(a[x] + k) - query(a[x]-k-1);
}

int main(){
	sd3(n,Q,k);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	root = ((int) sqrt(n)) + 1;
	
	for(int i = 0; i < Q; i++){
		int l, r; sd2(l,r);
		q[i] = mp(l,r);
		qq.pb(mp(mp((l-1)/root,r),i));
	}
	
	sort(qq.begin(), qq.end());
	
	for(int i = 1; i <= n; i++){
		ans += query(a[i]+k) - query(a[i]-k-1);
		update(a[i], 1);
	}
	
	int l = 1, r = n;
	for(int i = 0; i < Q; i++){
		int ll = q[qq[i].se].fi, rr = q[qq[i].se].se;
		while(l < ll) remove(l++);
		while(l > ll) add(--l);
		while(r < rr) add(++r);
		while(r > rr) remove(r--);
		res[qq[i].se] = ans;
	}
	
	for(int i = 0; i < Q; i++){
		printf("%lld\n", res[i]);
	}
	
	return 0;
}
