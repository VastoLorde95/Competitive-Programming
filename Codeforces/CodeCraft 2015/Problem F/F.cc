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

int t, h, w, n, x, y;
long long f[205100], invf[205100], MOD = 1e9 + 7, ans, ways[3010];
vector<pair<int, int> > b;

long long inv(long long a){
	long long ret = 1, p = MOD-2;
	while(p){
		if(p%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		p >>= 1;
	}
	return ret;
}

long long help(int x1, int y1, int x2, int y2){
	int a = x2-x1;
	int b = y2-y1;
	
	return (f[a+b]*((invf[a]*invf[b])%MOD))%MOD;
}

int main(){
	invf[0] = f[0] = 1;
	for(int i = 1; i <= 200010; i++) f[i] = (f[i-1] * i)%MOD;
	for(int i = 1; i <= 200010; i++) invf[i] = inv(f[i]);
	sd(t);
	while(t--){
		memset(ways, 0, sizeof ways);
		sd3(h,w,n);
		b.clear();
		for(int i = 0; i < n; i++){
			sd2(x,y);
			b.pb(mp(x,y));
		}
		b.pb(mp(h,w));
	
		sort(b.begin(), b.end());
	
		int sz = (int) b.size();
	
		for(int i = 0; i < sz; i++){
			ways[i] = (f[b[i].fi+b[i].se-2] * invf[b[i].fi-1])%MOD;
			ways[i] = (ways[i] * invf[b[i].se-1])%MOD;
		}
	
		for(int i = 0; i < sz-1; i++){
			for(int j = i+1; j < sz; j++){
				if(b[j].fi < b[i].fi or b[j].se < b[i].se) continue;
			
				ways[j] -= (ways[i] * help(b[i].fi, b[i].se, b[j].fi, b[j].se))%MOD;
				ways[j] = (ways[j] + MOD)%MOD;
			
			}			
		}	
	
		printf("%d\n", (int) ways[sz-1]);	
	}
	return 0;
}
