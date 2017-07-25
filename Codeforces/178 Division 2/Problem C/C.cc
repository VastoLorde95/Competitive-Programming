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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, l[1000], len, prev;
long long res = 1, MOD = 1000000007, fact[1001], pow2[1001];

long long expp(long long x, long long b){
	long long ret = 1;
	while(b > 0){
		if(b%2 == 1) ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		b /= 2;
	}
	return ret;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 1000; i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}	
		
	pow2[0] = 1;
	for(int i = 1; i <= 1000; i++){
		pow2[i] = (pow2[i-1]*2)%MOD;
	}
	
	sd2(n,m);
	
	//if(n == m){
	//	puts("1");
	//	return 0;
	//}	
	
	for(int i = 0; i < m; i++){
		sd(l[i]);
	}
	
	sort(l, l+m);
	
	(res *= fact[n-m]) %= MOD;
	
	prev = 0;
	for(int i = 0; i < m; i++){
		res *= expp(fact[l[i]-prev-1], MOD-2);
		res %= MOD;	
		prev = l[i];
	}
	
//	tr(res);
	
	res *= expp(fact[n-l[m-1]], MOD-2);
	res %= MOD;
	
//	tr(res);
	
	for(int i = 1; i < m; i++){
		len = l[i]-l[i-1]-1;
		if(len >= 1)
			(res *= pow2[len-1]) %= MOD;
	}	
	
	
	
	tr(res);
	
	return 0;
}
