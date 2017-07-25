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

const int N = 200100;

int n, m, f[N], visited[N];
int c[N], u[N], v[N];
vector<pair<int,int> > g[N];

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		sd3(u[i], v[i], c[i]);
		g[u[i]].pb(mp(v[i],i));
		g[v[i]].pb(mp(u[i],i));
		
		f[u[i]] += c[i], f[v[i]] += c[i];
	}
	
	for(int i = 1; i <= n; i++){
		f[i] /= 2;
	}
	
	queue<int> q;
	q.push(1);
	f[1] = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(visited[cur]) continue;
		visited[cur] = 1;
		
		foreach(it, g[cur]){
			int id = it->se, x = it->fi;
			if(visited[x]) continue;
			
			f[x] -= c[id];
			if(f[x] == 0 and x != n) q.push(x);
			
			if(cur == u[id]) c[id] = 0;
			else c[id] = 1;
		}
	}
	
	for(int i = 0; i < m; i++){
		printf("%d\n", c[i]);
	}
	
	return 0;
}
