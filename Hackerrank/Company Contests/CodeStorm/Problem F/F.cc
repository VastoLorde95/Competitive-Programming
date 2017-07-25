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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int N = 1<<19;

int n, a[N], cnt;
set<int> compressor;
map<int,int> m;

int tree1[N]; // Careful, indexing begins from 1.
int tree2[N];

int used[N], inf = 1e9;

long long ans = 1, MOD = 1e9 + 7;

int query1(int idx){
    int sum = 0;
    while(idx){
        sum += tree1[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update1(int idx, int val){
    while(idx < N){
        tree1[idx] += val;
        idx += (idx & -idx);
    }
}

int query2(int idx){
    int sum = 0;
    while(idx){
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update2(int idx, int val){
    while(idx < N){
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

struct node{
	int cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt = min(cnt, value);
	}
	void combine(node &left, node &right){
		cnt = min(left.cnt, right.cnt);
	}
};

int lazy[N];
node tree[2*N];

void build(int id = 1, int l = 0, int r = N){
	if(l+1 == r){
		tree[id].assign(inf);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

void update(int index, int val, int id = 1, int l = 0, int r = N){
	if(l+1 == r){
		tree[id].update(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}


int query(int x, int y, int id = 1, int l = 0, int r = N){
	if(x >= r or l >= y) return inf;
	if(x <= l && r <= y) return tree[id].cnt;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return min(query(x, y, left, l, mid), query(x, y, right, mid, r));
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		compressor.insert(a[i]);
	}
	
	foreach(it, compressor){
		m[*it] = ++cnt;
	}
	
	build();
	
	for(int i = 0; i < n; i++) a[i] = m[a[i]];
	
	int mn = inf;
	
	for(int i = n-1; i >= 0; i--){
		if(query1(a[i]) > 0){
			if(query2(a[i]) == 0){
				int tmp = query(a[i]+1, cnt+1);
				if(tmp > a[i]) ans = (ans*2)%MOD;
				update(a[i], mn);
				update2(a[i], 1);
				used[i] = 1;
			}
			else{
				ans = 0;
			}
		}
		update1(a[i], 1);
		mn = min(mn, a[i]);
	}
	
	memset(tree1, 0, sizeof tree1);
	
	for(int i = 0; i < n; i++){
		if(i-query1(a[i]-1) == 0 and !used[i]){
			ans = (ans*2)%MOD;
		}
		update1(a[i], 1);
	}

	printf("%lld\n", ans);
	
	return 0;
}
