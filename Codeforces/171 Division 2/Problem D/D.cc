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

int n, a[23];
int dp[1<<23][2];

map<int,int> pos;

int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(a[i]);	
	
	int g = a[0];
	for(int i = 1; i < n; i++){
		g = __gcd(g, a[i]);
	}
	
	if(g != a[0]){
		puts("-1"); return 0;	
	}
	
	for(int i = 0; i < n; i++){
		pos[a[i]] = i;
	}
	
	for(int i = 2; i < n; i++){
		bool ok = false;
		for(int j = 0; j < i; j++){
			for(int k = 0; k < i; k++){
				if(a[j]+a[k] == a[i]) ok = true;
				if(a[k] == a[i]) ok = true;
			}
		}
		if(!ok){
			puts("-1"); return 0;
		}
	}
	
	dp[1][0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 1; j < (1<<i); j++){
			dp[j][i&1] = 0;
			if(dp[j][(i^1)&1] == 0) continue;
			for(int k = 0; k < i; k++){
				if((j&(1<<k)) > 0 and pos.count(a[i]-a[k])){
					int ind = pos[a[i]-a[k]];
					if((j&(1<<ind)) > 0){
						int nmask = j|(1<<i);
						dp[nmask][i&1] = 1;
						for(int l = 0; l < i; l++){
							if((nmask&(1<<l)) > 0){
								dp[nmask^(1<<l)][i&1] = 1;
							}
						}
						break;	
					}
				}
			}
		}
	}
		
	int ans = 1000;
	for(int i = 0; i < (1<<n); i++){
		if(dp[i][(n-1)%2] == 1) ans = min(ans, __builtin_popcount(i));
	}

	if(ans == 1000) puts("-1"); else printf("%d\n", ans);
		
	return 0;
}
