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

int t, n, a, b, r, cnt;
vector<pair<int, int> > p;

int main(){
	sd(t);
	while(t--){
		sd(n);
		cnt = 0;
		p.clear();
		for(int i = 0; i < n; i++){
			sd2(a,b);
			p.push_back(make_pair(b,a));
		}
		
		sort(p.begin(), p.end());
		
		r = p[0].fi;
		cnt = 1;
		for(int i = 1; i < n; i++){
			if(p[i].se > r){
				cnt++;
				r = p[i].fi;
			}
		}
			
		printf("%d\n",cnt);
	}
	return 0;
}
