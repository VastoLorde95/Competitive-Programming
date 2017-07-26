#include <bits/stdc++.h>

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

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
long long l = v.size(); for(long long i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<long long,long long> pii;

const long long N = 100100;

long long t, n, m;
long long z;
long long a[N+N];

int main(){
	sd(t);
	while(t--){
		sd3(n,m,z);
		
		memset(a, 0, sizeof a);
		
		for(long long i = 0; i < n; i++){
			sd(a[i]);
		}
		
		if(n == 1){
			printf("%lld\n", a[0]);
			continue;
		}
		for(long long i = n-1, j = 1; i >= 0; i--, j = -j){
			a[n] = (a[n] + j*a[i] + m)%m;
		}
		if(n%2 == 0){
			n++;
			for(int i = n; i < 2*n; i++){
				a[i] = (-a[i-n] + m)%m;
			}
			
			n = 2*n;
			z %= (n);
		}
		else{		
			z %= (n+1);
		}
		printf("%lld\n", a[z]);
		
		
	}
	return 0;
}
