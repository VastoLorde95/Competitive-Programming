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

int n, k, a, m, x, cnt, inf = 1e9;
set<pair<int, int> > seg;
set<pair<int, int> >::iterator it;

int main(){
	sd3(n,k,a);
	sd(m);
	
	seg.insert(mp(1,n));
	cnt = (n+1) / (a+1);
	
	int i;
	for(i = 1; i <= m and cnt >= k; i++){
		sd(x);
		it = seg.upper_bound(mp(x,inf));
		it--;
		int l = it->fi, r = it->se;
		seg.erase(it);
		cnt -= (r-l+2) / (a+1);
		
		int newr = x-1, newl = x+1;
		
		seg.insert(mp(l,newr));
		cnt += (newr-l+2) / (a+1);
		
		seg.insert(mp(newl,r));
		cnt += (r-newl+2) / (a+1);
		
//		tr(cnt);
//		foreach(it, seg){
//			tr3(i, it->fi,it->se);
//		}
//		tr("****");
		
	}
	
	if(cnt >= k){
		puts("-1");
	}
	else{
		printf("%d\n", i-1);
	}
	
	return 0;
}
