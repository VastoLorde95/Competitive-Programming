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

int n, k;
double l, v1, v2;

bool f(double T){
	int s = n;
	double d1 = 0, d2 = 0;
	
	while(s > 0){
		double x = l - d1;
		double t = (x - v1 * T) / (v2 - v1);
		if(t > T) return false;
		
		T -= t;
		s -= k;
		
		if(s <= 0) return true;
		
		d2 = d1 + v2 * t;
		d1 += v1 * t;
		
		t = (d2 - d1) / (v1 + v2);
		
		if(t > T) return false;
		T -= t;
		
		d1 = d2 = d1 + v1 * t;
	}
	return true;
}

int main(){
	cin >> n >> l >> v1 >> v2 >> k;
	
	double lo = 0, hi = l / v1, mid;
	
	for(int i = 0; i < 100; i++){
		mid = (lo + hi) / 2;
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	
	cout << fixed << setprecision(20) << hi << endl;
	
	
	return 0;
}
