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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, a[1002][1002];
long long m1[1002][1002], m2[1002][1002], m3[1002][1002], m4[1002][1002], mx, cur;

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(a[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			m1[i][j] = max(m1[i-1][j], m1[i][j-1]) + a[i][j];
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			m2[i][j] = max(m2[i+1][j], m2[i][j-1]) + a[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			m3[i][j] = max(m3[i-1][j], m3[i][j+1]) + a[i][j];
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			m4[i][j] = max(m4[i][j+1], m4[i+1][j]) + a[i][j];
		}
	}
	
	for(int i = 2; i < n; i++){
		for(int j = 2; j < m; j++){
			cur = max(m1[i-1][j]+m2[i][j-1]+m3[i][j+1]+m4[i+1][j], m1[i][j-1]+m2[i+1][j] + m3[i-1][j]+m4[i][j+1]);
			mx = max(mx,cur);
		}
	}
	
	tr(mx);
	
	return 0;
}
