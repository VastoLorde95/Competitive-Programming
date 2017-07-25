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

int main(){
	int n, w, l, h;
	sd(n);
	sd3(w,l,h);

	ll x, y, z;

	ll ans = 1ll << 60;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j*i <= n; j++){
			int k = (n + ((i*j)-1)) / (i*j);
			
			x = w*i;
			y = l*j;
			z = h*k;
			
			ans = min(ans, (x*y + y*z + z*x)*2);
			
			x = w*i;
			y = l*k;
			z = h*j;
			
			ans = min(ans, (x*y + y*z + z*x)*2);
			
			x = w*j;
			y = l*i;
			z = h*k;
			
			ans = min(ans, (x*y + y*z + z*x)*2);
			
			x = w*j;
			y = l*k;
			z = h*i;
			
			ans = min(ans, (x*y + y*z + z*x)*2);
			
			x = w*k;
			y = l*i;
			z = h*j;
			
			ans = min(ans, (x*y + y*z + z*x)*2);
			
			x = w*k;
			y = l*j;
			z = h*i;
			
			ans = min(ans, (x*y + y*z + z*x)*2);
		}
	}
	
	assert(ans != (1ll << 60));
	
	cout << ans << endl;
	
	return 0;
}
