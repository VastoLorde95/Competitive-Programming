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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long f[2001000], MOD = 1e9 + 7, ans = 0;
int n;

long long inv(long long a){
	long long ret = 1, b = MOD-2;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

long long nCr(int x, int y){
	long long ret = f[x];
	ret = (ret * inv(f[y]))%MOD;
	ret = (ret * inv(f[x-y]))%MOD;
	return ret;
}

int main(){
	f[0] = 1;
	for(int i = 1; i <= 2000010; i++){
		f[i] = (f[i-1]*i)%MOD;
	}
	
	sd(n);
	
	for(int i = 0; i <= n; i++){
		ans = (ans + nCr(n+i+1,i+1))%MOD;
	}
	
	cout << ans << "\n";
	
	return 0;
}
