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

string s, p;
int dp[2001][2001];
int j[2001], k[2001];

int main(){ _
	cin >> s >> p;
	
	int n = s.length(), m = p.length();
	
	for(int i = 0; i < n; i++){
		if(s[i] == p[m-1]){
			bool ok = false;
			for(int a = m-1, b = i; a >= 0 and b >= 0 and !ok; b--){
				if(s[b] == p[a]) a--; else k[i+1]++;
				
				if(a < 0){
					j[i+1] = b; ok = true;
				}
			}
			if(!ok) k[i+1] = j[i+1] = -1;
		}
		else{
			k[i+1] = j[i+1] = -1;
		}
	}
	
//	for(int i = 1; i <= n; i++){
//		tr3(i, j[i], k[i]);
//	}
	
	
	for(int i = 1; i <= n; i++){
		if(j[i] != -1 and k[i] == 0){
//			tr3(i,j[i], k[i]);
			dp[0][i] = dp[0][j[i]]+1;
		}
		dp[0][i] = max(dp[0][i], dp[0][i-1]);
//		tr4("hey",0, i, dp[0][i]);
	}
	
	for(int i = 1; i <= n; i++){
		dp[i][0] = -10000;
		for(int l = 1; l <= n; l++){
			if(l < i) dp[i][l] = -10000;
			else if(l > i and j[l] != -1 and k[l] <= i){
				dp[i][l] = max(dp[i-k[l]][j[l]] + 1, max(dp[i-1][l-1], dp[i][l-1]));
			}
			else{
				dp[i][l] = max(dp[i-1][l-1], dp[i][l-1]);
			}
//			tr4("hey",i, l, dp[i][l]);
		}	
	}
	
	for(int i = 0; i <= n; i++){
		int mx = 0;
		for(int l = 1; l <= n; l++){
			mx = max(mx, dp[i][l]);
		}
		cout << mx << " ";
	}
	cout << endl;
	
	return 0;
}
