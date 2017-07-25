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

typedef long long ll;

int n, a, b;
vector<pair<double,double> > p;

double mx, mn;
double eps = 1e-12;

double dist(double x1, double y1, double x2, double y2){
	double l = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	if(fabs(l) < eps) return x1*x1+y1*y1;
	l = ((-x1*(x2-x1)) - (y1*(y2-y1))) / l;
	if(l < 0) return x1*x1+y1*y1;
	if(l > 1) return x2*x2+y2*y2;
	
	double x = x1 + (x2-x1)*l;
	double y = y1 + (y2-y1)*l;
	return x*x + y*y;
	
}

int main(){
	sd3(n,a,b);
	
	double pi = acos(0)*2;
	
	for(int i = 0; i < n; i++){
		int x, y; sd2(x,y);
		p.pb(mp(x-a,y-b));
	}
	p.pb(p[0]);
	
	mx = 0;
	mn = 1e18;	
	for(int i = 1; i <= n; i++){
		ll x1 = p[i].fi, y1 = p[i].se, x2 = p[i-1].fi, y2 = p[i-1].se;
		mx = max(mx, pi*max(x1*x1+y1*y1,x2*x2+y2*y2));
		mn = min(mn, pi*dist(x2,y2,x1,y1));
//		tr3(i,mx,mn);
	}
	
	printf("%.20lf\n", (mx-mn));
	return 0;
}
