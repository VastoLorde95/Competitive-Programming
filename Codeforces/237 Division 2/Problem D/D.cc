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

long long dp[1<<20][5], ans, MOD = 1e9 + 7;
int  n, t, i;
string s;

int main(){ _
	cin >> s;
	n = s.length();

	if(s[0] == '?'){
		dp[i][0] = dp[i][4] = 1;
		if(n > 1) dp[i][2] = 1;
	}
	else if(s[0] == '0') dp[0][0] = 1;
	else if(s[0] == '1' and n > 1) dp[i][2] = 1;
	else if(s[0] == '*') dp[i][4] = 1;
	
	for(i = 1; i < n; i++){
		if(s[i] != '?'){
			if(s[i] == '0') (dp[i][0] += dp[i-1][0] + dp[i-1][1]) %= MOD;
			else if(s[i] == '1'){
				(dp[i][1] += dp[i-1][4]) %= MOD;
				if(i < n-1) (dp[i][2] += dp[i-1][0] + dp[i-1][1]) %= MOD;
			}
			else if(s[i] == '2' and i < n-1){
				 (dp[i][3] += dp[i-1][4]) %= MOD;
			}
			else if(s[i] == '*') (dp[i][4] += dp[i-1][2] + dp[i-1][3] + dp[i-1][4]) %= MOD;
		}
		else{
			(dp[i][0] += dp[i-1][0] + dp[i-1][1])%= MOD;
			(dp[i][1] += dp[i-1][4]) %= MOD;
			if(i < n-1){
				(dp[i][2] += dp[i-1][0] + dp[i-1][1]) %= MOD;
				(dp[i][3] += dp[i-1][4]) %= MOD;
			}
			(dp[i][4] += dp[i-1][2] + dp[i-1][3] + dp[i-1][4]) %= MOD;
		}
	}
	
	for(i = 0; i < 5; i++) ans += dp[n-1][i];
	cout << ans%MOD << "\n";
	
	return 0;
}
