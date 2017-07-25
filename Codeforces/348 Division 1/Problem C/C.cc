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

const int N = 100100;

int n;
double a[N], b[N];
double x[N], y[N];
double eps = 1e-9;

long double solve(long double b, long double c){
	long double det = b*b - c*4;
	if(abs(det) < eps) det = 0;
	det = sqrt(det);
	return (det - b) / 2;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++) scanf("%lf", a+i);
	for(int i = 0; i < n; i++) scanf("%lf", b+i);
	
	x[0] = solve(-a[0] - b[0], a[0]);
	y[0] = a[0] + b[0] - x[0];
	
	for(int i = 1; i < n; i++){
		a[i] += a[i-1], b[i] += b[i-1];
		x[i] = solve(-a[i] - b[i], a[i]);
		y[i] = a[i] + b[i] - x[i];
	}
	
	for(int i = n-1; i > 0; i--){
		x[i] -= x[i-1]; y[i] -= y[i-1];
	}
	
	cout << setprecision(9) << fixed;
	
	for(int i = 0; i < n; i++) printf("%.9lf ", x[i]);
	puts("");
	for(int i = 0; i < n; i++) printf("%.9lf ", y[i]);
	puts("");
	
	
	return 0;
}

