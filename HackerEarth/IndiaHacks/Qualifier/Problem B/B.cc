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
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

int t, n, m, q;
int x, y;

vector<int> v1, v2;

int main(){
	sd(t);
	while(t--){
		sd3(n,m,q);
		v1.clear();
		v2.clear();
		v1.pb(1);
		v1.pb(n);
		v2.pb(1);
		v2.pb(m);
		for(int i = 0; i < q; i++){
			sd2(x,y);
			v1.pb(x);
			v2.pb(y);
		}
		
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int c1 = 0, c2 = 0;
		int mx1 = 0, mx2 = 0, mn1 = 1e9, mn2 = 1e9;
		
		for(int i = 1; i < v1.size(); i++){
			if(v1[i]-v1[i-1] > 0){
				c1++;
				mx1 = max(mx1, v1[i]-v1[i-1]);
				mn1 = min(mn1, v1[i]-v1[i-1]);
			}
			if(v2[i]-v2[i-1] > 0){
				c2++;
				mx2 = max(mx2, v2[i]-v2[i-1]);
				mn2 = min(mn2, v2[i]-v2[i-1]);
			}
		}
		
		long long count = (1ll*c1)*(1ll*c2);
		long long maxi = (1ll*mx1)*(1ll*mx2);
		long long mini = (1ll*mn1)*(1ll*mn2);
		printf("%lld %lld %lld\n", count, mini, maxi);
		
	}
	return 0;
}
