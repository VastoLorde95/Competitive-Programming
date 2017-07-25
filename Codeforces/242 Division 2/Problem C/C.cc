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

int n, res, p;
int xors[1000001];

int main(){
	sd(n);
	
	for(int i = 1; i <= 1000000; i++){
		xors[i] = xors[i-1]^i;
	}
	
	for(int i = 0; i < n; i++){
		sd(p);
		res ^= p;
	}
	
	for(int i = 2; i <= n; i++){
		if(n/i > 1){
			if((n/i)%2 == 0)
				res ^= xors[n%i];
			else
				res ^= xors[n%i]^xors[i-1];
		}
		else{
			if(n/i == 1)
				res ^= xors[i-1]^xors[n%i];
			else
				res ^= xors[n%i];
		}
	}
	
	printf("%d\n", res);
	
	return 0;
}
