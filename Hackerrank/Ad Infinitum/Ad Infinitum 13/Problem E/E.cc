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

const int N = 1001001;
int sieve[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i <= N; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] <= N; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}

int n, q, x;
long long ans, MOD = 1e9 + 7;
long long sum[N];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	getSieve();
	sd2(n,q);
	
	for(int i = 1; i < N; i++){
		sum[i] = 1;
	}
	
	ans = 1;
	if(n > 1){
		int tmp = n;
		while(tmp > 1){
			int prime = sieve[tmp];
			tmp /= prime;
			ans = (ans * fast(sum[prime], MOD-2))%MOD;
			sum[prime] = (1+(sum[prime]*prime)%MOD)%MOD;
			ans = (ans * sum[prime])%MOD;
		}
	}
	
	int tmp;
	while(q--){
		sd(tmp);
		while(tmp > 1){
			int prime = sieve[tmp];
			tmp /= prime;
			ans = (ans * fast(sum[prime], MOD-2))%MOD;
			sum[prime] = (1+(sum[prime]*prime)%MOD)%MOD;
			ans = (ans * sum[prime])%MOD;
		}
		printf("%lld\n", ans);
	}	
	
	
	return 0;
}
