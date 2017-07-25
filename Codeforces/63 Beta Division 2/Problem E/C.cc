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

int n, k;
int a[N];
int c[N], invf[N];
set<int> comp, s;
map<int,int> f;
int cnt;

int main(){
	sd2(n,k);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		comp.insert(a[i]);
	}
	
	foreach(it, comp){
		f[*it] = cnt;
		invf[cnt++] = *it;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = f[a[i]];
	}
	
	for(int i = 0; i < k; i++){
		c[a[i]]++;
		if(c[a[i]] == 1){
			s.insert(a[i]);
		}
		else{
			s.erase(a[i]);
		}
	}
	
	if(s.empty()) puts("Nothing");
	else printf("%d\n", invf[*s.rbegin()]);
	
	for(int i = k; i < n; i++){
		c[a[i-k]]--;
		if(c[a[i-k]] == 1){
			s.insert(a[i-k]);
		}
		else if(s.count(a[i-k])) s.erase(a[i-k]);
		
		c[a[i]]++;
		if(c[a[i]] == 1){
			s.insert(a[i]);
		}
		else if(s.count(a[i])) s.erase(a[i]);
		
		if(s.empty()) puts("Nothing");
		else printf("%d\n", invf[*s.rbegin()]);
		
	}
	
	return 0;
}
