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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;

const int N = 100100;

int n, k, a[N];
map<int,int> m;
ll f[N], MOD = 1e9+7, dp[N];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll C(int a, int b){
	if(a < b) return 0;
	return (f[a] * ((fast(f[b], MOD-2) * fast(f[a-b], MOD-2))%MOD))%MOD;
}

int main(){
	sd2(n,k);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		sd(a[i]);
		int j = a[i], ok = 1;
		while(j){
			int d = j%10;
			j /= 10;
			if(d != 4 and d != 7) ok = 0;
		}
		if(ok) m[a[i]]++;
		else cnt++;
	}
	
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (f[i-1]*i)%MOD;
	
	for(int i = 0; i <= k; i++){
		dp[i] = C(cnt,i);
	}
	
	foreach(it, m){
		for(int i = k; i >= 1; i--){
			dp[i] += (dp[i-1]*it->se)%MOD;
			if(dp[i] >= MOD) dp[i] -= MOD;
		}
	}

	printf("%d\n", (int) dp[k]);	
		
	return 0;
}
