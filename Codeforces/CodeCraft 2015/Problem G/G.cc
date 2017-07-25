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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef long long ll;

int t, n, K;
ll dp[1<<15][15];

int main(){
	sd(t);
	while(t--){
		sd2(n,K);
		memset(dp, 0, sizeof dp);
		int up = 1<<n;
		for(int i = 0; i < n; i++) dp[1<<i][i] = 1;
		
		for(int i = 1; i < up; i++){
			for(int j = 0; j < n; j++){
				if((i&(1<<j)) == 0){
					int nxt = i | (1<<j);
					for(int k = 0; k < n; k++){
						if((i&(1<<k)) > 0 and abs(j-k) <= K){
							dp[nxt][j] += dp[i][k];
						}
					}
				}
			}
		}
		
		ll ans = 0;
		for(int i = 0; i < n; i++){
			ans += dp[up-1][i];
		}
		cout << ans << "\n";
	}
	return 0;
}
