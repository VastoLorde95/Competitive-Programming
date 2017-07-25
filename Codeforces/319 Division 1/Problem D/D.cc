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

typedef pair<int,int> pii;
typedef long long ll;

const int N = 200;

int n, m, dp[32][N][N], ok[N], v[N];
vector<pair<int, pii> > e;
vector<int> g[N];

ll dis[N], inf = 1e17, ans;

void update(int x, int y, int z){
	if(z == 31 or dp[z][x][y]) return;
	dp[z][x][y] = 1;
	
	for(int i = 1; i <= n; i++){
		if(dp[z][i][x]) update(i,y,z+1);
		if(dp[z][y][i]) update(x,i,z+1);
	}
}


void update2(int exp){
	int tmp[200];
//	tr2("up", exp);
	for(int i = 0; i < 31; i++){
		if((exp&(1<<i)) > 0){
			memset(tmp, 0, sizeof tmp);
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					if(ok[k] and dp[i][k][j]){
						tmp[j] = 1;
						break;
					}
				}
			}
			
			for(int j = 1; j <= n; j++){
				ok[j] = tmp[j];
			}
		}
	}
}

ll bfs(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		v[i] = 0;
		dis[i] = inf;
		
		if(ok[i]){
			dis[i] = 0;
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		
		if(v[cur]) continue;
		v[cur] = 1;
		
		foreach(it, g[cur]){
			if(!v[*it]){
				dis[*it] = min(dis[*it], dis[cur]+1);
				q.push(*it);
			}
		}
	}
	
	return dis[n];
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int a, b, d; sd3(a,b,d);
		e.pb(mp(d,mp(a,b)));
	}
	
	sort(e.begin(), e.end());
	
	ok[1] = 1;
	
	int cur = 0;
	while(cur < m and e[cur].fi == 0){
		update(e[cur].se.fi, e[cur].se.se, 0);
		g[e[cur].se.fi].pb(e[cur].se.se);
		
		cur++;
	}
	
	
	if(cur == 0){
		puts("Impossible"); return 0;
	}
	
	
	ans = min(inf, bfs());
	
//	tr(ans);

//	for(int i = 1; i <= n; i++){
//		tr3("%", i, ok[i]);
//	}
//	
//	tr(cur);
	while(cur < m){
		int d = e[cur].fi, d1 = e[cur-1].fi;
		
		update2(d-d1);
		
		while(cur < m and e[cur].fi == d){
			update(e[cur].se.fi, e[cur].se.se, 0);
			g[e[cur].se.fi].pb(e[cur].se.se);
			cur++;
		}
		
		ans = min(ans, bfs()+d);
//		tr4(cur, ans, bfs(),d);
//		
//		for(int i = 1; i <= n; i++){
//			tr3("%", i, ok[i]);
//		}
		
	}
	
	if(ans == inf) puts("Impossible");
	else tr(ans);
	
	return 0;
}
