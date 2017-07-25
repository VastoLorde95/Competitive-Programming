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

int t, n;
ll k;

long long C[61][61];

int main(){ _
	cin >> t;
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= 60; i++){
		for(int j = 0; j <= i; j++){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	while(t--){
		cin >> n >> k;
		if(k == 1){
			cout << 0 << "\n";
			continue;
		}
		
		ll cur = 0, d = -1;
		while(cur < k and d < n){
			k -= cur;
			d += 1;
			cur = C[n][d];
		}
		
		ll num = 0; cur = 0;
		for(int i = 0; i < n; i++){
			if(n-i-1 == 0){
				num |= 1;
				break;
			}
			if(d > n-i-1){
				num |= (1LL<<(n-i-1));
			}
			else if(cur + C[n-i-1][d] < k){
				cur += C[n-i-1][d];
				num |= (1LL<<(n-i-1));
				d -= 1;
			}
			if(d == 0) break;
		}
		cout << num << "\n";
	}
	return 0;
}
