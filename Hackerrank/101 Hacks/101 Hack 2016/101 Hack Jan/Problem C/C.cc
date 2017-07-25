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

const int N = 51000;

int t, n, p, k, a[N];

int main(){
	sd(t);
	while(t--){
		sd3(n,p,k);
		for(int i = 0; i < n; i++){
			sd(a[i]);
			a[i] %= p;
		}
		
		for(int i = 1; i < n; i++){
			a[i] += a[i-1];
			if(a[i] >= p) a[i] -= p;
		}
		
		long long x = 0, y = 1;
		
		for(int j = k; j < 2*k and j-1 < n; j++){
			long long l = a[j-1], m = j;
//			tr(l,m,j);
			for(int i = j; i < n; i++){
				long long num = (a[i] - a[i-j] + p)%p;
				long long den = j;
				
//				tr(i,j,a[i],a[i-j],num,den);
				
				if(l*den < m*num){
					l = num, m = den;
				}
			}
			
			if(x*m < y*l){
				x = l, y = m;
			}
		}
		
		if(x == 0){
			printf("0 1\n"); continue;
		}
		
		long long g = __gcd(x,y);
		x /= g;
		y /= g;
		printf("%lld %lld\n", x, y);
		
	}
	return 0;
}
