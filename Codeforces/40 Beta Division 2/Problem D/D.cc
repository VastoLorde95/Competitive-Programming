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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

int n, m, k;
int g[101][101];
int dp[101][101][12];
pair<int,int> prev[101][101][12];

string s;

int update(int &x, int y){
	if(x < y){
		x = y; return 1;
	}
	return 0;
}

int main(){
	sd3(n,m,k);
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			g[i][j] = s[j-1] - '0';
		}
	}
	
	k++;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int l = 0; l < k; l++){
				dp[i][j][l] = -1;
			}
		}
	}
	
	
	
	for(int i = 1; i <= m; i++){
		int rem = g[n][i]%k;
		dp[n][i][rem] = g[n][i];
//		prev[n][i][rem] = -1;
	}
	
	
	for(int i = n-1; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			for(int l = 0; l < k; l++){
				if(j-1 > 0 and dp[i+1][j-1][l] != -1){
					int rem = (dp[i+1][j-1][l] + g[i][j])%k;
					if(update(dp[i][j][rem], dp[i+1][j-1][l] + g[i][j])){
						prev[i][j][rem] = mp(j-1,l);
					}
				}
				if(j+1 <= m and dp[i+1][j+1][l] != -1){
					int rem = (dp[i+1][j+1][l] + g[i][j])%k;
					if(update(dp[i][j][rem], dp[i+1][j+1][l] + g[i][j])){
						prev[i][j][rem] = mp(j+1,l);
					}
				}
			}
		}
	}
	
	int ans = -1, indx = -1, val = 0;
	
	for(int i = 1; i <= m; i++){
		if(update(ans, dp[1][i][0])){
			indx = i;
		}
	}
		
	if(ans == -1){
		cout << ans << "\n"; return 0;
	}
	
	string res;
	
	for(int i = 2; i <= n; i++){
		pair<int,int> p = prev[i-1][indx][val];
		if(p.fi > indx) res = 'L' + res; else res = 'R' + res;
		indx = p.fi, val = p.se;
	}
	
	cout << ans << "\n";
	cout << indx << "\n";
	cout << res << "\n";
	return 0;
}
