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
 
int t, m;
long double p;
 
long double fast(long double x, int y){
	long double ret = 1;
	while(y){
		if(y%2) ret = (ret*x);
		x = (x*x);
		y >>= 1;
	}
	return ret;
}
 
int main(){ _
	cin >> t;
	while(t--){
		cin >> m >> p;
		long double x = 1.0f-fast(-p,m);
		x /= (p+1);
		
		double v1 = 1000000000*x;
		cout.precision(10);
//    		if(m%2)
		cout << fixed << v1 << " " <<  1000000000.0f - v1 << "\n";
//    		else
//    			printf("%.5lf %.5lf\n", 1000000000.0f - v1, v1);
		
	}
	return 0;
}
