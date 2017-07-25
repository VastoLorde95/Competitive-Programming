#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

long long dp[1<<16], INF = 1LL<<60;
int t, n, d;

long long value(const vector<int>& x){	//construct the number in base 'd'
	long long res = 0;
	for(int i = 0; i < n; i++)
		res = (long long)res*d + x[i];
	return res;
}

long long bad(const vector<int>& x){	//the number of bad people in that cell
	long long exor = 0, sum = 0;
	for(int i = 0; i < n; i++)
		exor ^= x[i], sum += x[i];
	return exor*sum;
}

long long permute(vector<int>& x){		//top down recursion to compute the optimum answer
	long long val = value(x);
	if(dp[val] != -1) return dp[val];
	if(val == 0){
		dp[val] = 0;
		return 0;
	}
	dp[val] = INF;
	vector<int> prev = x;
	long long cost = bad(x), mini = INF;
	for(int i = 0; i < n; i++){
		if(x[i] > 0){
			prev[i] -= 1;
			mini = min(mini, permute(prev));
			prev[i] += 1;
		}
	}
	return dp[val] = mini + cost;
}

void solve(){
	memset(dp, -1, sizeof dp);
	vector<int> state;
	sd2(n,d);
	for(int i = 0; i < n; i++) state.push_back(d-1);
	printf("%lld\n", permute(state));
}

int main(){
	sd(t);
	while(t--){
		solve();
	}
	return 0;
}
