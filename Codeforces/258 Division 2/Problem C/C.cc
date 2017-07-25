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

typedef long long ll;

int t;
ll n, k, d1, d2, need;

int main(){ _
	cin >> t;
	while(t--){
		cin >> n >> k >> d1 >> d2;
		
		if(n%3 != 0){
			puts("no"); continue;
		}
		
		need = n/3;
		
		ll tmp = k-d1-d1-d2;
		if(tmp%3 == 0 and tmp >= 0){
			tmp /= 3;
			ll x1 = tmp, x2 = tmp+d1, x3 = tmp+d1+d2;
			
			if(!(x1 < 0 or x2 < 0 or x3 < 0) and !(x1 > need or x2 > need or x3 > need))
				if(need*3 - x1-x2-x3 <= n-k){
					puts("yes");
					continue;
				}
		}
		
		tmp = k-d1-d1+d2;
		if(tmp%3 == 0 and tmp >= 0){
			tmp /= 3;
			ll x1 = tmp, x2 = tmp+d1, x3 = tmp+d1-d2;
			
			if(!(x1 < 0 or x2 < 0 or x3 < 0) and !(x1 > need or x2 > need or x3 > need))
				if(need*3 - x1-x2-x3 <= n-k){
					puts("yes");
					continue;
				}
		}
		tmp = k+d1+d1-d2;
		if(tmp%3 == 0 and tmp >= 0){
			tmp /= 3;
			ll x1 = tmp, x2 = tmp-d1, x3 = tmp-d1+d2;
			
			if(!(x1 < 0 or x2 < 0 or x3 < 0) and !(x1 > need or x2 > need or x3 > need))
				if(need*3 - x1-x2-x3 <= n-k){
					puts("yes");
					continue;
				}
		}
		tmp = k+d1+d1+d2;
		if(tmp%3 == 0 and tmp >= 0){
			tmp /= 3;
			ll x1 = tmp, x2 = tmp-d1, x3 = tmp-d1-d2;
			
			if(!(x1 < 0 or x2 < 0 or x3 < 0) and !(x1 > need or x2 > need or x3 > need))
				if(need*3 - x1-x2-x3 <= n-k){
					puts("yes");
					continue;
				}
		}
		
		puts("no");
	}
	return 0;
}
