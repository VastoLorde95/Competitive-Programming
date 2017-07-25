#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int x1, x2, Y1, y2, n, r, a, b;
set<pair<int, int> > nodes;
map<pair<int, int>, int> visited;
map<pair<int, int>, vector<pair<int, int> > > adj;

void bfs(pair<int, int> cur, pair<int, int> target){
	int d;
	queue<pair<pair<int, int>, int> > q;
	q.push(mp(cur,0));
	
	while(!q.empty()){
		cur = q.front().fi; d = q.front().se; q.pop();
		
//		cout << "Currently at " << cur.fi << ", " << cur.se << endl;
		
		if(visited.find(cur) != visited.end()) continue;
	
		visited[cur] = d;
		
		if(cur == target) return;
		
		for(int i = 0; i < adj[cur].size(); i++){
			if(visited.find(adj[cur][i]) == visited.end()){
				q.push(mp(adj[cur][i], d+1));
			}
		}	
		
	}
	
	return;
	
}


int main(){
	
	sd2(x1, Y1);
	sd2(x2, y2);	
	
	sd(n);
	for(int i = 0; i < n; i++){
		sd3(r,a,b);
		for(int i = a; i <= b; i++){
			nodes.insert(mp(r,i));
		}
	}
	
	for(set<pair<int, int> >::iterator it = nodes.begin(); it != nodes.end(); it++){
		pair<int, int> p = *it;
		int x = p.fi, y = p.se;
		
		if(nodes.find(mp(x-1,y-1)) != nodes.end()) adj[p].pb(mp(x-1, y-1));
		if(nodes.find(mp(x-1,y)) != nodes.end())   adj[p].pb(mp(x-1, y));
		if(nodes.find(mp(x-1,y+1)) != nodes.end()) adj[p].pb(mp(x-1, y+1));
		if(nodes.find(mp(x,y-1)) != nodes.end())   adj[p].pb(mp(x, y-1));
		if(nodes.find(mp(x,y+1)) != nodes.end())   adj[p].pb(mp(x, y+1));
		if(nodes.find(mp(x+1,y-1)) != nodes.end()) adj[p].pb(mp(x+1, y-1));
		if(nodes.find(mp(x+1,y)) != nodes.end())   adj[p].pb(mp(x+1, y));
		if(nodes.find(mp(x+1,y+1)) != nodes.end()) adj[p].pb(mp(x+1, y+1));
	}
	
	bfs(mp(x1,Y1), mp(x2,y2));
	
	if(visited.find(mp(x2,y2)) != visited.end()) printf("%d\n", visited[mp(x2,y2)]);
	else printf("-1\n");
	
	return 0;
}
