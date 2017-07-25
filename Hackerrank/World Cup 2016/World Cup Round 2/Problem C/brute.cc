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

int t, n, m, k;
int v[100];
vector<int> g[100];

vector<int> order;

set<vector<int> > hash;

bool dfs(int cur, int dest){
	if(cur == dest) return true;
	if(v[cur]) return false;
	v[cur] = 1;
	
	foreach(it, g[cur]){
		if(dfs(*it, dest)) return true;
	}
	return false;
}

bool good(){
	for(int i = 1; i < order.size(); i++){
		memset(v, 0, sizeof v);
		if(!dfs(order[i-1], order[i])) return false;
	}
	return true;
}

int main(){
	sd(t);
	while(t--){
		sd3(n,m,k);
		
		order.clear();
		hash.clear();
		
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		
		for(int i = 0; i < k; i++){
			int num; sd(num);
			order.pb(num);
		}
		
		for(int i = 0; i < m; i++){
			int x, y; sd2(x,y);
			g[x].pb(y);
			
		}
		
		if(good()) hash.insert(order);	
		
		while(next_permutation(order.begin(), order.end())){
			if(good()) hash.insert(order);	
		}
		
		if(hash.empty()) cout << -1 << "\n";
		else{
			order = *hash.begin();
			foreach(it, order){
				cout << *it << " ";
			}
			cout << "\n";
		}
		
	}
	return 0;
}
