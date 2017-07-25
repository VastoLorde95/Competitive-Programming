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

int n, a, b, p[100100], res[100100], v[100100], deg[100100], cnt;
map<int, int> m;
vector<pair<int, int> > g[100100];

void dfs(int cur, int prev){
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		
		res[cur] = res[it->fi] = it->se;
		cnt += 2;
		dfs(it->fi, cur);
		return;
	}
}

int main(){
	sd3(n,a,b);
	for(int i = 0; i < n; i++){
		sd(p[i]);
		m[p[i]] = i;
		res[i] = -1;
	}
	
	for(int i = 0; i < n; i++){
		if(m.count(a-p[i])){
			g[i].pb(mp(m[a-p[i]], 0));
			deg[i]++;
		}
		if(m.count(b-p[i])){
			g[i].pb(mp(m[b-p[i]], 1));
			deg[i]++;
		}
	}
	
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(deg[i] == 0){
			puts("NO"); return 0;
		}
		if(deg[i] == 1){
			q.push(i);
		}
	}
	
	int cur, nxt;
	while(!q.empty()){
		cur = q.front(); q.pop();
		
		if(v[cur] == 1) continue;
		
		int color;
		
		nxt = -1;
		
		foreach(it, g[cur]){
			if(!v[it->fi]){
				nxt = it->fi;
				color = it->se;
			}
		}
		
		if(nxt != -1){
			if(nxt == cur){
				res[cur] = color;
				v[cur] = 1;
				deg[cur]--;
				cnt++;
			}
			else{
				res[cur] = res[nxt] = color;
				v[cur] = v[nxt] = 1;
				deg[nxt]--, deg[cur]--;
				cnt += 2;
			}
			
			foreach(it, g[nxt]){
				deg[it->fi]--;
				if(!v[it->fi] and deg[it->fi] == 1){
					q.push(it->fi);
				}
			}
			
		}
		else{
			puts("NO"); return 0;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(res[i] == -1){
			dfs(i, -1);
		}
	}
	
	if(cnt < n){
		puts("NO"); return 0;
	}
	
	puts("YES");
	for(int i = 0; i < n; i++){
		printf("%d ", res[i]);
	}
	printf("\n");
	
	return 0;
}
