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

const int N = 1001;

int n, l;
int x[N], b[N], prev[N];
double d[N][N], mn[N];

bool f(double m){
	for(int i = 1; i <= n; i++) mn[i] = d[0][i] - m*b[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			mn[j] = min(mn[j], mn[i] + d[i][j] - m*b[j]);
		}
	}
	
	return mn[n] <= 0;
	
}

int main(){
	sd2(n,l);
	for(int i = 1; i <= n; i++){
		sd2(x[i], b[i]);
		for(int j = 0; j < i; j++) d[j][i] = sqrt(abs(l-(x[i]-x[j])));
	}
	
	double lo = 0, hi = 1000, mid, eps = 1e-9;
	for(int i = 0; i < 35; i++){
		mid = (lo+hi)/2;
		if(f(mid)) hi = mid; else lo = mid+eps;
	}
	
	hi = (lo+hi)/2;
	
	for(int i = 1; i <= n; i++){
		mn[i] = d[0][i] - hi*b[i];
		prev[i] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(mn[i] + d[i][j] - hi*b[j] < mn[j]){
				mn[j] = mn[i] + d[i][j] - hi*b[j];
				prev[j] = i;
			}
		}
	}
		
	vector<int> res(1,n);
	while(prev[res.back()] != 0) res.pb(prev[res.back()]);
		
	reverse(res.begin(), res.end());
	
	foreach(it, res) printf("%d ", *it); puts("");
		
	return 0;
}
