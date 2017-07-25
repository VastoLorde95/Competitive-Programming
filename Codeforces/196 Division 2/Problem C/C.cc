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

using namespace std;

int n, m, k, thres, tmp, MOD = 1000000009, rem;
long long ans;

long long power(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	sd3(n,m,k);
	
	thres = (n/k)*(k-1) + n%k;
	
	if(m <= thres){
		printf("%d\n",m);
		return 0;
	}
	
	rem = m - thres;
	
	ans = ((power(2, rem+1)-2 +MOD)%MOD * k)%MOD;
	
	cout << (ans + (m-rem*k))%MOD << endl;
	
	return 0;
}
