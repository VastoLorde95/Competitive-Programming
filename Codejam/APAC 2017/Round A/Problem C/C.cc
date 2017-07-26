#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 110;
const double eps = 1e-9;

int m;
double c[N];

void doit(){
	if(m == 1){
		printf("%.11lf\n", (-c[0] - c[1]) / c[0]);
	}
	else{
		double a = c[0];
		double b = c[0]*2 + c[1];
		double cc = c[0] + c[1] + c[2];
		
		a /= c[0];
		b /= c[0];
		cc /= c[0];
		
		double x1 = -1 + eps, x;
		
		for(int i = 0; i < 30; i++){
			x = x1;
			double f = (x*x) + b*x + cc;
			double dfdx = 2*x + b;
			x1 = x - f/dfdx; 
			if(abs(x-x1) < eps) break;
		}
		
		double x2 = 1 - eps;
		
		for(int i = 0; i < 30; i++){
			x = x2;
			double f = (x*x) + b*x + cc;
			double dfdx = 2*x + b;
			x2 = x - f/dfdx; 
			if(abs(x-x2) < eps) break;
		}
		
		if(-1-eps < x2 < 1+eps) x1 = x2;
		
		
		printf("%.11lf\n", x1);
	}
}

long double f(long double x){
	long double p = 1, res = c[0];
	for(int i = 1; i <= m; i++){
		p *= x;
		res += c[i] * p;
	}
	return res;
}

void solve(){
	sd(m);
	for(int i = 0; i <= m; i++){
		scanf("%lf", &c[i]);
	}
	
	c[0] = -c[0];
	
//	if(m <= 2){
//		doit();
//		return;
//	}
	
	reverse(c, c+m+1);
	
	long double x = 0+eps, y = -eps+2, mid;
	for(int i = 0; i < 100; i++){
		mid = (x+y)/2;
		long double val = f(mid);
		if(val > 0) x = mid;
		else y = mid;
	}
	
	printf("%.15lf\n", (double) mid-1);
	
}

int main(){
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
