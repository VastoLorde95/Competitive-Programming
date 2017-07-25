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

int grid[2000][2000], w, h, k, mx, p, x, y, id;
vector<pair<int, int> > vals;
int main(){
	sd3(h, w, k);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < h; j++){
			grid[i][j] = 0;
		}
	}
	mx = -1;
	for(int i = 0; i < k; i++){
		sd(p);
		if(p <= mx){
			for(int j = 0; j < p; j++){
				sd2(x, y);
			}
		}
		else{
			mx = p;
			vals.clear();
			id = i + 1;
			for(int j = 0; j < p; j++){
				sd2(x, y);
				vals.push_back(make_pair(x-1, y-1));
			}
		}
	}
	
	for(int i = 0; i < vals.size(); i++){
		grid[vals[i].first][vals[i].second] = id;
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
