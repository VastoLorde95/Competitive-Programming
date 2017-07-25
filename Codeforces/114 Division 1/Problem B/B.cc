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

int n, l, K, a[201];
double dp[202][202], p[201];

int main(){
	sd3(n,l,K);
	
	K = min(n,K);
	
	for(int i = 0; i < n; i++){
		scanf("%lf",&p[i]);
		p[i] /= 100;
	}
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
		a[i]++;
	}
	
	dp[0][K] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = n-1; j >= 0; j--){
			for(int k = 0; k <= n; k++){
				dp[j+1][min(k+a[i],n)] += dp[j][k] * p[i];
				dp[j][k] *= (1.0 - p[i]);
			}
		}
	}	
	
	double ans = 0;
	
	for(int i = l; i <= n; i++){
		for(int k = i; k <= n; k++){
			ans += dp[i][k];
		}
	}
	
	printf("%.9lf\n", ans);
	
	return 0;
}
