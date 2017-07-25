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

int n, h[300100], l[300100];
vector<int> pos[1001000];
stack<int> s;

long long ans = 0;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(h[i]);
		pos[h[i]].pb(i);
	}
	
	l[0] = -1;
	s.push(0);
	
	for(int i = 1; i < n; i++){
		while(!s.empty() and h[s.top()] <= h[i]) s.pop();
		if(s.empty()) l[i] = -1;
		else l[i] = s.top();
		s.push(i);
	}
	
	for(int i = 0; i < n; i++){
		int l1 = upper_bound(pos[h[i]].begin(), pos[h[i]].end(), l[i]) - pos[h[i]].begin();
		int l2 = lower_bound(pos[h[i]].begin(), pos[h[i]].end(), i) - pos[h[i]].begin();
		ans += (l2-l1);
	}
	
	printf("%lld\n", ans*2);
	
	
	
	return 0;
}
