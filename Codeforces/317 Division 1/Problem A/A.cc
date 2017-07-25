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

long long ans;
int a, b, c, l;

int main(){
	
	cin >> a >> b >> c >> l;
	
	ans = (long long) (l+3)*(l+2)*(l+1)/6;
	
	for(int i = 0; i <= l; i++){
		long long x = min(a-b-c+i, l-i);
		if(x >= 0) ans -= ((x+1)*(x+2))/2;
	}
	
	for(int i = 0; i <= l; i++){
		long long x = min(b-a-c+i, l-i);
		if(x >= 0) ans -= ((x+1)*(x+2))/2;
	}
	
	for(int i = 0; i <= l; i++){
		long long x = min(c-b-a+i, l-i);
		if(x >= 0) ans -= ((x+1)*(x+2))/2;
	}
	
	tr(ans);
	
	return 0;
}
