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

int n, m, grid[52][52], visited[52][52], cntt, flag;
string s;

int go_left(int, int, int, int);
int go_right(int, int, int, int);
int go_down(int, int, int, int);
int go_up(int, int, int, int);


int go_right(int i, int j, int cnt, int t){
	if(grid[i][j] != 1)
		return 0;
	if(visited[i][j] == 0){
		visited[i][j] = 1;
		cnt = 1;
	}
	else{
		cnt = 0;
	}
	
	//cout << "right " << i << " " << j << endl;
	
	cnt += go_right(i, j+1, cnt, t);
	if(t == 0){
		cnt += go_up(i-1, j, cnt, t+1);
		cnt += go_down(i+1, j, cnt, t+1);
	}
	
	return cnt;
}

int go_left(int i, int j, int cnt, int t){
	if(grid[i][j] != 1)
		return 0;
	if(visited[i][j] == 0){
		visited[i][j] = 1;
		cnt = 1;
	}
	else{
		cnt = 0;
	}
	//cout << "left " << i << " " << j << endl;
	
	cnt += go_left(i, j-1, cnt, t);
	if(t == 0){
		cnt += go_up(i-1, j, cnt, t+1);
		cnt += go_down(i+1, j, cnt, t+1);
	}
	
	return cnt;
}

int go_down(int i, int j, int cnt, int t){
	if(grid[i][j] != 1)
		return 0;
	if(visited[i][j] == 0){
		visited[i][j] = 1;
		cnt = 1;
	}
	else{
		cnt = 0;
	}
	
	//cout<< i << " " << j << endl;
	
	cnt += go_down(i+1, j, cnt, t);
	if(t == 0){
		//cout<< "entering" <<endl;
		cnt += go_left(i, j-1, cnt, t+1);
		
		cnt += go_right(i, j+1, cnt, t+1);
		//cout<< "exiting" <<endl;
	}
	
	return cnt;
}

int go_up(int i, int j, int cnt, int t){
	if(grid[i][j] != 1)
		return 0;
		
	if(visited[i][j] == 0){
		visited[i][j] = 1;
		cnt = 1;
	}
	else{
		cnt = 0;
	}
	
	cnt += go_up(i-1, j, cnt, t);
	if(t == 0){
		cnt += go_left(i, j-1, cnt, t+1);
		cnt += go_right(i, j+1, cnt, t+1);
	}
	
	return cnt;
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i <= 51; i++){
		for(int j = 0; j <= 51; j++){
			grid[i][j] = -1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		cin>>s;
		for(int j = 1; j <= m; j++){
			if(s[j-1] == 'B'){
				grid[i][j] = 1;
				cntt++;
			}
			else grid[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(grid[i][j] == 1){
				memset(visited, 0, sizeof visited);
				
				visited[i][j] = 1;
				
				int c1 = 1;
				c1 += go_up(i-1, j, 0, 0);
				
				//cout << c1 << endl;
				
				c1 += go_down(i+1, j, 0, 0);
				
				//cout << c1 << endl;				
				
				c1 += go_left(i, j-1, 0, 0);
				
				//cout << c1 << endl;				
				
				c1 += go_right(i, j+1, 0, 0);
				
				//cout<< i << " " << j << " " <<  c1 << " " << cntt << endl;
				
				if(c1 != cntt){
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	
	
	cout<< "YES\n";
	
	return 0;
}
