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

int n, a[200100], one[200100], zero[200100];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
//	one[1] = a[i];
//	for(int i = 2; i <= n; i++){
//		one[i] = one[i-1] + a[i];
//	}
	
	long long ans = 0;
	
	zero[n] = (1-a[n]);
	for(int i = n-1; i >= 1; i--){
		zero[i] = zero[i+1] + (1-a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			ans += zero[i];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
