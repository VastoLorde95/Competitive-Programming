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

typedef long long ll;

ll dp[1<<16][2];
int a[16];

ll go(int x){
	int v[16], cur = 0;
	for(int i = 0; i < 16; i++){
		if(i != x) v[cur++] = a[i];
	}
	
	memset(dp, 0, sizeof dp);
	
	int up = (1<<15)-1;
	dp[0][0] = 1;
	
	for(int i = 0; i < up; i++){
		for(int j = 0; j < 2; j++){
			if(dp[i][j] == 0) continue;
			int nxt = __builtin_popcount(i);
			for(int k = 1; k < 16; k++){
				if((i&(1<<(k-1))) == 0 and (v[nxt]&(1<<k)) > 0){
					int nmask = i | (1<<(k-1));
					int newp = j;
					for(int l = k+1; l < 16; l++){
						if((i&(1<<(l-1))) > 0) newp ^= 1;
					}
					dp[nmask][newp] += dp[i][j];
				}
			}
		}
	}
	
	int p = ((x/4)+1)%2;
	return dp[up][p];
	
}

int main(){
	for(int i = 0; i < 16; i++){
		int c; cin >> c;
		while(c--){
			int x; cin >> x;
			a[i] |= (1<<x);
		}
	}
	
	long long ans = 0;
	for(int i = 0; i < 16; i++){
		if(a[i]&1){
			ans += go(i);
		}
	}	
	
	printf("%lld\n", ans);
	return 0;
}
