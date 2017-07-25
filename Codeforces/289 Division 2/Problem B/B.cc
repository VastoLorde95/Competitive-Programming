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

int main(){
	int n, k, p[100], colors[100][101], temp[100][101], c, first, flag, number = 0, cnt = 0, cur;
	pair<int, int> ans[100];
	memset(colors, 0, sizeof colors);
	memset(temp, 0, sizeof temp);
	
	sd2(n, k);
	
	for(int i = 0; i < n; i++){
		sd(p[i]);
		number += p[i];
		ans[i] = make_pair(p[i], i);
	}
	
	sort(p, p+n);
	sort(ans, ans + n);
	
	for(int i = 0; i < n; i++){
		c = 0;
		int x = p[i]/k;
		int rem = p[i]%k;
		for(int j = 1; j <= rem; j++){
			colors[i][j] += (x+1);
			for(int r = 0; r < i; r++){
				if(colors[r][j] == colors[i][j] or colors[r][j] == colors[i][j]+1 or colors[r][j] == colors[i][j]-1) continue;
				else{
					cout<<"NO"<<endl;
					return 0;
				}
			}	
		}
		for(int j = rem+1; j <= k; j++){
			colors[i][j] += x;
			for(int r = 0; r < i; r++){
				if(colors[r][j] == colors[i][j] or colors[r][j] == colors[i][j]+1 or colors[r][j] == colors[i][j]-1) continue;
				else{
					cout<<"NO"<<endl;
					return 0;
				}
			}	
		}
	}

	cout<<"YES"<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= k; j++){
			while(colors[i][j] > 0){
				colors[i][j]--;
				temp[ans[i].second][j]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= k; j++){
			while(temp[i][j] > 0){
				printf("%d ",j);
				temp[i][j]--;
			}
		}
		printf("\n");
	}
		
	return 0;
}
