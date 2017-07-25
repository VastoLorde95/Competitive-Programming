#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

long long fact[10000001], p, res, ans;

int main(){
	int n, m;
	fact[0] = 1;
	sd2(n,m);
	for(int i = 1; i < m; i++){
		fact[i] = (fact[i-1] * i)%m;
	}
	fact[m] = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld",&p);
		if(p >= m-1){
			if(p % 2 == 0){
				res = (p/2)%m;
				p %= m;
				res = ((res * p)%m * (p+1))%m;
				res = (res - 1 + m)%m;
			}
			else{
				res = ((p+1)/2)%m;
				p %= m;
				res = ((res * p)%m * p)%m;
				res = (res - 1 + m)%m;
			}
		}
		else{
			if(p % 2 == 0){
				res = (p/2)%m;
				p %= m;
				res = ((res * p)%m * (p+1))%m;
				res = (res - 1 + m)%m;
				res = (res + fact[p+1])%m;
			}
			else{
				res = ((p+1)/2)%m;
				p %= m;
				res = ((res * p)%m * p)%m;
				res = (res - 1 + m)%m;
				res = (res + fact[p+1])%m;
			}
		}
		ans = (ans+res)%m;
	}
	
	cout<<ans<<endl;
	return 0;
}
