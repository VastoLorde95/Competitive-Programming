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

int t, n, p[22], mx;

void go(int lvl){
	if(lvl == n-1){
		int sum = 0, mid = n/2;
		for(int j = 0; j < mid; j++){
			sum += abs(p[j] - p[n-j-1]);
		}
		mx = max(mx, sum);
		return;
	}
	
	if(lvl > n-1) return;
	
	if(p[lvl-1]%2 == 0 and p[lvl+1]%2 == 0){
		int tmp = p[lvl];
		p[lvl] = (p[lvl-1]+p[lvl+1])/2;
		go(lvl+1);
		p[lvl] = tmp;
		go(lvl+1);
	}
	else{
		go(lvl+1);
	}
}

int main(){
	sd(t);
	while(t--){
		sd(n);
		mx  = 0;
		for(int i = 0; i < n; i++){
			sd(p[i]);
		}		
		for(int i = 1; i < n; i++){
			if(p[i-1]%2 == 0 and p[i+1]%2 == 0){
				int tmp = p[i];
				p[i] = (p[i-1]+p[i+1])/2;
				go(i+1);
				p[i] = tmp;
				go(i+1);
			}
			else{
				go(i+1);
			}
		}	
		
		printf("%d\n", mx);		
		
	}
	return 0;
}
