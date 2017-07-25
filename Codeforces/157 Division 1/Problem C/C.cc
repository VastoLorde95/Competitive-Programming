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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;

const int N = 100100;

int n, a[N], l[N];
ll ans = 0, MOD = 1e9 + 7;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){	_ 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	for(int i = N-1, j = n-1; i > 0; i--){
		while(j >= 0 and a[j] >= i) j--;
		l[i] = j+1;
	}
	
	vector<int> v1, v2;
	for(int i = a[n-1]; i > 1; i--){
		v1.clear();
		
		for(int j = 1; j*j <= i; j++){
			if(i%j == 0){
				v1.pb(j);
				if(j*j != i) v2.pb(i/j);
			}
		}
		
		reverse(v2.begin(), v2.end());
		v1.insert(v1.end(), v2.begin(), v2.end());
		v2.clear();
		
		ll tmp = 1;
		for(int j = 1; j < v1.size(); j++){
			tmp = (tmp * fast(j, l[v1[j]]-l[v1[j-1]]))%MOD;
		}
		
		int len = n-l[v1.back()];
		tmp = (tmp * (fast(v1.size(), len) - fast(v1.size()-1, len) + MOD)%MOD)%MOD;
		ans += tmp;
		
		if(ans >= MOD) ans -= MOD;
	}
	
	ans++;
	if(ans >= MOD) ans -= MOD;
	
	cout << ans << '\n';
	
	return 0;
}
