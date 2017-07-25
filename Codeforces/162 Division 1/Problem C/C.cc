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

int n, q;
ll v[N], c[N];
ll dp[N], a, b, inf = (1LL<<63);
ll mx1, mx2;
int c1, c2;

int main(){ _
	cin >> n >> q;
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	
	while(q--){
		for(int i = 1; i <= n; i++) dp[i] = -inf;
		cin >> a >> b;
		
		mx1 = b*v[0];
		c1 = c[0];
		
		dp[c1] = mx1;
		
		mx2 = -inf;
		c2 = -1;
		
		
		ll t1, t2;
		for(int i = 1; i < n; i++){
			if(dp[c[i]] == -inf){
				dp[c[i]] = max(mx1,0ll) + b*v[i];
				
				if(dp[c[i]] > mx1){
					mx2 = mx1;
					c2 = c1;
					
					mx1 = dp[c[i]];
					c1 = c[i];
				}
				else if(dp[c[i]] > mx2){
					mx2 = dp[c[i]];
					c2 = c[i];
				}
			}
			else{
				t1 = dp[c[i]] + a*v[i];
				if(c1 != c[i]){
					t2 = max(mx1, 0ll) + b*v[i];
				}
				else{
					t2 = max(mx2, 0ll) + b*v[i];
				}
				
				t1 = max(t1, t2);
				dp[c[i]] = max(dp[c[i]], t1);
				
				if(c1 == c[i]){
					if(t1 > mx1) mx1 = t1;
				}
				else if(c2 == c[i]){
					if(t1 > mx2) mx2 = t1;
					if(mx2 > mx1){
						swap(mx2, mx1);
						swap(c2, c1);
					}
				}
				else{
					if(t1 > mx1){
						mx2 = mx1;
						c2 = c1;
						
						mx1 = t1;
						c1 = c[i];
					}
					else if(t1 > mx2){
						mx2 = t1;
						c2 = c[i];
					}
				}
			}
		} 
		cout << max(mx1, 0ll) << '\n';
	}
	
	return 0;
}
