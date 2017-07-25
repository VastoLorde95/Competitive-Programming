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
#include<queue>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int n, capacity[125][125], flow, INF = 1000000;
char S = 'A', T = 'Z', s, t;
vector<int> graph[125];

int find_path(){
	queue<int> Q;
	int visited[125]; memset(visited, 0, sizeof(visited));
	int from[125]; memset(from, -1, sizeof(from));
	int where, next, prev, flag = 1, path_cap = INF;
	Q.push(S); visited[S] = 1;
	while(!Q.empty() and flag == 1){
		where = Q.front();
		Q.pop();
		for(int i = 0; i < graph[where].size(); i++){
			next = graph[where][i];
			if(visited[next] != 1 and capacity[where][next] > 0){
				Q.push(next);
				visited[next] = 1;
				from[next] = where;
				if(next == T){
					flag = 0;
					break;
				}
			}
		}
	}
	
	where = T;
	while(from[where] > -1){
		prev = from[where];
		path_cap = min(path_cap, capacity[prev][where]);
		where = prev;
	}
	
	where = T;
	while(from[where] > -1){
		prev = from[where];
		capacity[prev][where] -= path_cap;
		capacity[where][prev] -= path_cap;
		where = prev;
	}
	
	if(path_cap == INF)
		return 0;
	return path_cap;
	
}

int max_flow(){
	int result = 0, path_cap;
	while(true){
		path_cap = find_path();
		if(path_cap == 0)
			return result;
		result += path_cap;
	}
	return result;
}

int main(){
	sd(n);
	memset(capacity, 0, sizeof(capacity));
	for(int i = 0; i < n; i++){
		scanf(" %c %c %d",&s,&t,&flow);
		//cout<<s<<" "<<t<<endl;
		if(capacity[s][t] == 0)
			graph[s].push_back(t);
		capacity[s][t] += flow;
	}
	/*for(int i =67; i < 125; i++){
		for(int j = 67; j < 125; j++)
			cout<<capacity[i][j]<<" ";
		cout<<endl;
	}*/
	printf("%d\n",max_flow());
	return 0;
}
