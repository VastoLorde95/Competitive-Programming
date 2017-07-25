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

int t, n, r, k, a, b, indegree[1000], processed[1000], cur, i, j;
vector<int> adj_list[1000], current, next;

int main(){
	sd(t);
	for(int T = 1; T <= t; T++){
		sd2(n,r);
		for(i = 0; i <= n; i++){
			adj_list[i].clear();
			processed[i] = 0;
		}
		while(r--){
			sd2(a,b);
			adj_list[b].push_back(a);
			indegree[a]++;
		}		
		for(i = 0; i < n; i++){
			if(indegree[i] == 0){
				current.push_back(i);
			}
		}
		cur = 1;
		printf("Scenario #%d:\n", T);
		while(!current.empty()){
			sort(current.begin(), current.end());
			next.clear();
			for(i = 0; i < current.size(); i++){
				printf("%d %d\n",cur, current[i]);
				processed[current[i]] = 1;
				for(j = 0; j < adj_list[current[i]].size(); j++){
					if(processed[adj_list[current[i]][j]] == 0){
						indegree[adj_list[current[i]][j]]--;
						if(indegree[adj_list[current[i]][j]] == 0) next.push_back(adj_list[current[i]][j]);
					}
				}
			}
			cur++;
			current = next;
		}
	}
	return 0;
}
