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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 100100;
int n, a[N], b[N], inf = 1e9;
int p1[N], p2[N], dis[N];

set<pair<int,int> > s1, s2;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
		p1[a[i]] = i;
	}
	
	for(int i = 0; i < n; i++){
		sd(b[i]);
		p2[b[i]] = i;
	}
	
		
	for(int i = 0; i < n; i++){
		if(i <= p1[b[i]]){
			s1.insert(mp(p1[b[i]]-i, b[i]));	
			dis[b[i]] = p1[b[i]]-i;
		}
		else{
			s2.insert(mp(i-p1[b[i]], b[i]));
		}
	}
	
	for(int i = 0; i < n; i++){
		int v1 = inf, v2 = inf;
		
		if(!s1.empty()) v1 = min(v1, s1.begin()->fi+i);
		if(!s2.empty()) v2 = min(v2, s2.begin()->fi-i);
		printf("%d\n", min(v1,v2));
		
		s1.erase(mp(dis[b[i]], b[i]));
		s2.insert(mp(n-p1[b[i]]+i, b[i]));
		
		while(!s2.empty() and s2.begin()->fi == i+1){
			int x = s2.begin()->se;
			dis[x] = -i-1;
			s1.insert(mp(dis[x],x));
			s2.erase(s2.begin());
		}
		
	}
	
	return 0;
}
