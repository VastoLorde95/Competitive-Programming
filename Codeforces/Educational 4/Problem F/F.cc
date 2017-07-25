#include <bits/stdc++.h>

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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 2100;
int n, s;
int a[N];
int dp[N][N], prev[N][N];

set<int> compr;
int cnt;
map<int,int> f;

int go(int x, int y){
	if(y < 0) return 0;
	if(dp[x][y] > 0) return dp[x][y];
	int &ret = dp[x][y];
	
	int d = 0, cur = x, dis = 0, last;
	for(int i = 1; i < n; i++){
		cur++; if(cur >= n) cur -= n;
		dis++;
		if(a[cur] == y){
			d += dis;
			dis = 0;
			last = cur;
		}
	}
	
	ret = go(last, y-1) + d;
	prev[x][y] = d;
	
	d = 0, cur = x, dis = 0;
	for(int i = 1; i < n; i++){
		cur--; if(cur < 0) cur += n;
		dis++;
		if(a[cur] == y){
			d += dis;
			dis = 0;
			last = cur;
		}
	}
	
	int val = go(last, y-1) + d;
	if(val < ret){
		ret = val;
		prev[x][y] = -d;
	}
	return ret;
}

int main(){
	sd2(n,s);
	s--;
	for(int i = 0; i < n; i++){
		sd(a[i]);
		compr.insert(a[i]);
	}
	
	foreach(it, compr){
		f[*it] = cnt++;
	}
	
	for(int i = 0; i < n; i++) a[i] = f[a[i]];
	
	go(s, cnt-1);
	
	printf("%d\n", dp[s][cnt-1]);
	
	return 0;
}
