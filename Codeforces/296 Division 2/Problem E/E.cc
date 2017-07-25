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

int n, m;
int used[500100];
vector<pair<int, int> > g[100100];
vector<int> odd, tour;

void find(int u){
	while(g[u].size() > 0){
		pair<int, int> nxt = g[u].back(); g[u].pop_back();
		if(used[nxt.se] == 1) continue;
		
		used[nxt.se] = 1;
		find(nxt.fi);
	}
	tour.pb(u);
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int u, v; sd2(u,v);
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
	}
	for(int i = 1; i <= n; i++){
		if(g[i].size()%2 == 1){
			odd.pb(i);
		}
	}
	
	for(int i = 1; i < odd.size(); i += 2){
		int u = odd[i-1], v = odd[i];
		g[u].pb(mp(v,m));
		g[v].pb(mp(u,m));
		m++;
	}
	
	if(m%2 == 1){
		g[1].pb(mp(1,m));
		g[1].pb(mp(1,m));
		m++;
	}

	printf("%d\n", m);
	
	find(1);
	
	for(int i = 1; i < tour.size(); i++){
		if(i%2) printf("%d %d\n", tour[i-1], tour[i]); else printf("%d %d\n", tour[i], tour[i-1]);
	}
	
	return 0;
}
