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

int n, a, b, MOD = 1000000007, num;
set<int> good;
long long fact[1000001], res;

long long inv(long long a){
	long long ret = 1, b = MOD-2;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	sd3(a,b,n);
	
	for(int i = 1; i <= 7; i++){
		for(int mask = 0; mask < (1<<i); mask++){
			num = 0;
			for(int j = 0; j < i; j++){
				num *= 10;
				if((mask&(1<<j)) > 0){
					num += a;
				}
				else{
					num += b;
				}
			}
		
			good.insert(num);
		}
	}
	fact[0] = 1;
	for(int i = 1; i <= n; i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	
	for(int i = 0; i <= n; i++){
		num = i*a + (n-i)*b;
		
//		cout << num << endl;
		
		if(good.find(num) != good.end()){
//			cout << "yo " << i << endl;
			res = (res + ((fact[n]*inv(fact[i]))%MOD*inv(fact[n-i]))%MOD)%MOD;	
		}
	}
	
	cout << res << endl;
	
	return 0;
}
