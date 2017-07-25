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

ll gcd(ll n, ll m)
{
	ll gcd, remainder;
 
	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}
 
	gcd = m;
 
	return gcd;
}//end gcd function

int t;

int memo[1<<26];

char s[1001000];

int p[30];

int main(){
	sd(t);
	
	ll gd;
	
	int i, j;
	
	p[0] = 1;
	for(i = 1; i < 30; i++){
		p[i] = p[i-1]*2;
	}
	
	while(t--){
		scanf("%s", s);
		int l = strlen(s);
		ll q = (1ll*l*(l+1))/2;
		
		int mask = 0;
		ll tot = 0;
		
		memo[0] = 1;
		
		for(i = 1; i <= l; i++){
			mask ^= p[(s[i-1]-'a')];
			tot += memo[mask];
			for(j = 0; j < 26; j++){
				tot += memo[mask^p[j]];
			}
			memo[mask]++;
		}
		
		mask = 0;
		
		for(i = 1; i <= l; i++){
			mask ^= p[(s[i-1]-'a')];
			memo[mask]--;
		}
		
		
		
		gd = gcd(tot,q);
		tot /= gd;
		q /= gd;	
				
		printf("%lld/%lld\n", tot, q);
		
	}
	return 0;
}
