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

typedef long long ll;

const int N = 15;
const int M = 101;

int n, m, q;
int x[N], y[N], a[M], b[M], c[M];
ll dp1[N][1<<N], dp2[N][1<<N];

bool in(int x, int mask){
	return (mask&(1<<x)) > 0;
}

ll calc(int v, int mask);

ll go1(int v, int mask, int p){
	for(int i = 0; i < m; i++){
		if(in(x[i], mask) != in(y[i], mask)){
			if((x[i] != v and x[i] != p) or (y[i] != v and y[i] != p)) return 0;
		}
	}
	
	for(int i = 0; i < q; i++){
		if(!in(c[i], mask)){
			if(in(a[i], mask) and in(b[i], mask)) return 0;
		}
		else if(!in(a[i], mask) or !in(b[i], mask)) return 0;
	}
	
	if(dp1[v][mask] > 0) return dp1[v][mask];
	return dp1[v][mask] = calc(v, mask);
}

ll go2(int v, int mask){
	for(int i = 0; i < m; i++){
		if(in(x[i], mask) != in(y[i], mask)){
			if(x[i] != v and y[i] != v) return 0;
		}
	}
	
	for(int i = 0; i < q; i++){
		if(!in(c[i], mask)){
			if(in(a[i], mask) and in(b[i], mask)) return 0;
		}
		else if((!in(a[i], mask) or !in(b[i], mask)) and c[i] != v) return 0;
	}
	
	if(dp2[v][mask] > 0) return dp2[v][mask];
	return dp2[v][mask] = calc(v, mask);
}


ll calc(int v, int mask){
	int nmask = mask^(1<<v);
	if(nmask == 0) return 1;
	
	int low = 0;
	for(int i = 0; i < n; i++){
		if((nmask&(1<<i)) > 0){
			low = 1<<i;
			break;
		}
	}
	
	ll ret = 0;
	for(int i = nmask; i > 0; i = ((i-1)&nmask)){
		if((i&low) == 0) continue;
		
		for(int j = 0; j < n; j++){
			if(in(j, i)){
				ret += go1(j, i, v) * go2(v, mask^i);
			}
		}
	}
	return ret;
}

int main(){
	sd3(n,m,q);
	
	for(int i = 0; i < m; i++){
		sd2(x[i], y[i]);
		x[i]--, y[i]--;
	}
	
	for(int i = 0; i < q; i++){
		sd3(a[i], b[i], c[i]);
		a[i]--, b[i]--, c[i]--;
	}
	
	cout << go1(0, (1<<n)-1, -1) << endl;	
	
	
	return 0;
}
