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

long long n, k, x, a[200100], l[200100], r[200100];

int main(){ _
	cin >> n >> k >> x;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	l[1] = a[1];
	r[n] = a[n];
	for(int i = 2; i <= n; i++){
		l[i] = l[i-1] | a[i];
	}
	
	for(int i = n-1; i >= 1; i--){
		r[i] = r[i+1] | a[i];
	}
	
	long long num = 1;
		
	for(int i = 1; i <= k; i++){
		num *= x;
	}
	
	if(n == 1){
		cout << a[1] * num << "\n"; return 0;
	}
	
	
	long long ans = max((a[1]*num | r[2]), (a[n]*num | l[n-1]));
	
	for(int i = 2; i < n; i++){
		ans = max(ans, ((num*a[i]) | l[i-1]) | r[i+1]);
	}
	
	cout << ans << "\n";
		
	return 0;
}
