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

using namespace std;

int n, visited[26], flag, l1, l2, l, cur;
priority_queue<int> q;
string name[100];
set<int> adj[26], indegree[26];
vector<char> order;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		cin>>name[i];
	}
	for(int i = 0; i < n; i++){
		int j = i + 1;

		if(j < n){
			while(j < n and name[i][0] == name[j][0]){

				if(name[i] == name[j]){
					j++;
					continue;
				}
				
				l1 = name[i].length(); l2 = name[j].length();
				l = min(l1, l2);
				
				flag = 0;
				
				for(int k = 1; k < l; k++){
					if(name[i][k] == name[j][k]) continue;
					else{
						adj[name[i][k] - 'a'].insert(name[j][k] - 'a');
						indegree[name[j][k] - 'a'].insert(name[i][k] - 'a');
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					if(l1 > l2){
						cout<<"Impossible"<<endl;
						return 0;
					}
				}
				j++;
			}
		}
		while(j < n){
			adj[name[i][0] - 'a'].insert(name[j][0] - 'a');
			indegree[name[j][0] - 'a'].insert(name[i][0] - 'a');
			j++;
		}
	}
	
	flag = 0;
	for(int i = 0; i < 26; i++){
		if(indegree[i].size() == 0){
			q.push(-i);
			visited[i] = 1;
			flag = 1;
		}
	}
	
	if(flag == 0){
		cout<<"Impossible"<<endl;
		return 0;
	}

	while(!q.empty()){
	
		cur = -q.top();
		q.pop();
		visited[cur] = 1;
		order.push_back(cur);
		
		for(set<int>::iterator it = adj[cur].begin(); it != adj[cur].end(); it++){
			if(visited[*it] == 1){
				cout<<"Impossible"<<endl;
				return 0;
			}
			else{
				indegree[*it].erase(cur);
				if(indegree[*it].size() == 0){
					q.push(-(*it));
				}
			}
		}
	}
	
	if(order.size() != 26){
		cout<<"Impossible"<<endl;
		return 0;
	}
	
	for(int i = 0; i < 26; i++){
		cout<<(char)(order[i]+'a');
	}
	
	cout<<endl;
	
	return 0;
}
