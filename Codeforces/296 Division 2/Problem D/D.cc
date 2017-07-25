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

int n, x, w, ans, prev;
vector<pair<int, int> > seg;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(x, w);
		seg.push_back(make_pair(x+w, x-w));
	}
	sort(seg.begin(), seg.end());
	
	prev = 0, ans = 1;
	
	for(int i = 1; i < n; i++){
		if(seg[i].second >= seg[prev].first){
			++ans;
			prev = i;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
