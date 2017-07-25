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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, x, y;
vector<pii> p;

long long dp[201][201], MOD = 1e9 + 7;

bool good(pll p1, pll p2, pll p3){	
	return (p3.se-p1.se)*(p2.fi-p1.fi) - (p2.se-p1.se)*(p3.fi-p1.fi) < 0;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(x,y);
		p.pb(mp(x,y));
	}
	
	ll area = 0;
	for(int i = n-1, j = 0; j < n; i = j++){
		area += (ll) p[i].fi*p[j].se - (ll) p[i].se*p[j].fi;
	}
	
	if(area < 0) reverse(p.begin(), p.end());
	
	for(int i = 1; i < n; i++){
		for(int j = i; j < n; j++){
			if(i == 1){
				dp[j-i][j] = 1;
			}
			else{
				for(int k = j-i+1; k < j; k++){
					if(!good(p[j-i], p[j], p[k])) continue;
					dp[j-i][j] += (dp[j-i][k]*dp[k][j])%MOD;
					if(dp[j-i][j] >= MOD) dp[j-i][j] -= MOD;
				}
			}
		}
	}
	
	printf("%d\n", (int) dp[0][n-1]);
	
	return 0;
}
