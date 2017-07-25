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

int n, m;

int dp1[1111][1111];
int dp2[1111][1111];
int dp3[1111][1111];
int dp4[1111][1111];

int dp5[1111][1111];
int dp6[1111][1111];
int dp7[1111][1111];
int dp8[1111][1111];

int dp9[1111][1111];
int dp10[1111][1111];
int dp11[1111][1111];
int dp12[1111][1111];

char s[1111][1111];
int g[1111][1111];

bool inrange(int x, int y){
	if(!g[x][y]) return true;
	return false;
}

bool atedge(int x, int y){
	int cnt = 0;
	if(inrange(x-1,y)){
		cnt++;
	}
	if(inrange(x-1,y+1)){
		cnt++;
	}
	if(inrange(x-1,y-1)){
		cnt++;
	}
	if(inrange(x+1,y)){
		cnt++;
	}
	if(inrange(x+1,y+1)){
		cnt++;
	}
	if(inrange(x+1,y-1)){
		cnt++;
	}
	if(inrange(x,y-1)){
		cnt++;
	}
	if(inrange(x,y+1)){
		cnt++;
	}
	return (cnt >= 5);
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i]);
		for(int j = 0; j < m; j++){
			g[i][j+1] = (s[i][j] == '#');
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
 				dp1[i][j] = min(dp1[i][j-1], dp1[i-1][j-1])+1;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(g[i][j]){
 				dp2[i][j] = min(dp2[i][j+1], dp2[i-1][j+1])+1;
			}
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
 				dp3[i][j] = min(dp3[i][j-1], dp3[i+1][j-1])+1;
			}
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(g[i][j]){
 				dp4[i][j] = min(dp4[i][j+1], dp4[i+1][j+1])+1;
			}
		}
	}
	
	/***********/
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
 				dp5[i][j] = min(dp5[i-1][j], dp5[i-1][j-1])+1;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(g[i][j]){
 				dp6[i][j] = min(dp6[i-1][j], dp6[i-1][j+1])+1;
			}
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
 				dp7[i][j] = min(dp7[i+1][j], dp7[i+1][j-1])+1;
			}
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(g[i][j]){
 				dp8[i][j] = min(dp8[i+1][j], dp8[i+1][j+1])+1;
			}
		}
	}
	
	/***********/
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
 				dp9[i][j] = min(dp9[i][j-1], dp9[i-1][j])+1;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(g[i][j]){
 				dp10[i][j] = min(dp10[i][j+1], dp10[i-1][j])+1;
			}
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			if(g[i][j]){
 				dp11[i][j] = min(dp11[i][j-1], dp11[i+1][j])+1;
			}
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(g[i][j]){
 				dp12[i][j] = min(dp12[i][j+1], dp12[i+1][j])+1;
			}
		}
	}
	
	int ans = 1e9;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] and atedge(i,j)){
				int t1 = max(max(dp1[i][j], dp2[i][j]),max(dp3[i][j],dp4[i][j]));
				int t2 = max(max(dp5[i][j], dp6[i][j]),max(dp7[i][j],dp8[i][j]));
				int t3 = max(max(dp9[i][j], dp10[i][j]),max(dp11[i][j],dp12[i][j]));
				ans = min(ans, max(max(t1,t2),t3));
//				tr3(i,j,ans);
//				tr6(i,j,dp1[i][j], dp2[i][j],dp3[i][j],dp4[i][j]);
//				tr6(i,j,dp5[i][j], dp6[i][j],dp7[i][j],dp8[i][j]);
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
