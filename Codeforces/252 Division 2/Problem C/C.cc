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

int n, m, k, val, rem, cnt, cur;
vector<pair<int, int> > pts[100000];


int main(){
	sd3(n,m,k);
	
	val = (n*m)/k;
	
	cur = 0;
	
	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			for(int j = 0; j < m; j++){
				pts[cur].push_back(make_pair(i,j));
				cnt++;
				if(cnt == val){
					cnt = 0;
					cur++;
					if(cur == k) cur--;
				}			
			}
		}
		else{
			for(int j = m-1; j >= 0; j--){
				pts[cur].push_back(make_pair(i,j));
				cnt++;
				if(cnt == val){
					cnt = 0;
					cur++;
					if(cur == k) cur--;
				}		
			}
		}
	}
	
	for(int i = 0; i < k; i++){
		printf("%d ", (int) pts[i].size());
		for(int j = 0; j < pts[i].size(); j++){
			printf("%d %d ", pts[i][j].fi+1, pts[i][j].se+1);
		}
		printf("\n");	
	}
	
	
	return 0;
}
