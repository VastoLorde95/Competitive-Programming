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

unordered_map<ll, int> dp;
unordered_map<ll, ll> vol;

ll ans;

pair<int,ll> go(ll m){
	if(dp.count(m)) return mp(dp[m], vol[m]);
	
	int &retc = dp[m];
	ll &retv = vol[m];

	retc = retv = 0;

	pair<int, ll> t;

	ll up = cbrt(m), x, y;
	
	for(int i = up; i > 0; i--){
		int j = i+1;
		
		x = 1ll*i*i*i;
		y = min(1ll*j*j*j, m+1);
		
		if(dp.count(y-1-x) and dp[y-1-x] < retc) break;

		for(ll z = x, k = 1; z < y; z += x, k++){
			
			t = go(y-1-z);
			t.fi += k;
			t.se += z;
			
			if(t.fi > retc){
				retc = t.fi;
				retv = t.se;
			}
			else if(t.fi == retc and t.se > retv){
				retv = t.se;
			}
		}
	}
	
	return mp(retc, retv);
}

int main(){ _
	ll m;
	cin >> m;
	dp[0] = 0;
	
	pair<ll, ll> t = go(m);
	cout << t.fi << ' ' << t.se << '\n';
	
	return 0;
}
