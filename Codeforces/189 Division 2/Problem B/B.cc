#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int n, t, a, b, cur;
vector<int> adj[100];
pair<int, int> s[100];

int bfs(int x, int y){
	int visited[100];
	memset(visited, 0, sizeof(visited));
	
	queue<int> q;
	
	int cur = x;
	q.push(x);
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		if(visited[cur] == 1)
			continue;
		
		visited[cur] = 1;
		
		if(cur == y)
			return 1;
		
		for(int i = 0; i < adj[cur].size(); i++){
			if(visited[adj[cur][i]] == 0){
				q.push(adj[cur][i]);
			}
		}
	}
	
	return 0;
	
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd3(t,a,b);
		if(t == 1){
			s[cur] = make_pair(a,b);
			for(int i = 0; i < cur; i++){
				if((s[i].fi < a  and a < s[i].se) or (s[i].fi < b and b < s[i].se)){
					adj[cur].push_back(i);
				}
				if((a < s[i].fi  and s[i].fi < b) or (a < s[i].se and s[i].se < b)){
					adj[i].push_back(cur);
				}
			}
			cur++;
		}
		else{
			if(bfs(a-1,b-1))
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}
