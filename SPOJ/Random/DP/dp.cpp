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

int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int c, m, n, dist[3000], start, ND, node, node2, a, b, N;
vector<pair<int,int> > graph[3000];	//adjacency list representation
vector<int> times;
vector<int> delivery;
char grid[55][55];

void dijkstra(int s){
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0, s));
	memset(dist, -1, sizeof(dist));
	while(!pq.empty()){
		pair<int, int> w = pq.top();
		pq.pop();
		if (dist[w.second]!=-1)
			continue;
		dist[w.second] = w.first;
		for (int i = 0; i < graph[w.second].size(); i++){
			pair<int, int> w1 = graph[w.second][i];
			pq.push(make_pair(w.first + w1.first, w1.second));
		}
	}
}

int minimize(int n2, int bitmask){
	if(n2 == ND){
		int boy1 = 0, boy2 = 0, m1 = -1, m2 = -1;
		for(int i = 0; i < ND; i++){
			if(bitmask&(1<<i)){
				boy1 += (times[i] * 2);
				m1 = i;
			}
			else{
				boy2 += (times[i] * 2);
				m2 = i;
			}
		}
		if(m1 != -1)
			boy1 -= times[m1];
		if(m2 != -1)
			boy2 -= times[m2];
		return max(boy1, boy2);
	}
	else
		return min(minimize(n2+1,bitmask|(1<<n2)), minimize(n2+1, bitmask));
}

int result(int start){
	for(int i = 0; i < ND; i++){
		if(dist[delivery[i]] != -1){
			times.push_back(dist[delivery[i]]);
		}
		else return -1;
	}
	sort(times.begin(), times.end());
	return minimize(0,0);
}

int main(){
	sd(c);
	while(c--){
		sd2(m,n);
		for(int i = 0; i < m; i++){
			cin>>grid[i];
		}
		node = 0, start = -1, N = n*m;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] == '$')
					delivery.push_back(node);
				else if(grid[i][j] == 'X')
					start = node;
				for(int k = 0; k < 4; k++){
					a = i + x[k], b = j + y[k], node2 = node + y[k] + x[k]*n;
					if(a < 0 || b < 0 or a >= m || b >= n)
						continue;
					if (grid[i][j]=='$' or grid[i][j]=='X')//moving from a building
						graph[node].push_back(make_pair(2, node2));
					else if(grid[a][b] == '$' or grid[a][b] == 'X')//moving to a building
						graph[node].push_back(make_pair(2, node2));
					else if(abs((grid[i][j] - '0') -  (grid[a][b] - '0')) == 0)//moving to same height
						graph[node].push_back(make_pair(1,node2));
					else if(abs((grid[i][j] - '0') -  (grid[a][b] - '0')) == 1)//moving to height +-1
						graph[node].push_back(make_pair(3,node2));
				}
				node++;
			}
		}
		
		ND = delivery.size();
		if(ND == 0 or start == -1){
			delivery.clear();
			times.clear();
			for(int i = 0; i < N; i++){
				graph[i].clear();
			}
			cout<<0<<endl;
			continue;
		}
		
		dijkstra(start);
		
		
		printf("%d\n", result(start));
		
		times.clear();
		delivery.clear();
		for(int i = 0; i < N; i++){
			graph[i].clear();
		}
	}
	return 0;
}
