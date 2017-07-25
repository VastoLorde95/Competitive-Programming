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

const int N = 20100;

int n;
vector<pair<int,int> > g[N];

int visited[N];
int st[N], tp;

int main(){
	sd(n);
	int u, v; char c;
	for(int i = 1; i < n; i++){
		scanf("%d %d %c", &u, &v, &c);
		g[u].pb(mp(v,c-'a'));
		g[v].pb(mp(u,c-'a'));
	}
	
	vector<pair<int, int> > next;
	int cur = 0;
	for(int i = 1; i <= n; i++){
		st[tp++] = i;
		while(tp >= 1){
			int mn = 0, mx = 0;
			next.clear();
			while(tp >= 1){
				cur = st[--tp];
				mx = max(mx, cur);
				visited[cur] = i;
			
				foreach(it, g[cur]){
					if(visited[it->fi] == i) continue;
					if(it->se > mn){
						mn = it->se;
						next.clear();
						next.pb(*it);
					}
					else if(it->se == mn){
						next.pb(*it);	
					}
				}
			}
			
			if(next.size() == 0){
				printf("%d ", mx);
			}
			else{
				foreach(it, next){
					st[tp++] = it->fi;
				}
			}
		}
	}
	
	puts("");
	
	return 0;
}
