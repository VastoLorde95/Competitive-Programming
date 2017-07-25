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

int n, m, MOD = 1e9 + 7;
int  vv[100100];
long long dp[(1<<20)+1], p[(1<<20)+1], ans = 0;
char st[22];

int main(){
	sd2(n,m);
	
	p[0] = 1;
	for(int i = 1; i <= (1<<m); i++){
		p[i] = (p[i-1]*2)%MOD;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%s", st);
		for(int j = 0; j < m; j++){
			vv[i] <<= 1;
			vv[i] |= (st[j]-'0');
		}
		dp[vv[i]]++;
	}
	
	int r = 0;
	scanf("%s", st);
	for(int i = 0; i < m; i++){
		r <<= 1;
		r |= (st[i]-'0');
	}	
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < (1<<m); j++){
			if((j&(1<<i)) > 0){
				dp[j] += dp[j ^ (1<<i)];
			}
		}
	}
	
	for(int i = r; ; i = (i-1)&r){
		if(__builtin_popcount(i^r)%2 == 0){
			ans += (p[dp[i]]-1);
			if(ans >= MOD) ans -= MOD;
		}
		else{
			ans -= (p[dp[i]]-1);
			ans += MOD;
			if(ans >= MOD) ans -= MOD;
		}
		if(i == 0) break;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
