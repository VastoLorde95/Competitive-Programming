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

typedef long double ld;

const int N = 100100;

int n, q, a, b, l, sz[N], r, w;
vector<pair<int, int> > g[N];
pair<int, pair<int, int> > edges[N];
ld ans, ways[N];

int dfs(int cur, int prev){
	sz[cur] = 1;
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		sz[cur] += dfs(it->fi, cur);
	}
	return sz[cur];
}

ld count(long long x, long long y){
	ld p1 = (ld) ((x*(x-1))/2) /  (ld) n;
	p1 /= (ld) (n-1);
	p1 /= (ld) (n-2);
	p1 *= y;
	
	ld p2 = (ld) ((y*(y-1))/2) /  (ld) n;
	p2 /= (ld) (n-1);
	p2 /= (ld) (n-2);
	p2 *= x;
	
	return p1+p2;
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		sd3(a,b,l);
		g[a].pb(mp(b,l));
		g[b].pb(mp(a,l));
		edges[i] = mp(l,mp(a,b));
	}	
	dfs(1,-1);
	
	for(int i = 1; i < n; i++){
		a = sz[edges[i].se.fi], b = sz[edges[i].se.se];
		a = min(a,b);
		b = n-a;
		ways[i] = count(a,b);
		ld tmp = edges[i].fi;
		ans += ways[i] * tmp;
	}
	
	sd(q);
	
	while(q--){
		sd2(r,w);
		ld tmp = edges[r].fi - w;
		
		edges[r].fi = w;
		ans -= ways[r] * tmp;
		
		printf("%.9lf\n", (double) ans*12);
	}	
	return 0;
}
