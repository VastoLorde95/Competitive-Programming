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

long double a, b;

int main(){ _
	cin >> a >> b;
	
	int k1 = (a+b)/(2*b), k2 = (a-b)/(2*b);
	
	ld x1 = -1, x2 = -1;
	
	if(k1 > 0){
		x1 = (a+b)/(ld)(k1*2);
	}
	if(k2 > 0){
		x2 = (a-b)/(ld)(k2*2);
	}
	
	cout.precision(16);
	
	if(x1 <= 0 and x2 <= 0) cout << -1 << "\n";
	else if(x1 <= 0){
		cout << fixed << x2 << "\n";
	}
	else if(x2 <= 0){
		cout << fixed << x1 << "\n";
	}
	else{
		cout << fixed << min(x1,x2) << "\n";
	}
	return 0;
}
