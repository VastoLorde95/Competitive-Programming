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

int n, m;
string s[20];
int bad[20][20], tot[20][20], a[20][20], dp[1<<20], inf = 1e9;

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sd(a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int mx = 0;
			for(int k = 0; k < n; k++){
				if(s[i][j] == s[k][j]){
					bad[i][j] |= (1<<k);
					tot[i][j] += a[k][j];
					mx = max(mx, a[k][j]);
				}
			}
			tot[i][j] -= mx;
		}
	}
	
	for(int i = 0; i < (1<<n); i++) dp[i] = inf;
	
	dp[0] = 0;
	
	for(int mask = 1; mask < (1<<n); mask++){
		int bit = 0;
		for(int j = n-1; j >= 0; j--){
			if((mask&(1<<j)) > 0) bit = j;
		}
		for(int i = 0; i < m; i++){
			dp[mask] = min(dp[mask], dp[mask&(mask^bad[bit][i])] + tot[bit][i]);
			dp[mask] = min(dp[mask], dp[mask^(1<<bit)] + a[bit][i]);
		}
	}
	
	printf("%d\n", dp[(1<<n)-1]);
	
	return 0;
}
