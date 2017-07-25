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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, a[101], dp[101][1<<16], prev[101][1<<16], res[101], inf = 1e9;
int masks[60];
vector<int> primes;

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++) sd(a[i]);
	
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j < (1<<16); j++){
			dp[i][j] = inf;
		}
	}
	
	for(int i = 0; i < (1<<16); i++){
		dp[0][i] = 0;
	}
	
	primes.pb(2);
	for(int i = 3; i < 59; i += 2){
		bool ok = true;
		foreach(it, primes){
			if(i%(*it) == 0) ok = false;
		}
		if(ok){
			primes.pb(i);
		}
	}
	
	for(int i = 2; i < 59; i++){
		for(int j = 0; j < primes.size(); j++){
			if(i%primes[j] == 0){
				masks[i] |= (1<<j);
			}
		}
	}
	
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < 59; j++){
			int mask = (~masks[j]) & ((1<<16)-1);
			for(int s = mask; ; s = ((s-1)&mask)){
				if(dp[i-1][s] == inf) continue;
				
				if(dp[i-1][s] + abs(a[i]-j) < dp[i][s | masks[j]]){
					dp[i][s | masks[j]] = dp[i-1][s] + abs(a[i] - j);
					prev[i][s | masks[j]] = j;
				}
				
				if(s == 0) break;
			}
		}
	}
	
	int s = -1, mn = inf;
	for(int i = 0; i < (1<<16); i++){
		if(dp[n][i] < mn){
			mn = dp[n][i];
			s = i;
		}
	}
	
	for(int i = n; i >= 1; i--){
		res[i] = prev[i][s];
		s ^= masks[prev[i][s]];
	}
	
	for(int i = 1; i <= n; i++) printf("%d ", res[i]); printf("\n");
	
	
	
	return 0;
}
