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

int n, q, a[100100];
int l, k;

const int MAXN = 100100;
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

vector<pair<int, int> > v;
vector<pair<pair<int, int>, int> > qu;
int res[200100];

int main(){	
	sd2(n,q);
	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		a[i] = x;
		v.pb(mp(x,i));
		update(i, 1);
	}
	
	
	int prev = 0;
	sort(v.begin(), v.end());
	
	int Q = q;
	
	int id = 1;
	while(q--){
		sd2(l,k);
		qu.pb(mp(mp(l,k),id++));
	}
	
	sort(qu.begin(), qu.end());
	
	foreach(it, qu){
		l = it->fi.fi, k = it->fi.se;
		while(prev < n and v[prev].fi < l){
			update(v[prev].se, -1);
//			tr2("removing", v[prev].fi);
			prev++;
		}
		
//		tr3(prev, l, k);
		
		int lo = 1, hi = n, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			int val = query(mid);
			
//			tr6(lo, mid, hi, val, l, k);
			
			if(val < k) lo = mid+1;
			else if(val > k) hi = mid-1;
			else hi = mid;
//			tr6(lo, mid, hi, val, l, k);
		}
		res[it->se] = a[hi];
	}
	
	for(int i = 1; i <= Q; i++){
		printf("%d\n", res[i]);
	}
	
	return 0;
}
