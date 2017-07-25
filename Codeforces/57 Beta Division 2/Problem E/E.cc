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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int MAXN = 1000001;

int n, a[MAXN], cnt;
set<int> comp;
map<int,int> f;

long long tree[MAXN], tree2[MAXN], ans; // Careful, indexing begins from 1.

long long query(int idx){
    long long sum = 0;
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

long long query2(int idx){
    long long sum = 0;
    while(idx){
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update2(int idx, long long val){
    while(idx < MAXN){
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		comp.insert(a[i]);
	}
	
	cnt = 1;
	foreach(it, comp) f[*it] = cnt++;

	for(int i = 0; i < n; i++) a[i] = f[a[i]];
	
	for(int i = n-1; i >= 0; i--){
		long long v1 = query(a[i]-1);
		update(a[i], 1);
		ans += query2(a[i]-1);
		update2(a[i], v1);
	}

	cout << ans << '\n';
	
	return 0;
}
