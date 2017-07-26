#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<unordered_map>
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

using namespace std;

long long t, n, dp[10000001], flip;
unordered_map<long long, long long> memo;

long long flipit(long long x){
	long long res = 0, rem, max = 1LL<<60;
		
	//cout << x << endl;
	
	if(x%10 == 0){
		return max;
	}
	
	while(x > 0){
		rem = x%10;
		res *= 10;
		res += rem;
		x /= 10;
	}
	
	//cout << res << endl;
	
	return res;
}
	
int recur(long long x){
	if(memo[x] != 0){
		//cout << "returning " << x << " " << memo[x] << endl;
		return memo[x];
	}
	
	long long flip = flipit(x);
		
	if(flip < x)
		memo[x] = min(recur(x-1)+1, recur(flip)+1);
	else
		memo[x] = recur(x-1)+1;
	
	//cout << x << " " << flip << " " << memo[x] << endl;
	
	return memo[x];
	
}

int main(){
	cin >> t;
	
	for(long long i = 1; i <= 2000000; i++){
		dp[i] = 100000000LL;
	}

	dp[1] = 1;
	
	//cout << "this?"<< endl;
		
	for(long long i = 2; i <= 2000000; i++){
		dp[i] = min(dp[i], min(i, dp[i-1]+1));
		
		flip = flipit(i);
		
		if(flip > i and flip <= 2000000){
			dp[flip] = min(dp[flip], dp[i]+1);
		}
	}
	
	//cout << "this?"<< endl;
	
	for(long long i = 1; i <= 2000000; i++){
		memo[i] = dp[i];
	}
	
	for(int i = 1; i <= 100000; i++){
		cout << i <<", "<< dp[i] << endl;
	}
	
	//cout << "this?"<< endl;
	
	for(long long T = 1; T <= t; T++){
		cin >> n;
		cout << "Case #"<< T << ": "<< recur(n) << endl;
	}
	return 0;
}
