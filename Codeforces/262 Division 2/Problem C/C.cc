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

int n, m, w;
int a[100100], start[100100];

bool check(int val){
	int cur = 0, tot = 0;
	for(int i = 0; i < n; i++){
		start[i] = 0;
	}
	for(int i = 0; i < n; i++){
		cur -= (i >= w)? start[i-w] : 0;
		if(a[i] + cur < val){
			start[i] = val-(a[i]+cur);
			cur += val-(a[i]+cur);
		}
	}
	
//	tr2("Tracing", val);
//	for(int i = 0; i < n; i++) cout << start[i] << " "; cout << endl;
	
	for(int i = 0; i < n; i++){
		tot += start[i];
		if(tot > m) return false;
	}
	
	return true;
}

int main(){
	sd3(n,m,w);
	
	int mn = 1e9, mx = 0;
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
		mn = min(mn, a[i]); mx = max(mx, a[i]);
	}
	int lo = mn, hi = mx+m+1, mid;
	while(lo+1 < hi){
		mid = (lo+hi)/2;
//		tr2(lo,hi);
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	printf("%d\n", lo);
	return 0;
}
