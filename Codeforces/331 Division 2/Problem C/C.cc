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

const int N = 100100, off = N;

typedef pair<int,int> pii;

int n, w[N], inf = 1e9;
vector<pii> vals[off+N];
int ptr[off+N];
pii ans[N];
map<pii, int> m;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int x, y; sd2(x,y);
		if(y-x >= 0){
			vals[off+y-x].pb(mp(x,y));
		}
		else if(y-x < 0){
			vals[off+y-x].pb(mp(y,x));
		}
		m[mp(x,y)] = inf;
	}
	
	for(int i = 0; i < N+off; i++){
		sort(vals[i].begin(), vals[i].end());
	}
	
	for(int i = 0; i < n; i++){
		sd(w[i]);
	}
	
	if(w[0] != 0){
		puts("NO"); return 0;
	}
	
	for(int i = 0; i < n; i++){
		if(ptr[off+w[i]] == vals[off+w[i]].size()){
			puts("NO"); return 0;
		}
		else{
			ans[i] = vals[off+w[i]][ptr[off+w[i]]];
			ptr[off+w[i]]++;
			if(w[i] < 0){
				swap(ans[i].fi, ans[i].se);		
			}
			int x = ans[i].fi, y = ans[i].se;
			m[mp(x,y)] = i+1;
			if(m.count(mp(x-1,y)) and m[mp(x-1,y)] > i+1){
				puts("NO"); return 0;
			}
			if(m.count(mp(x,y-1)) and m[mp(x,y-1)] > i+1){
				puts("NO"); return 0;
			}
		}
	}

	puts("YES");
	for(int i = 0; i < n; i++){
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}	
	
			
	return 0;
}
