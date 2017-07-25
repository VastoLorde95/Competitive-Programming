#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	

int n, p[300], visited[300], res[300];
string a[300];
vector<int> comp[300][2];

void get_connected_components(){
	int count = 0, c = 0, k;
	stack<int> s;
	memset(visited, 0, sizeof visited);
	while(count != n){
		k = 0;
		while(visited[k] == 1) k++;
		
		s.push(k);	
		visited[k] = 1;	
		while(!s.empty()){
			k = s.top();
			s.pop();
			comp[c][0].push_back(p[k]);
			comp[c][1].push_back(k);
			count++;
			for(int i = 0; i < n; i++){
				if(a[k][i] == '1' and visited[i] == 0){
					s.push(i);
					visited[i] = 1;
				}
			}				
		}
		c++;
	}
	
	for(int i = 0; i < c; i++){
		sort(comp[i][0].begin(), comp[i][0].end());
		sort(comp[i][1].begin(), comp[i][1].end());
		for(int j = 0; j < comp[i][0].size(); j++){
			res[comp[i][1][j]] = comp[i][0][j];
		}
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>p[i];
	}
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	
	get_connected_components();
	
	for(int i = 0; i < n; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
