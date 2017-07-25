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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 100100;

int n, k, s[N];

map<int, int> b;
map<int, int>::iterator it;

bool ok(int m){
	b.clear();
	for(int i = 0; i < n; i++){
		b[s[i]]++;
	}
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		if(b.count(s[i])){
			if(s[i] > m) return false;
			b[s[i]]--;
			if(b[s[i]] == 0) b.erase(s[i]);
			
			if(s[i] == m){
				cnt++;
				continue;
			}
			
			it = b.upper_bound(m-s[i]);
			
			if(it == b.begin()){
				cnt++;
			}
			else{
				it--;
				int x = it->fi;
				b[x]--;
				if(b[x] == 0) b.erase(x);
				cnt++;
			}
		}
	}
	
	return cnt <= k;
}

int main(){
	sd2(n,k);
	for(int i = 0; i < n; i++){
		sd(s[i]);
	}
	
	sort(s, s+n, greater<int>());
	
	int lo = 0, hi = 2000*1000 + 1, mid;
	while(lo < hi){
		mid = (lo+hi)/2;
		if(ok(mid)) hi = mid;
		else lo = mid+1;
	}

	cout << hi << '\n';
	
	return 0;
}
