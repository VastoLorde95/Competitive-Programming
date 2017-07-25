#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, m, board[52][52], visited[52][52], flag = 0;
pair<int, int> prev[52][52];
char c;
vector<pair<int, int> > colors[26];

int cycle(int col){
	if(colors[col].size() == 0){
		return 0;
	}
	int c_len, x, y, x2, y2;
	pair<int, int> cur;
	queue<pair<int, int> > q;
	
	for(int i = 0; i < colors[col].size(); i++){
		while(i < colors[col].size() and visited[colors[col][i].first][colors[col][i].second] == 1) i++;
		if(i >= colors[col].size()) return 0;
		
		q.push(colors[col][i]);
		c_len = 1;
		x2 = y2 = -1;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			x = cur.first, y = cur.second;
			visited[x][y] = 1;
			
			//cout<<x<<" "<<y<<endl;
			
			if(board[x+1][y] == board[x][y]){
				if(visited[x+1][y] == 1 and prev[x][y] != make_pair(x+1, y)){
					if(c_len >= 4) return 1;
				}
				else if(visited[x+1][y] == 0){
					prev[x+1][y] = make_pair(x,y);
					q.push(make_pair(x+1, y));
					c_len++;	
				}
			}
			
			if(board[x-1][y] == board[x][y]){
				if(visited[x-1][y] == 1 and prev[x][y] != make_pair(x-1, y)){
					if(c_len >= 4) return 1;
				}
				else if(visited[x-1][y] == 0){
					prev[x-1][y] = make_pair(x,y);
					q.push(make_pair(x-1, y));
					c_len++;	
				}
			}
			
			if(board[x][y+1] == board[x][y]){
				if(visited[x][y+1] == 1 and prev[x][y] != make_pair(x, y+1)){
					if(c_len >= 4) return 1;
				}
				else if(visited[x][y+1] == 0){
					prev[x][y+1] = make_pair(x,y);
					q.push(make_pair(x, y+1));
					c_len++;	
				}
			}
			
			if(board[x][y-1] == board[x][y]){
				if(visited[x][y-1] == 1 and prev[x][y] != make_pair(x, y-1)){
					if(c_len >= 4) return 1;
				}
				else if(visited[x][y-1] == 0){
					prev[x][y-1] = make_pair(x,y);
					q.push(make_pair(x, y-1));
					c_len++;	
				}
			}
			
			x2 = x;
			y2 = y;
		}
	}
	
	return 0;
	
}

int main(){
	memset(board, -1, sizeof board);
	memset(visited, 0, sizeof visited);
	for(int i = 1; i <= 50; i++){
		for(int j = 1; j <= 50; j++){
			prev[i][j] = make_pair(-1, -1);
		}
	}
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c",&c);
			board[i][j] = (int)(c - 'A');
			colors[c - 'A'].push_back(make_pair(i,j));
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(cycle(i) == 1){
			cout<<"Yes"<<endl;
			flag = 1;
			break;
		}
	}
	
	if(flag == 0){
		cout<<"No"<<endl;
	}
	
	return 0;
}
