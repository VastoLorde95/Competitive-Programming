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

int n, q, a[200100], cnt[500500], lp[500500], in[200100], val[64], bitcount[64], lsb[64], x;
long long ans;

void update(int x, int sign){
	int pcnt = 0, tmp = x;
	vector<int> primes;
	while(tmp > 1){
		int p = lp[tmp]; pcnt++;
		primes.pb(p);
		while(tmp%p == 0) tmp /= p;
	}
	
	for(int mask = 0; mask < (1<<pcnt); mask++){
		if(mask > 0)
			val[mask] = primes[lsb[mask]] * val[mask ^ (1<<lsb[mask])];
		else
			val[mask] = 1;
			
		if(sign < 0) cnt[val[mask]]--;
		
		if(bitcount[mask]%2 == 0) ans += sign*cnt[val[mask]]; else ans -= sign*cnt[val[mask]];
		
		if(sign > 0) cnt[val[mask]]++;
	}
	
}

int main(){
	sd2(n,q);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	memset(lp, -1, sizeof lp);
	for(int i = 2; i <= 500000; i++){
		if(lp[i] == -1)
			for(int j = i; j <= 500000; j += i) lp[j] = i;
	}
	
	for(int i = 0; i < 64; i++){
		for(int j = 0; j < 6; j++){
			if((i&(1<<j)) > 0) bitcount[i]++, lsb[i] = j;
		}
	}
	
	while(q--){
		sd(x);
		in[x] ^= 1;
		if(in[x]) update(a[x-1],1); else update(a[x-1],-1);
		printf("%I64d\n", ans);
	}
	
	return 0;
}
