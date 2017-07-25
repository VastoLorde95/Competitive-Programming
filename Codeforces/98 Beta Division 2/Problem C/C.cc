#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, x, y, mx, cnt;
vector<pair<int, int> > e;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(x,y);
		e.pb(mp(x,-y));
	}
	
	sort(e.begin(), e.end());
	
	mx = -e[0].se;
	
	for(int i = 1; i < n; i++){
		if(-e[i].se < mx) cnt++; else mx = -e[i].se;
	}
	
	printf("%d\n",cnt);
	return 0;
}
