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

typedef long long ll;

const int N = 100100;
const int M = 101;

struct line{
	ll m, c;
	ll f(ll x){return m*x + c;}
};

struct convexHull{
	line st[N];
	double pos[N];
	int top, ptr;
	
	double x_intersection(const line &l1, const line &l2){ // Careful! if slopes are equal, then this is not defined!
		assert(l1.m != l2.m);
		return ((double)(l2.c-l1.c))/(l1.m-l2.m);
	}
	
	void reset(){
		top = ptr = 0;
		return;
	}
	
	void insert(ll m, ll c){
		line l = {m, c};
		double x;
		
		while(top > 1){
			x = x_intersection(st[top-2], l);
			if(x > pos[top-1]) break;
			--top;
		}
		
		st[top++] = l;
		if(top > 1) // if there is more than one line in the hull
			pos[top-1] = x_intersection(st[top-1], st[top-2]);
		return;
	}
	
	ll getMin(ll x){
		while(ptr < top-1 and pos[ptr+1] <= x) ptr++; // find the line whose range straddles point x
		return st[ptr].f(x);
	}
};

int n, m, p;
ll ans, d[N], h[N], t[N], s[N], dp[M][N], inf = 1ll<<60;
convexHull c;

int main(){ _
	cin >> n >> m >> p;
	for(int i = 2; i <= n; i++){
		cin >> d[i];
		d[i] += d[i-1];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> h[i] >> t[i];
		t[i] = t[i] - d[h[i]];
	}
	
	sort(t+1, t+m+1);	
	for(int i = 1; i <= m; i++){
		s[i] = s[i-1] + t[i];
	}
	
	for(int i = 1; i <= m; i++) dp[0][i] = inf;
	
	for(int i = 1; i <= p; i++){
		c.reset();					// insert each line one by one from the previous level in the new convexHull
		for(int j = 1; j <= m; j++){
			c.insert(-(j-1), dp[i-1][j-1] + s[j-1]);
			dp[i][j] = 1ll*j*t[j] - s[j] + c.getMin(t[j]);	// Retrieve the line which gives the minimum using the convex hull uptil this point
		}
	}
	
	ans = inf;
	for(int i = 0; i <= p; i++) ans = min(ans, dp[i][m]);
	cout << ans << '\n';
		
	return 0;
}
