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

int n, m, c[101], vi[101];
vector<pair<int, int> > v;
vector<int> g[101];

bool ok= true;

void dfs(int cur, int col){
	if(vi[cur]){
		if(col != c[cur]) ok = false;
		return;
	}
	vi[cur] = 1;
	c[cur] = col;
	foreach(it, g[cur]){
		dfs(*it, 1-col);
	}
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int x, y; sd2(x,y);
		if(x > y) swap(x,y);
		v.pb(mp(x,y));
	}
	
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			if(v[i].fi < v[j].fi and v[j].fi < v[i].se and v[i].se < v[j].se){
				g[i].pb(j);
				g[j].pb(i);
			}
			else if(v[j].fi < v[i].fi and v[i].fi < v[j].se and v[j].se < v[i].se){
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		if(!vi[i]){
			dfs(i, 0);
		}
	}
	
	if(!ok){
		puts("Impossible"); return 0;
	}
	
	for(int i = 0; i < m; i++){
		printf("%c", (c[i] == 0)? 'i' : 'o');
	}
	printf("\n");
		
	return 0;
}
