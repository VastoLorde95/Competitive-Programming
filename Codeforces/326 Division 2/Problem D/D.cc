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

typedef long long ll;

const int N = 1001000;

ll n, l, k;
ll a[N], cont[N], MOD = 1e9 + 7, ans;
set<ll> comp;
map<ll,ll> f;

ll q, r;

int main(){ _
	cin >> n >> l >> k;
	
	q = l/n, r = l%n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		comp.insert(a[i]);
	}
	
	ll cnt = 0;
	foreach(it, comp){
		f[*it] = cnt++;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = f[a[i]];
		cont[a[i]]++;
	}
	
	ll dp[cnt][k+1];
	
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = (j == 0);
		}
	}
	
	for(int i = 1; i <= k; i++){
		dp[0][i] = (dp[0][i-1]*cont[0])%MOD;
		if(n*i <= l){
			ans = (ans + (dp[0][i]*((q-i+1)%MOD))%MOD)%MOD;
		}
	}
	
	for(int i = 1; i < cnt; i++){
		for(int j = 1; j <= k; j++){
			ll t1 = (dp[i][j-1]*cont[i])%MOD;
			dp[i][j] = (dp[i-1][j] + t1)%MOD;
			if(j*n <= l){
				ll t2 = (t1*((q-j+1)%MOD))%MOD;
				ans = (ans + t2)%MOD;
			}
		}		
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 1; j <= k; j++){
			if((j-1)*n <= l){
				ans = (ans + dp[a[i]][j-1])%MOD;
			}
		}
	}
	
	cout << ans << '\n';
		
	return 0;
}
