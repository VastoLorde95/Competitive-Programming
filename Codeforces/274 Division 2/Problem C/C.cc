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


int n, a, b, mn, prev;
vector<pair<int, int> > dates;
int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(a,b);
		dates.push_back(make_pair(a,b));
	}
	
	sort(dates.begin(), dates.end());
	
	prev = dates[0].se;
	
	for(int i = 1; i < n; i++){
		if(dates[i].se >= prev)
			prev = dates[i].se;
		else{
			prev = dates[i].fi;
		}
	}
	
	cout<< prev << endl;
	
	
	return 0;
}
