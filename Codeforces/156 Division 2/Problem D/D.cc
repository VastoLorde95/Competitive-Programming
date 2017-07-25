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
ll n, x, y, c, tmp;

ll l, r, u, d;

ll sqr(ll m){
	return m*m;
}

ll sum(ll m){
	return (m*(m+1))/2;
}

int f(ll val){
	tmp = sqr(val) + sqr(val+1);
	if(val > l) tmp -= sqr(val-l);
	if(val > r) tmp -= sqr(val-r);
	if(val > u) tmp -= sqr(val-u);
	if(val > d) tmp -= sqr(val-d);
	if(val > l+d) tmp += sum(val-(l+d)-1);
	if(val > l+u) tmp += sum(val-(l+u)-1);
	if(val > r+d) tmp += sum(val-(r+d)-1);
	if(val > r+u) tmp += sum(val-(r+u)-1);
	return tmp >= c;
}

int main(){ _
	cin >> n >> x >> y >> c;
	
	l = x-1, r = n-x, u = y-1, d = n-y;
	
	if(c == 1){
		cout << 0 << "\n";
		return 0;
	}
	
	ll lo = 1, hi = 2*n, mid;
	
	while(lo+1 < hi){
		mid = (lo+hi)>>1;
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	
	cout << hi << "\n";	
	
	return 0;
}
