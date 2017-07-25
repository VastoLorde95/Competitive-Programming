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

int n;
long double a[200100];

long double f(long double x){
	ld cur = -x+a[0], mx = abs(cur); if(cur < 0) cur = 0;
	for(int i = 1; i < n; i++){
		cur += (ld)(-x + a[i]);
		if(cur < 0) cur = 0;
		mx = max(mx, cur);
	}
	
	cur = -x+a[0]; if(cur > 0) cur = 0;
	for(int i = 1; i < n; i++){
		cur += (ld)(-x+a[i]);
		if(cur > 0) cur = 0;
		mx = max(mx, abs(cur));
	}
	return mx;
}

int main(){ _
	cin >> n; 
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
//		lo = min(lo, a[i]);
//		hi = max(hi, a[i]);
	}
	
	long double m1, m2, eps = 1e-11, lo = -10000, hi = 10000, v1, v2;
	
	for(int i = 0; i < 200; i++){
		m1 = lo + (hi-lo)/3.0;
		m2 = hi - (hi-lo)/3.0;
		
		v1 = f(m1);
		v2 = f(m2);
		
		
//		tr6(lo,hi,m1,m2,v1,v2);
		if(v1 < v2) hi = m2;
		else if(v1 > v2) lo = m1;
		else lo = m1, hi = m2;
	}
	
	cout.precision(15);
	
	cout << fixed << min(v1,v2) << "\n";
	
	
//	for(int i = 0; i < n; i++){
//		a[i] -= 5.375;
//	}
//	
//	ld mx = 0;
//	for(int i = 0; i < n; i++){
//		for(int j = i+1; j < n; j++){
//			ld sum = 0;
//			for(int k = i; k <= j; k++){
//				sum += a[k];
//			}
//			mx = max(mx, abs(sum));
//		}
//	}
//	
//	tr(mx);
//	
	return 0;
}
