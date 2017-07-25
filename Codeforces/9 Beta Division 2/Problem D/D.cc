#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, h;

long long dp[36][36];

int main(){ _
	cin >> n >> h;
	
	dp[0][0] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int h0 = 1; h0 <= i; h0++){
			for(int root = 1; root <= i; root++){
				for(int h1 = 0; h1 <= h0-1; h1++){
					dp[i][h0] += dp[root-1][h0-1] * dp[i-root][h1];
				}
				for(int h1 = 0; h1 <= h0-2; h1++){
					dp[i][h0] += dp[i-root][h0-1] * dp[root-1][h1];
				}
			}
		}
	}
	
	long long ans = 0;
	
	for(int i = h; i <= n; i++){
		ans += dp[n][i];
	}
	
	cout << ans << "\n";
	
	return 0;
}
