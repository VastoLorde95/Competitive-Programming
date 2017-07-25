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

int n, k;
ll MOD = 1e9 + 7, ans = 1;
ll a[N], b[N];

ll p[10];

int main(){ _
	cin >> n >> k;
	ll l = n/k;
	
	p[0] = 1;
	for(int i = 1; i <= 9; i++) p[i] = p[i-1]*10;
	
	for(int i = 0; i < l; i++){
		cin >> a[i];
	}
	for(int i = 0; i < l; i++){
		cin >> b[i];
	}
	
	for(int i = 0; i < l; i++){
		ll t1 = (p[k]-1)/a[i] + 1;
		ll rem = (b[i]*p[k-1])%a[i];
		rem = (a[i] - rem)%a[i];
		ll t2 = 0;
		if(rem == 0){
			t2 = (p[k-1]-1)/a[i] + 1;
		}	
		else if(rem < p[k-1]){
			t2 = (p[k-1]-1-rem)/a[i] + 1;
			if(((p[k-1]-1-rem)/a[i])*a[i] + rem < p[k-1]){
				t2++;
			}
		}
	
//		tr3(i,t1,t2);
	
		ans = (ans * (t1-t2))%MOD;
	}
	
	cout << ans << endl;
			
	return 0;
}
