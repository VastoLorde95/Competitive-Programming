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
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, a[1000	];	
long long fact[30001], MOD = 1000000007, res = 1;
vector<int> primes;
map<int,int> c;

long long inv(long long x){
	long long y = MOD-2, ret = 1;
	while(y > 0){
		if(y%2 == 1) ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y >>= 1;
	}
	return ret;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 30000; i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int tmp = a[i];

		for(int j = 2; j*j <= tmp; j++){
			while(tmp%j == 0){
				c[j]++;
				tmp /= j;
			}
		}
		
		if(tmp > 1) c[tmp]++;
		
	}
	
	for(map<int, int>::iterator it = c.begin(); it != c.end(); it++){
		int cnt = it->second;
		res = (res * fact[cnt+n-1])%MOD;
		res = ((res * inv(fact[cnt]))%MOD * inv(fact[n-1]))%MOD;
	}
	
	cout << res << endl;
	
	return 0;
}
