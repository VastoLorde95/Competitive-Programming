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

int n, a, b, x, sz, mx, cnt;
vector<int> v;
set<int> comp;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(x);
		comp.insert(x);
	}
	
	sd2(a,b);
	foreach(it, comp) v.pb(*it);
	
	sz = v.size();

	while(a > b){
		mx = 1, cnt++;
		for(int i = 0; i < sz; i++) if(a - (a%v[i]) >= b) mx = max(mx, a%v[i]);
		a -= mx;
		while(sz and (a - (a%v[sz-1])) < b) sz--;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
