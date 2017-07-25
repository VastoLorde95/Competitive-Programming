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

long long f[100001], MOD = 1000000007;
long long n, k, t;

long long inv(long long x){
	long long ret = 1, y = MOD-2;
	while(y){
		if(y%2) ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y >>= 1;
	}
	return ret;
}

int main(){
	f[0] = 1;
	for(int i = 1; i <= 100000; i++){
		f[i] = (f[i-1]*i)%MOD;
	}
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k > n) cout << 0 << endl;
		else{
			long long ans = f[n];
			ans *= inv(f[k]);
			ans %= MOD;
			ans *= inv(f[n-k]);
			ans %= MOD;
			cout << ans << endl;
		}
	}
	return 0;
}
