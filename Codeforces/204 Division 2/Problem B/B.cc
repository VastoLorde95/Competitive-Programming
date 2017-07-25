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

int n, num, mx, cnt;
vector<int> pos[100001];

int is_ap(int p){
	if(pos[p].size() == 0)
		return 0;
	if(pos[p].size() == 1){
		return 1;
	}
	int diff = pos[p][1] - pos[p][0];
	
	for(int i = 2; i < pos[p].size(); i++){
		if(pos[p][i] - pos[p][i-1] != diff)
			return 0;
	}
	
	return 1;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(num);
		pos[num].push_back(i);
		mx = max(mx, num);
	}
	
	for(int i = 1; i <= mx; i++){
		if(is_ap(i)){
			cnt++;
		}
	}	
			
	cout<< cnt <<endl;
	
	if(cnt)
		for(int i = 1; i <= mx; i++){
			if(is_ap(i)){
				cnt++;
				if(pos[i].size() == 1){
					cout<<i<<" 0"<<endl;
				}
				else{
					cout<<i<<" "<<pos[i][1]-pos[i][0]<<endl;
				}	
			}
		}	
	return 0;
}
