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

int n, m, s[5001], dp[5001], mx;
double x;

int main(){ _
	cin >> n >> m;
	
	int tmp = 0;
	
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> x;
	}	
	
	mx = dp[1] = 1;
	
	for(int i = 2; i <= n; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			if(s[j] <= s[i]){
				dp[i] = max(dp[i], dp[j] +1);
			}
		}
		mx = max(mx, dp[i]);
	}
	
	tr(n-mx);
	
	return 0;
}
