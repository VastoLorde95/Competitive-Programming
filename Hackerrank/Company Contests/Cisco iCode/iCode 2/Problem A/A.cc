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

int t, n, a[100100], l[100100], r[100100];
stack<int> s;

long long ans = 0;

int main(){
	sd(t);
	while(t--){
		sd(n);
		for(int i = 0; i < n; i++){
			sd(a[i]);
		}
		while(!s.empty()) s.pop();
		l[0] = -1;
		
		s.push(0);
		
		for(int i = 1; i < n; i++){
			while(!s.empty() and a[s.top()] < a[i]) s.pop();
			if(s.empty()) l[i] = -1;
			else l[i] = s.top();
			s.push(i);
		}
		
		while(!s.empty()) s.pop();
		r[n-1] = n;
		s.push(n-1);
		for(int i = n-2; i >= 0; i--){
			while(!s.empty() and a[s.top()] < a[i]) s.pop();
			if(s.empty()) r[i] = n;
			else r[i] = s.top();
			s.push(i);
		}
		
		ans = 0;
		for(int i = 0; i < n; i++){
			ans += (long long)(r[i] - i) * (long long)(i - l[i]);
		}
		
		cout << ans << "\n";
				
	}
	return 0;
}
