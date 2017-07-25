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

long long MOD = 1000000007;
long long ff[100100], inv_ff[100100];
int q, n, f, prime[100100], sqr[100100], mu[100100], ans;
vector<int> divi[100100];

long long inv_mod(long long x){
	long long ret = 1LL, y = MOD-2;
	while(y){
		if(y & 1) ret = (ret*x)%MOD;
		x = (x*x)%MOD, y >>= 1;
	}
	return ret;
}

long long C(int x, int y){
	if(y > x) return 0;
	return (ff[x] * ((inv_ff[y]*inv_ff[x-y])%MOD))%MOD;
}

void precompute(){
	inv_ff[0] = 1LL; ff[0] = 1LL;
	for(int i = 1; i <= 100099; i++){
		ff[i] = (ff[i-1]*i)%MOD;
		inv_ff[i] = inv_mod(ff[i]);
		prime[i] = 1;
	}
	
	// mobius function mu prepocessing
	for(int i = 1; i <= 100099; i++){
		for(int j = i; j <= 100099; j += i){
			divi[j].pb(i);	
		}
	}

	prime[0] = 0, prime[1] = 0;
	
	for(int i = 2; i <= 100099; i++){
		if(prime[i] == 1){
			for(int j = i+i; j <= 100099; j += i)
				prime[j] = 0;
		}
	}
	
	for(int i = 2; i*i <= 100099; i++){
		for(int j = (i*i); j <= 100099; j += (i*i))
			sqr[j] = 1;
	}
	
	for(int i = 1; i <= 100099; i++){
		if(sqr[i]) continue;
		int cnt = 0;
		foreach(d, divi[i]) if(prime[*d]) cnt++;
		mu[i] =  (cnt%2 == 1) ? -1: 1;
	}
	return;
}

int main(){
	precompute();
	
	sd(q);
	while(q--){
		sd2(n,f);
		
		if(n == 1 and f == 1){
			printf("1\n"); continue;
		}
		if(n > 1 and f == 1){
			printf("0\n"); continue;
		}
		
		ans = 0;
		
		foreach(d, divi[n]){
			ans = ans + mu[*d]*C((n/(*d))-1,f-1);
			if(ans < 0) ans += MOD;
			else if(ans >= MOD) ans -= MOD;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
