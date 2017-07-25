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

void solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll g = __gcd(c,d);
	if(g == 1){
		cout << 0 << endl;
		return;
	}
	
	ll v1 = (a-b)%g;
	v1 = (v1 + g)%g;
	
	ll v2 = (b-a)%g;
	v2 = (v2 + g)%g;
	
	ll ans = min(min(v1,v2),min(g-v1,g-v2));
	assert(ans >= 0);
	cout << ans << endl;
	
}

int main(){ _
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
