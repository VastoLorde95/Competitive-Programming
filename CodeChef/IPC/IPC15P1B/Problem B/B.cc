#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)

#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)

using namespace std;

const int MOD = 1e9 + 7;

unordered_map<int, int> dp1, dp2, dp3;

void add(int &x, int y){
	x += y; if(x >= MOD) x -= MOD;
}

void solve(){
	register int n, x;
	sd(n);
	dp1.clear(), dp2.clear(), dp3.clear();
	
	while(n--){
		sd(x);
		add(dp2[x], dp1[x+1]);
		add(dp3[x], dp1[x-1]);
		
		add(dp1[x], 1);
		add(dp1[x], dp2[x-1]);
		add(dp1[x], dp3[x+1]);
	}
	
	int tot = 0;
	for(const pair<int,int> &it : dp1) add(tot, it.second);
	
	printf("%d\n", tot);
}

int main(){
	int t; sd(t);
	while(t--) solve();
	return 0;
}
