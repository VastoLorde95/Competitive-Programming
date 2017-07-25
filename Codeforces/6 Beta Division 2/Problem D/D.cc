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

int n, x, y;
int h[20], p[1000], res[1000];
int ans = 1e9;

void attack(int &a, int &b, int &c){
	a -= y; if(a < 0) a = 0;
	b -= x; if(b < 0) b = 0;
	c -= y; if(c < 0) c = 0;
}

void go(int cur, int a, int b, int c, int lvl){
	if(lvl >= ans) return;
	if(cur == n){
		if(a+b+c == 0){
			ans = lvl;
			for(int i = 0; i < ans; i++) res[i] = p[i];
		}
		return;
	}
	
	while(a > 0){
		attack(a,b,c);
		p[lvl++] = cur;
	}	
	
	go(cur+1,b,c,h[cur+2],lvl);
	
	while(b+c > 0){
		attack(a,b,c);
		p[lvl++] = cur;
		go(cur+1,b,c,h[cur+2],lvl);
	}
}

int main(){
	sd3(n,x,y);
	for(int i = 1; i <= n; i++){
		sd(h[i]);
		h[i]++;
	}
	
	go(2,h[1],h[2],h[3],0);
	
	printf("%d\n", ans);
	for(int i = 0; i < ans; i++){
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}
