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
 
typedef long double ld;
 
int t;
ld r1, r2, r3, r4;
long long n0, p, m, b, tmp, n;
ld ans = 0;

int main(){
	cin >> t;
	cin >> n0 >> p >> m >> b;
	cin >> r1 >> r2 >> r3 >> r4;
 
	tmp = n0;
	
	ld r, k1 = (ld)-1.0f/r1, k2 = (ld) 1.0f/r2, k3 = (ld) 1.0f/r3, k4 = (ld) 1.0f/r4, tmp;
	ld k = (k1+k2);
	
	for(int i = 1; i <= t; i++){
		n0 = (n0*p)%m  + b;
		n = n0 - 4;
		ans += 1/((((ld)(k*(ld)n)*(ld)(n+1)) - (ld)(k3*(ld)n) + (ld)(k4*(ld)(n+1))));
	}
	
	
	printf("%.6lf\n", (double) ans);
	
	return 0;
} 
