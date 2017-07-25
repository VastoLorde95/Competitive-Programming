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

using namespace std;

int n, m, x, y, grid[1000][1000], s1[1000], s2[1000], dp[1000][2], INF = 1000000000;
string s;

int main(){
	sd2(n,m); sd2(x,y);
	
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '#') grid[i][j] = 1;
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(grid[j][i]) s1[i]++; else s2[i]++;
		}
	}
	
	for(int i = 1; i < m; i++){
		s1[i] += s1[i-1];
		s2[i] += s2[i-1];
	}
	
	for(int i = 0; i < m; i++){
		dp[i][0] = dp[i][1] = INF;
	}
	
	for(int i = 0; i < x; i++) dp[i][0] = dp[i][1] = INF;
	
	for(int i = x-1; i < y; i++){
		dp[i][0] = s1[i];	// 0 means that it ends with a white strip, so convert all black to white
		dp[i][1] = s2[i];		// 1 means that it ends with a black strip, so convert all white to black
	}
	
	for(int i = x; i < m; i++){
		for(int j = x-1; j < y; j++){
			if(i+j < m){
				dp[i+j][0] = min(dp[i+j][0], dp[i-1][1] + s1[i+j] - s1[i-1]);
				dp[i+j][1] = min(dp[i+j][1], dp[i-1][0] + s2[i+j] - s2[i-1]);
			}
		}
	}
	
	cout << min(dp[m-1][0], dp[m-1][1]) << endl;
	return 0;
}
