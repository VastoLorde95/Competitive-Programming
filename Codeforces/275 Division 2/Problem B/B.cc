#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long cnt1, cnt2, x, y;

bool check(long long val){
	long long c = val + (val/(x*y)) - (val/x) - (val/y);
	
	if(val - (val/(x*y)) < cnt1+cnt2) return false;
	if(c + (val/y) - (val/(x*y)) < cnt1) return false;
	
	c -= max(cnt1 - (val/y) + (val/(x*y)), 0LL);
	
	if(c + (val/x) - (val/(x*y)) < cnt2) return false;
	return true;
}

int main(){
	cin >> cnt1 >> cnt2 >> x >> y;
	
	long long lo = cnt1+cnt2-1, hi = 1e18, mid;
	
	while(lo+1 < hi){
		mid = (lo+hi)/2;
		if(check(mid)) hi = mid;
		else lo = mid;
	}	
	
	cout << hi << endl;
	return 0;
}
