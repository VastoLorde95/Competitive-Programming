#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int N = 100100;

typedef pair<int,int> pii;

int n, m;
vector<int> r[N], c[N];
vector<pii> d1[N+N], d2[N+N];

int ans[9];

vector<pii> queens;

int main(){
	sd2(n,m);
	int x, y;
	for(int i = 0; i < m; i++){
		sd2(x,y);
		r[x].pb(y);
		c[y].pb(x);
		d1[x-y+n].pb(mp(x,y));
		d2[x+y].pb(mp(x,y));
		
		queens.pb(mp(x,y));
	}
	
	for(int i = 1; i <= n; i++){
		sort(r[i].begin(), r[i].end());
		sort(c[i].begin(), c[i].end());
	}
	
	for(int i = 1; i < 2*n; i++){
		sort(d1[i].begin(), d1[i].end());
		sort(d2[i+1].begin(), d2[i+1].end());
	}	
	
	int cnt;
	foreach(it, queens){
		x = it->fi, y = it->se, cnt = 0;
		
		if(upper_bound(r[x].begin(), r[x].end(), y) != r[x].end()) cnt++;
		if(lower_bound(r[x].begin(), r[x].end(), y) != r[x].begin()) cnt++;
		
		if(upper_bound(c[y].begin(), c[y].end(), x) != c[y].end()) cnt++;
		if(lower_bound(c[y].begin(), c[y].end(), x) != c[y].begin()) cnt++;
	
		if(upper_bound(d1[x-y+n].begin(), d1[x-y+n].end(), mp(x,y)) != d1[x-y+n].end()) cnt++;
		if(lower_bound(d1[x-y+n].begin(), d1[x-y+n].end(), mp(x,y)) != d1[x-y+n].begin()) cnt++;
		
		if(upper_bound(d2[x+y].begin(), d2[x+y].end(), mp(x,y)) != d2[x+y].end()) cnt++;
		if(lower_bound(d2[x+y].begin(), d2[x+y].end(), mp(x,y)) != d2[x+y].begin()) cnt++;
		
		ans[cnt]++;
	}	
	
	for(int i = 0; i < 9; i++) printf("%d ", ans[i]);
	puts("");
	
	return 0;
}
