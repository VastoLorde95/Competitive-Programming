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

int n, m, MOD = 1e9 + 7, x, y;
long long dp[200200], sum[200200];

map<int, vector<int> > c;
vector<int> v;

int main(){
	sd2(n,m);
	
	bool ok = false;
	bool okk = false;
	
	for(int i = 0; i < m; i++){
		sd2(x,y);
		
		v.pb(x); v.pb(y);
		
		if(x == 0) ok = true;	
		if(y == n) okk = true;	
			
		c[y].pb(x);
	}	
	
	if(!ok or !okk){
		puts("0"); return 0;
	}
	
	sort(v.begin(), v.end());
	
	v.resize(unique(v.begin(), v.end()) - v.begin());
	sum[0] = 1;
	
	int l = v.size();
	
	for(int i = 1; i < v.size(); i++){
		int cur = v[i];
		long long temp = 0;
		foreach(it, c[cur]){
			int ind = lower_bound(v.begin(), v.end(), *it) - v.begin();
			temp = (temp + sum[i-1] - sum[ind-1] + MOD)%MOD;
		}
		dp[i] = temp;
		sum[i] = (sum[i-1]+dp[i])%MOD;
	}
	
	cout << dp[l-1] << "\n";
		
	return 0;
}
