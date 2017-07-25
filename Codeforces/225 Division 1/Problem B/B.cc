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
int n, m, x[N], y[N], v[N];
map<int, map<int, int> > m1, m2;
queue<int> q;

map<int,int>::iterator it;

// collapse all "walls" starting from x = 1 or y = n and see if you are able to block x = n and y = 1 also from it
// if yes then no path exists

int main(){
	sd2(n, m);
	for(int i = 1; i <= m; i++){
		sd2(x[i], y[i]);
		if(x[i] == 1 or y[i] == n){
			v[i] = 1;
			q.push(i);
		}
		m1[x[i]][y[i]] = i;
		m2[y[i]][-x[i]] = i;
	}
	
	while(!q.empty()){
		int id = q.front(); q.pop();
		if(x[id] == n or y[id] == 1){
			// We have encountered a "wall" that blocks our path
			puts("-1"); return 0;
		}
		
		// connect the edge from (x,y) to the next blocked point in [x+1,y-1...n] if any and column [1...x+1,y-1] if any
		if(m1.count(x[id]+1)){
			it = m1[x[id]+1].lower_bound(y[id]-1);
			if(it != m1[x[id]+1].end() and v[it->se] == 0){
				v[it->se] = 1;
				q.push(it->se);
			}
		}
		if(m2.count(y[id]-1)){
			it = m2[y[id]-1].lower_bound(-x[id]-1);
			if(it != m2[y[id]-1].end() and v[it->se] == 0){
				v[it->se] = 1;
				q.push(it->se);
			}
		}
	}
		
	printf("%d\n", n+n-2);
	
	return 0;
}
