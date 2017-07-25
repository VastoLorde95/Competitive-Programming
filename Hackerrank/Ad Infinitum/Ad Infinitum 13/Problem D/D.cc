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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

ll get(ll d, ll k){
	ll ans = (fast(d, k+1)-1+MOD)%MOD;
	ans = (ans * fast(d-1, MOD-2))%MOD;
	return ans;
}

int main(){ _
	ll t, d, k, h;
	cin >> t;
	while(t--){
		cin >> d >> k >> h;
		if(h >= k){
			cout <<  get(d,k) << '\n';
		}
		else{
			ll tmp = (get(d,k) - get(d, k-h-1) + MOD)%MOD;
			if(k-h-2 > 0){
				if((k-h)%2 == 0){
					ll t = get((d*d)%MOD, -1+((k-h)/2));
					tmp = (tmp + t)%MOD;
				}
				else{
					ll t = get((d*d)%MOD, -1+((k-h)/2));
//					tr3(tmp,t,k-h);
					t = (t*d)%MOD;
//					tr2(tmp,t);
					tmp = (tmp+t)%MOD;
				}
			}
			cout << tmp << '\n';
		}	
	}
	return 0;
}
