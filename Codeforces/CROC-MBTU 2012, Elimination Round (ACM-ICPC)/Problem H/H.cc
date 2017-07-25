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

int l;
string s;
int dp[5001][5001], q, x, y;
vector<pair<int, int> > v;

int main(){ _
	cin >> s;
	l = s.length();
	
	for(int i = 0; i < l; i++){
		dp[i][i] = 1;
	}
	
	for(int i = 1; i < l; i++){
		if(s[i] == s[i-1]){
			dp[i-1][i] = 1;
		}
	}
	
	for(int i = 3; i <= l; i++){
		for(int j = 0; j < l; j++){
			if(dp[j+1][j+i-2] and s[j] == s[j+i-1]){
				dp[j][j+i-1] = 1;
			}
		}
	}
	
	
	for(int i = 0; i < l; i++){
		for(int j = 1; j < l; j++){
			dp[i][j] += dp[i][j-1];
		}
	}
	

	
	for(int i = 0; i < l; i++){
		for(int j = 1; j < l; j++){
			dp[j][i] += dp[j-1][i];
		}
	}

	
	cin >> q;
	while(q--){
		cin >> x >> y;
		--x, --y;
		
		int ans = dp[y][y]; 
		if(x > 0){
			ans -= dp[y][x-1];
			ans -= dp[x-1][y]; 
			ans += dp[x-1][x-1];
		}
		cout << ans << "\n";
	}
	
	return 0;
}
