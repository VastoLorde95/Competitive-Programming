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

long long N, k, l, m;

void fib(long long n, long long&x, long long&y){
    if(n==1){
        x = y = 1;
        return ;
    }
    if(n&1){
        fib(n-1, y, x);
        y=(y+x)%m;
    }else{
        long long a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b)%m;
        x = (a*b + a*(b-a+m))%m;
    }
}


long long exp(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%m;
		a = (a*a)%m;
		b >>= 1;
	}
	return ret;
}
int main(){
	cin >> N >> k >> l >> m;
	
	long long x, y;
	fib(N+1,x,y);
	
	if(l == 0){
		if(k == 0)
			cout << 1%m << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	
	long long fibb = y, p = exp(2ll,N);
	
	unsigned long long fuckthis = 1ULL<<l;
	if(l == 64) fuckthis = 0-1;
	
	if(k >= fuckthis){
		cout << 0 << endl; return 0;
	}
	
	long long ans = 1;
	
	for(int i = 0; i < l; i++){
		if((k&(1LL<<i)) > 0)
			ans = (ans * ((p-fibb+m)%m))%m;
		else
			ans = (ans*fibb)%m;
	}
	
	cout << ans%m << endl;
	
	return 0;
}
