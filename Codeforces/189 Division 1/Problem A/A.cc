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

using namespace std;

string x;
int n;
long long dp[101], MOD = 1000000007, p[101];

int main(){ _
	
	p[0] = 1;
	for(int i = 1; i <= 100; i++){
		p[i] = (p[i-1]*2)%MOD;
	}
			
	cin >> x;
	n = x.length();
	
	if(n == 1){
		if(x == "0"){
			tr(0);
		}
		else{
			tr(1);
		}
		return 0;
	}	
	
	if(x[n-1] == '0') dp[n-1] = 0;
	else dp[n-1] = 1;
	
	for(int i = n-2; i >= 0; i--){
		if(x[i] == '0'){
			dp[i] = (2*dp[i+1])%MOD;
		}
		else{
			dp[i] = ((p[n-i-1]*p[n-i-1])%MOD + 2*dp[i+1])%MOD;
		}
	}
	
	cout << dp[0] << endl;
	
	return 0;
}
