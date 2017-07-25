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

long long a, b;
long long sum, mod = 1e9 + 7;

long long mod_inv(long long a){
	long long b = mod-2, ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	cin >> a >> b;
	
	long long num = b+1, cur = 1, temp = 0;
	
	while(cur <= a){
		temp += num;
		temp %= mod;
		num += b;
		cur++;
	}
	
	for(int i = 1; i < b; i++){
		sum = (sum + (temp*i)%mod)%mod;
	}
	
	cout << sum << endl;
	return 0;
}
