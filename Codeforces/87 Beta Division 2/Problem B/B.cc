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

using namespace std;

int n, m, cnt2, res;
int grid[12][12], cnt[12][12];
string s;

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		cin>>s;
		for(int j = 1; j <= m; j++){
			if(s[j-1] == '.')
				grid[i][j] = 0;
			else if(s[j-1] == 'P')
				grid[i][j] = 1;
			else
				grid[i][j] = 2;
		}
	}
	
	for(int i = 1; i <= n; i++){
		cnt2 = 0;
		for(int j = 1; j <= m; j++){
			if(grid[i-1][j] == 1) cnt2++;
			if(grid[i+1][j] == 1) cnt2++;
			if(grid[i][j-1] == 1) cnt2++;
			if(grid[i][j+1] == 1) cnt2++;
			
			cnt[i][j] = cnt2;
		}
	}	
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(grid[i][j] == 1){
				vector<pair<int, pair<int, int> > > temp;
				if(grid[i-1][j] == 2) temp.push_back(make_pair(cnt[i-1][j], make_pair(i-1, j)));
				if(grid[i+1][j] == 2) temp.push_back(make_pair(cnt[i+1][j], make_pair(i+1, j)));
				if(grid[i][j-1] == 2) temp.push_back(make_pair(cnt[i][j-1], make_pair(i, j-1)));
				if(grid[i][j+1] == 2) temp.push_back(make_pair(cnt[i][j+1], make_pair(i, j+1)));
				
				if(temp.size()){
					sort(temp.begin(), temp.end());
					grid[temp[0].second.first][temp[0].second.second] = 0;
					res++;
					grid[i][j] = 0;
				}
				
			}
		}
	}
	
	cout<< res <<endl;
	return 0;
}
