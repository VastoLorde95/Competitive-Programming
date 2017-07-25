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

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 100100;
const int M = 2010;

int n, m, k, t;
int s[N], a[M][M];
int mxx1[10], mxx2[10], mnn1[10], mnn2[10];

int main(){
	sd3(n,m,k); sd(t);
	for(int i = 1; i < 10; i++){
		mnn1[i] = mnn2[i] = 1e9;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(a[i][j]);
			int x = a[i][j];
			mxx1[x] = max(mxx1[x], i+j);
			mxx2[x] = max(mxx2[x], i-j);
			mnn1[x] = min(mnn1[x], i+j);
			mnn2[x] = min(mnn2[x], i-j);
		}
	}
	
	for(int i = 0; i < t; i++){
		sd(s[i]);
	}
	
	int ans = 0;
	for(int i = 1; i < t; i++){
		int x = s[i-1], y = s[i];
		ans = max(ans, mxx1[x] - mnn1[y]);
		ans = max(ans, mxx2[x] - mnn2[y]);
		ans = max(ans, mxx1[y] - mnn1[x]);
		ans = max(ans, mxx2[y] - mnn1[x]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}
