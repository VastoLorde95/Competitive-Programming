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

const int N = 100100;

ll n, k, a[N], b[N];

ll f(ll val){
	ll cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i]*b[i] > val){
			cnt += (a[i] - (val/b[i]));
		}
	}
	return cnt;
}

int main(){ _
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	
	ll low = 0, hi = 1ll<<60, mid;
	while(low < hi){
		mid = low + ((hi-low)/2);
		if(f(mid) <= k) hi = mid;
		else low = mid+1;
	}
	
	ll val = hi;
	for(int i = 0; i < n; i++){
		if(a[i] * b[i] > val){
			k -= (a[i] - (val/b[i]));
			a[i] = val/b[i];
		}
	}
	
	if(k > 0){
		set<pair<ll,int> > s;
		for(int i = 0; i < n; i++){
			s.insert(mp(-(a[i]*b[i]), i));
		}
		
		for(int i = 0; i < k; i++){
			pair<ll, int> p = *s.begin();
			s.erase(p);
			if(p.fi != 0){
				p.fi += b[p.se];
			}
			s.insert(p);
		}
		
		foreach(it, s){
			a[it->se] = (-it->fi)/b[it->se];
		}
		
	}
	
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
	
		
	
	return 0;
}
