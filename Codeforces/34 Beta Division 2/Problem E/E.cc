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

const double eps = 1e-12;

int n, t;
vector<pair<pair<double, int> ,pair<double,double> > > v, tmp;
double res[20];

bool f(double jump){
	tmp = v;
	for(int i = 0; i < n; i++) tmp[i].fi.fi += (jump * tmp[i].se.fi);
	
	for(int i = 1; i < n; i++){
		if(tmp[i].fi.fi <= tmp[i-1].fi.fi) return true;
	}
	return false;
}

int main(){ _
	cin >> n >> t;
	
	for(int i = 0; i < n; i++){
		double x, vv, m;
		cin >> x >> vv >> m;
		v.pb(mp(mp(x,i),mp(vv,m)));
	}
	
	sort(v.begin(), v.end());

	cout.precision(15);
	double cur = 0;
	while(t > cur){
		double lo = eps, hi =(double) t-cur+eps, mid;
		while(hi-lo > eps){
			mid = (hi+lo)/2;
			
			if(f(mid)){
				hi = mid;
			}
			else{
				lo = mid;
			}
		}
		
		double jump = lo+eps;
//		tr(jump);
		
		int x;
		cin >> x;
		
		for(int i = 0; i < n; i++){
			v[i].fi.fi += (v[i].se.fi * jump);
		}
		
		double v1, v2, m1, m2;
		for(int i = 1; i < n; i++){
//			tr4(i, fabs(v[i].fi.fi - v[i-1].fi.fi), eps, (fabs(v[i].fi.fi - v[i-1].fi.fi) < eps));
			if(i-1 >= 0 and v[i].fi.fi <= v[i-1].fi.fi){
				v1 = v[i-1].se.fi, v2 = v[i].se.fi;
				m1 = v[i-1].se.se, m2 = v[i].se.se;
				
//				tr2(((m1-m2)*v1 + m2*v2*2), (m1+m2));
				
				v[i-1].se.fi = ((m1-m2)*v1 + m2*v2*2) / (m1+m2);
				v[i].se.fi = ((m2-m1)*v2 + m1*v1*2) / (m1+m2);
			}
		}
		
		
//		tr(v);
		
		cur += jump;
	}
	
	for(int i = 0; i < n; i++){
		res[v[i].fi.se] = v[i].fi.fi;
	}
	for(int i = 0; i < n; i++){
		cout << fixed << res[i] << endl;
	}
	
	return 0;
}
