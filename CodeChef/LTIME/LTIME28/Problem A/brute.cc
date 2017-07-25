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

long long a[20], res = 0;
int n, m, k, d;

void go(int indx, int left, int prev, long long tot){
	if(indx == n){
		if(left == 0)
			res = max(res, tot);
		return;
	}
	if(left == 0){
		if((indx-prev) <= d and prev != -1)
			tot += a[indx]*m;
		else
			tot += a[indx];
		go(indx+1, left, prev, tot);
		return;
	}
	
	if(indx-prev <= d and prev != -1){
		go(indx+1, left, prev, tot + a[indx]*m);
	}
	else
		go(indx+1, left, prev, tot+a[indx]);
	go(indx+1, left-1, indx, tot);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sd2(n,k); sd2(d,m);
		res = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		go(0,k,-1,0);
		cout << res << endl;
	}
	return 0;
}
