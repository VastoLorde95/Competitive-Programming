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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int t, k, a, b;
long long MOD = 1000000007, dp[100001], sum[100001];

int main(){ _
	cin >> t >> k;
	dp[0] = 1;
	for(int i = 1; i < k; i++){
		dp[i] = 1;
	}
	
	for(int i = k; i <= 100000; i++){
		dp[i] = (dp[i-1] + dp[i-k])%MOD;
	}
	
	for(int i = 1; i <= 100000; i++){
		sum[i] = (sum[i-1] + dp[i])%MOD;
	}
	
	while(t--){
		cin >> a >> b;
		cout << (sum[b] - sum[a-1] + MOD)%MOD << endl;
	}
	return 0;
}
