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
#define fi first
#define se second

using namespace std;

int n, m, cnt, a, b, flag = 1;
vector<int> adj[100], rem;

int main(){
	sd2(n,m);
	
	for(int i = 0; i < m; i++){
		sd2(a,b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	while(flag){
		flag = 0;
		rem.clear();
		for(int i = 0; i < n; i++){
			if(adj[i].size() == 1){
				flag = 1;
				rem.push_back(i);
			}
		}
		
		if(flag == 1){
			cnt++;
			for(int i = 0; i < rem.size(); i++){
				for(vector<int>::iterator it = adj[adj[rem[i]][0]].begin(); it != adj[adj[rem[i]][0]].end(); it++){
					if(*it  == rem[i]){
						adj[adj[rem[i]][0]].erase(it);
						break;
					}
				}
				adj[rem[i]].clear();
			}
		}
	}
	
	printf("%d\n",cnt);
	
	return 0;
}
