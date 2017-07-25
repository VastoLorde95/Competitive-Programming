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

const long long N = 101;

long long n, a[N];
long long p, q, mn, ans;

int main(){
	cin >> n;
	for(long long i = 0; i < n; i++) cin >> a[i];
	cin >> p >> q;
	
	sort(a, a+n);
	long long ptr;
	mn = 1e9, ptr = -1, ans = p;
	for(long long i = 0; i < n; i++){
		if(a[i] >= p and ptr == -1) ptr = i;
		a[i] = abs(a[i] - p);
		mn = min(mn, a[i]);
	}	
	
	long long sub = p, prev = -1;
	if(ptr == 0) prev = 0; else prev = a[ptr-1];
	for(long long i = ptr; i < n; i++){
		a[i] -= (sub-p);	
		long long tmp = (prev+a[i])/2;
		if(tmp > mn){
			mn = tmp;
			sub += a[i]-tmp;
			if(sub <= q){
				ans = sub;
			}
		}
		sub += a[i];
		a[i] = 0;
		prev = 0;
	}	
		
	cout << ans << endl;
	
	return 0;
}
