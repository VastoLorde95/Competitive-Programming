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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 100100;

int n, p;
int l[N], r[N];

int main(){
	sd2(n,p);
	
	for(int i = 0; i < n; i++){
		sd2(l[i], r[i]);
	}
	
	l[n] = l[0];
	r[n] = r[0];
	
	long double res = 0;
	
	for(int i = 1; i <= n; i++){
		long long v1 = (r[i]/p) - ((l[i]-1)/p);
		long long v2 = (r[i-1]/p) - ((l[i-1]-1)/p);
		
		long long l1 = r[i]-l[i]+1;
		long long l2 = r[i-1]-l[i-1]+1;
		
		long long t = (l1-v1)*(l2-v2);
		
		long double p = (long double) t / (long double) (l1*l2);
		
		p = 1.0f-p;
		res += p*2000;
	}
	
	printf("%.9lf\n", (double)res);
	
	return 0;
}
