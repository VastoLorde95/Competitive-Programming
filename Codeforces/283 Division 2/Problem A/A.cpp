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
	int n, heights[100], m;
	vector<int> d;
	sd(n);
	sd(heights[0]);
	sd(heights[1]);
	m = heights[1] - heights[0];
	for(int i = 2; i < n; ++i){
		sd(heights[i]);
		m = max(m, heights[i] - heights[i-1]);
		d.push_back(heights[i] - heights[i-2]);
	}
	sort(d.begin(), d.end());
	if(d[0] <= m){
		printf("%d\n",m);
	}
	else{
		printf("%d\n",d[0]);
	}	
	
}
