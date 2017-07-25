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

int n, a, x;
vector<pair<int, int> > l, r;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(x,a);
		if(x < 0){
			l.pb(mp(x, a));
		}
		else if(x > 0){
			r.pb(mp(x, a));
		}
	}
	
	sort(l.begin(), l.end(), greater<pair<int, int> >());
	sort(r.begin(), r.end());
	
	int cnt1 = 0, cnt2 = 0;
	int x = 0, y = 0, indx = 0;
	while(true){
		indx ^= 1;
		if(indx){
			if(x == l.size()) break;
			cnt1 += l[x++].se;
		}
		else{
			if(y == r.size()) break;
			cnt1 += r[y++].se;
		}
	}
	
	
	x = 0, y = 0, indx = 1;
	while(true){
		indx ^= 1;
		if(indx){
			if(x == l.size()) break;
			cnt2 += l[x++].se;
		}
		else{
			if(y == r.size()) break;
			cnt2 += r[y++].se;
		}
	}
	
	tr(max(cnt1,cnt2));
	
	return 0;
}
