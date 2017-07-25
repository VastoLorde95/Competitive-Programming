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

const int N = 210;
const int M = (N*(N-1))/2;

int n, m, f[N], g[N][N], inf = 1e9;
int x[M], y[M], w[M];
double ans = inf;

void solve(int a, int b, int c){
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; i++) v.pb(mp(g[a][i], g[b][i]));
	sort(v.begin(), v.end(), greater<pair<int,int> >());
	
	
	// we will get a set of linear functions, the maximums of these linear functions will form a polyline and
	// will correspond to the set of maximum distances to a junction
	// we maintain the point that is currently furthest away in "cur" and the update the value of ans at the
	// local minimas
	pair<int,int> cur = v[0];
	ans = min(ans, 1.0*cur.fi);
	for(int i = 1; i < n; i++){
		if(v[i].se > cur.se){
			ans = min(ans, 0.5*(v[i].fi+cur.se+c));
			cur = v[i];
		}
	}
	ans = min(ans, 1.0*cur.se);
	return;	
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = inf;
		}
		g[i][i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		sd3(x[i],y[i],w[i]);
		g[x[i]][y[i]] = g[y[i]][x[i]] = w[i];
	}		
	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	
	
	for(int i = 0; i < m; i++){
		solve(x[i], y[i], w[i]);
	}
	
	printf("%.9lf\n", ans);
	
	return 0;
}
