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

int m, n, k, a, b, indegree[101];
vector<int> adj_list[101];
priority_queue<int> q;

int main(){
	memset(indegree, 0, sizeof(indegree));
	sd2(n,m);
	while(m--){
		sd(a);
		sd(k);
		indegree[a] += k;
		while(k--){
			sd(b);
			adj_list[b].push_back(a);
		}
	}
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0)
			q.push(-i);
	}
	while(!q.empty()){
		a = -q.top();
		q.pop();
		printf("%d ", a);
		for(int i = 0; i < adj_list[a].size(); i++){
			indegree[adj_list[a][i]]--;
			if(indegree[adj_list[a][i]] == 0)
				q.push(-adj_list[a][i]);
		}
	}
	cout<<endl;
	return 0;
}
