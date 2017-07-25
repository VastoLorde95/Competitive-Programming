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

typedef long double ld;

const int N = 2002;

int n, h, inf = 1e9;
int x[N], l[N], r[N];
ld dp[N][N][2][2], p;

ld go(int i, int j, int s, int t){
	if(i > j) return 0;
	ld &ans = dp[i][j][s][t];
	if(ans > 0) return ans;
	
	int lft = (s == 0)? x[i-1] : x[i-1]+h;
	int rgt = (t == 1)? x[j+1] : x[j+1]-h;
	
	ans = p*(go(i+1,j,0,t) + min(h, x[i]-lft));
	if(r[i] < j) ans += (1.0f-p)*(go(r[i]+1,j,1,t) + x[r[i]]+h-x[i]);
	else ans += (1.0f-p)*(min(x[j]+h,rgt) - x[i]);
	
	
	ans += (1.0f-p)*(go(i,j-1,s,1) + min(h, rgt-x[j]));
	if(l[j] > i) ans += p*(go(i,l[j]-1, s, 0) + x[j]-(x[l[j]]-h));
	else ans += p*(x[j] - max(lft,x[i]-h));
	
	ans /= 2;
	
	return ans;
}

int main(){
	cin >> n >> h >> p;
	for(int i = 1; i <= n; i++){
		sd(x[i]);		
	}
	
	sort(x+1, x+n+1);
	x[0] = -inf, x[n+1] = inf;
	
	for(int i = 1; i <= n; i++){
		l[i] = (x[i]-x[i-1] < h)? l[i-1]: i;
	}
	
	for(int i = n; i >= 1; i--){
		r[i] = (x[i+1]-x[i] < h)? r[i+1]: i;
	}
	
	// 0 -> fall to the left
	// 1 -> fall to the right
	printf("%.9lf\n", (double) go(1,n,0,1));
	
	return 0;
}
