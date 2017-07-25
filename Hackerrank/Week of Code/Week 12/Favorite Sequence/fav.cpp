/*
This is Donald Knuth's Algorithm for Lexicographically first Topological Sort
If indegree of a vertex is 0, it should be printed.
If many such vertices have indegree 0, the one with the smallest number is printed first i.e
if nodes 2 and 3 both have indegree 0 then 2 will be printed before 3

O(nlogn + m) where n =  |V| and m  = |E|
*/
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

int n, k, present[1000001], indegree[1000001], cur, nxt;
vector<int> adj_list[1000001];
priority_queue<int> q;

int main(){
	sd(n);
	while(n--){
		sd(k);
		sd(cur);
		present[cur] = 1;	
		for(int i = 1; i < k; i++){
			sd(nxt);
			indegree[nxt]++;	//Incrasing the indegree of a node by 1
			adj_list[cur].push_back(nxt); // buliding the adjacency list
			cur = nxt;
			present[cur] = 1;	//The node is present
		}
	}
	
	for(int i = 0; i <= 1000000; i++){
		if(present[i] and indegree[i] == 0){
			q.push(-i);		// Since the nodes with indegree 0 are printed first, they are added to the priority queue
		}
	}
	while(!q.empty()){
		cur = -q.top(); 	// A node with zero indegree is extracted from the queue
		q.pop();
		printf("%d ",cur);
		for(int i = 0; i < adj_list[cur].size(); i++){
			indegree[adj_list[cur][i]]--;	// Since the extracted vertex is deleted from the graph. The indegrees of all its neighbours is reduced by 1.
			if(indegree[adj_list[cur][i]] == 0)
				q.push(-adj_list[cur][i]);	// If we come across a  vertex with 0 indegree then we add it to the queue
		}
	}
	printf("\n");
}
