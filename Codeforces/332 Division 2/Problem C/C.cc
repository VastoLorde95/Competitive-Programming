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

int n, h[N], c[N];
set<int> comp;
map<int,int> f;

vector<int> l[N];
int ptr[N];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(h[i]);
		c[i] = h[i];
		comp.insert(h[i]);
	}
	
	int cnt = 1;
	foreach(it, comp){
		f[*it] = cnt++;
	}
	
	sort(c, c+n);
	for(int i = 0; i < n; i++){
		h[i] = f[h[i]];
		c[i] = f[c[i]];
		l[c[i]].pb(i);
	}
	
	int ans = 1, right = l[h[0]][ptr[h[0]]++];
	for(int i = 1; i < n; i++){
		if(i > right){
			ans++;
			right = l[h[i]][ptr[h[i]]++];
		}	
		else{
			right = max(right, l[h[i]][ptr[h[i]]++]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
