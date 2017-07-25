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

const int N = 50;

long long t[3][3], dp[N][3][3];
int n;

void relax(int x){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			for(int k = 0; k < 3; k++){
				if(k == i or k == j) continue;
				dp[x][j][k] = min(dp[x][j][k], dp[x][j][i] + dp[x][i][k]);
			}
		}
	}
	return;
}

int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> t[i][j];
			dp[1][i][j] = t[i][j];
		}
	}
	cin >> n;

	relax(1);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(j == k) continue;
				for(int l = 0; l < 3; l++){
					if(l == j or l == k) continue;
					dp[i][j][k] = min(dp[i-1][j][l] + t[j][k] + dp[i-1][l][k], 
									dp[i-1][j][k] + t[j][l] + dp[i-1][k][j] + t[l][k] + dp[i-1][j][k]);
				}
			}
		}
		relax(i);
	}	
		
	cout << dp[n][0][2] << '\n';
	
	return 0;
}
