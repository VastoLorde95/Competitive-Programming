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

int n, k;
vector<pair<int,int> > v;

int main(){
	int ans = 0;
	sd2(n,k);
	for(int i = 0; i < n; i++){
		int a;
		sd(a);
		if(a == 100){
			ans += 10;
			continue;
		}
		v.pb(mp(a%10, a));
	}
	
	n = v.size();
	sort(v.begin(), v.end(), greater<pair<int,int> >());
	
	for(int i = 0; i < n and k > 0; i++){
		int diff = min(k, 10-v[i].fi);
		k -= diff;
		v[i].se += diff;
		v[i].fi = 0;
	}
	
	if(k > 0){
		for(int i = 0; i < n and k > 0; i++){
			if(v[i].se == 100) continue;
			int diff = min(k, 100-v[i].se);
			k -= diff;
			v[i].se += diff;
		}
	}
	
	
	for(int i = 0; i < n; i++){
		ans += v[i].se/10;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
