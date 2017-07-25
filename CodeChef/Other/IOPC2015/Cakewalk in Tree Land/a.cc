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

int n, g;
double x, y;
vector<pair<double, double> > p1, p2;
vector<pair<double, double> > hull1, hull2;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%lf%lf%d",&x,&y,&g);
		if(g == 0)
			p1.push_back(make_pair(x, y));
		else
			p2.push_back(make_pair(x, y));
	}
	
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	
	
	
	return 0;
}
