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

ll dp[1<<19][19];

int n, m, k;
ll a[19], sp[20][20], ans;

int main(){ _
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= k; i++){
		int x, y; ll c;
		cin >> x >> y >> c;
		x--, y--;
		sp[x][y] = c;
	}
	
	int up = 1<<n;
	
	for(int i = 1; i < up; i++){
		if(__builtin_popcount(i) > m) continue;
		if(__builtin_popcount(i) == 1){
			for(int j = 0; j < n; j++){
				if((i&(1<<j)) > 0){
					dp[i][j] = a[j];
					if(__builtin_popcount(i) == m) ans = max(ans, dp[i][j]);
					break;
				}
			}
			continue;
		}
		
		for(int j = 0; j < n; j++){
			if((i&(1<<j)) > 0){
				for(int k = 0; k < n; k++){
					if(k != j and ((i&(1<<k)) > 0)){
						dp[i][j] = max(dp[i][j], dp[i^(1<<j)][k] + a[j] + sp[k][j]);
					}	
				}
				if(__builtin_popcount(i) == m){
					ans = max(ans, dp[i][j]);
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
