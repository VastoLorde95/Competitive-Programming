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

ll fact[2500001], MOD = 1000000007;
int t, n, k;

long long fastexp(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b%2 == 1) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

long long inv(long long a){
	return fastexp(a, MOD-2);
}

long long nCr(long long a, long long b){
	long long res = 1;
	res = fact[a];
	res = (res * inv(fact[b]))%MOD;
	res = (res * inv(fact[a-b]))%MOD;
	return res;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 2500000; i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	sd(t);
	while(t--){
		sd2(n,k);
		ll tmp = (2*nCr(k+n+1, k+2)) % MOD;
		tmp = (tmp - n + MOD)%MOD;
		printf("%lld\n", tmp);
	}	
	return 0;
}
