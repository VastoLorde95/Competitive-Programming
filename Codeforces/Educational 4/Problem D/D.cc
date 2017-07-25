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

typedef pair<int,int> pii;

int n, k, cur;
vector<pii> res;
vector<pii> e;

int main(){
	sd2(n,k);
	int l, r;
	for(int i = 0; i < n; i++){
		sd2(l,r);
		e.pb(mp(l,-1));
		e.pb(mp(r,1));
	}
	
	l = 0, r = 0;
	int open = 0;
	sort(e.begin(), e.end());
	
	foreach(it, e){
		if(it->se == -1) cur++; else cur--;
		if(cur >= k and open == 0){
			l = it->fi; open = 1;
		}
		else if(cur < k and open == 1){
			res.pb(mp(l,it->fi));
			open = 0;
		}
	}
	
	printf("%d\n", (int) res.size());
	foreach(it, res) printf("%d %d\n", it->fi, it->se);
	
	return 0;
}
