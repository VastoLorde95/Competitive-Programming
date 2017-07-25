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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, u, v, w, pre[400001], pw[400001], visited[400001], start;
long long d, sum, dist[400001];
vector<pair<int, int> > adj[400001];

map<pair<int,int>,int> e;

void sp(int s){
	priority_queue<pair<long long, int> > q;
	
	q.push(mp(0,s));
	pre[s] = -1;
	
	pair<long long, int> cur;
	
	while(!q.empty()){
		cur = q.top();
		q.pop();
		
		if(visited[cur.se]) continue;
		
		s = cur.se;
		d = cur.fi;
		
//		tr2("currently at",s);
		
		dist[s] = -d;
		visited[s] = 1;
		
		for(int i = 0; i < adj[s].size(); i++){
			int nxt = adj[s][i].fi;
			if(dist[nxt] > dist[s] + adj[s][i].se){
				
				dist[nxt] = dist[s] + adj[s][i].se;
				
				sum += adj[s][i].se;
				sum -= pw[nxt];
				
				pre[nxt] = s;
				pw[nxt] = adj[s][i].se;
				
				q.push(mp(-dist[nxt], nxt));
			}
			else if(dist[nxt] == dist[s] + adj[s][i].se and sum > sum-pw[nxt]+adj[s][i].se){
				
				sum = sum-pw[nxt]+adj[s][i].se;
				
				pre[nxt] = s;
				pw[nxt] = adj[s][i].se;
				
				
				q.push(mp(-dist[nxt], nxt));
			}
		}
	}
	return;
}

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		sd3(u,v,w);
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));	
		e[mp(u,v)] = i+1;e[mp(v,u)] = i+1;
	}
	
	for(int i = 1; i <= n; i++){
		dist[i] = 1e18;
	}
	
	sd(start);
	
	dist[start] = 0;
	
	sp(start);
	
	tr(sum);
	
	for(int i = 1; i <= n; i++){
		adj[i].clear();
	}	
	
	for(int i = 1; i <= n; i++){
		if(pre[i] != -1){
			cout << e[mp(pre[i],i)] << " ";
		}
	}
	
	cout << endl;
	return 0;
}
