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

int n;
ll s, f[20], fact[21], inv_fact[21], ans, MOD = 1e9 + 7;
map<ll, ll> coef;

ll inv(ll a){
	ll b = MOD-2, ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}	
	return ret;
}


ll C(ll n, ll k){
	k = min(k, n-k);
	ll num = 1, denom = inv_fact[k];
	for(ll i = n-k+1; i <= n; i++){
		num = (num * (i%MOD))%MOD;
	}
	
	return (num*denom)%MOD;
}

void pre(){
	inv_fact[0] = fact[0] = 1;
	for(int i = 1; i <= 20; i++){
		fact[i] = (fact[i-1]*i)%MOD;
		inv_fact[i] = inv(fact[i]);
	}
}

int main(){ _
	pre();

	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> f[i];
	}
	
	int up = 1<<n;
	
	for(int i = 0; i < up; i++){
		ll c = 1, power = 0;
		for(int j = 0; j < n; j++){
			if((i&(1<<j)) > 0){
				c *= -1;
				power += (f[j]+1);
			}
		}
		if(c < 0) c += MOD;
		coef[power] += c;
		if(coef[power] >= MOD) coef[power] -= MOD;
	}
	
	foreach(it, coef){
		ll p = it->fi, c = it->se;
		ll rem = s-p;
		if(rem >= 0){
//			tr5(rem+n-1, rem, C(n+rem-1,rem), p, c);
			ans += (c*C(rem+n-1,rem))%MOD;
			if(ans >= MOD) ans -= MOD;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
