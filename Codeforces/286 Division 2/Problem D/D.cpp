#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

vector<int> graph[100001], rev_graph[100001];
vector<int> order;
int visited[100001], comp[100001], comp_size[100001], n, m, a, b, no_of_comp = 0, res;

void dfs(int v){
	visited[v] = 1;
	for(int i = 0; i < graph[v].size(); i++){
		if(visited[graph[v][i]] != 1) dfs(graph[v][i]);
	}
	order.push_back(v);
}

void rev_dfs(int v, int k){
	visited[v] = 1; comp[v] = k;
	for(int i = 0; i < rev_graph[v].size(); i++){
		if(visited[rev_graph[v][i]] != 1) rev_dfs(rev_graph[v][i], k);
	}
	return;
}

void strongy_connected_components(){
	for(int i = 1; i <= n; i++){
		if(visited[i] != 1) dfs(i);
	}

	for(int i = 1; i <= n; i++) visited[i] = 0;
	
	for(int i = order.size() - 1; i >= 0; i--){
		if(visited[order[i]] != 1) rev_dfs(order[i], no_of_comp++);
	}
	return;
}

int solve(int v){
	visited[v] = 1;
	int ret = (comp_size[comp[v]] == 1);
	for(int i = 0; i < graph[v].size(); i++){
		if(visited[graph[v][i]] != 1) ret &= solve(graph[v][i]);
	}
	
	for(int i = 0; i < rev_graph[v].size(); i++){
		if(visited[rev_graph[v][i]] != 1) ret &= solve(rev_graph[v][i]);
	}
	
	return ret;
}

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		sd2(a,b);
		graph[a].push_back(b);
		rev_graph[b].push_back(a);
	}
	
	strongy_connected_components();
	
	for(int i = 1; i <= n; i++){
		comp_size[comp[i]]++;
	}
	
	for(int i = 1; i <= n; i++) visited[i] = 0;
	
	res = n;
	
	for(int i = 1; i <= n; i++){
		if(visited[i] != 1) res -= solve(i);
	}
	
	printf("%d\n", res);
	
	return 0;
}
