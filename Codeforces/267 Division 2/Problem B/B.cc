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

int n, m, k, cnt, res, x[1001];

int main(){
	cin>>n>>m>>k;
	for(int i = 0; i < m+1; i++){
		cin>>x[i];
	}	
	for(int i = 0; i < m; i++){
		cnt = 0;
		for(int j = 0; j < n; j++){
			int a = (x[i]&(1<<j));
			int b = (x[m]&(1<<j));
			if(a != b){
				cnt++;
			}
		}
		if(cnt <= k) res++;	
	}
	
	cout<< res <<endl;
	return 0;
}
