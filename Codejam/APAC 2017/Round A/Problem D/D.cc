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

const int N = 13;

int k[N], l[N];
ll a[N][N];
ll c[N][N];

ll m, n;

vector<pair<ll,ll> > get(vector<int> &v){
	vector<pair<ll,ll> > al;
	int r = v[0];
	
	for(int i = l[r]; i <= k[r]; i++){
		if(c[r][i] > m) continue;
		al.pb(mp(a[r][i], c[r][i]));
	}
	
	for(int i = 1; i < v.size(); i++){
		r = v[i];
		vector<pair<ll, ll> > tmp;
		
		for(int j = l[r]; j <= k[r]; j++){
			foreach(it, al){
				ll x = it->fi, y = it->se;
				if(y+c[r][j] > m) continue;
				tmp.pb(mp(x+a[r][j],y+c[r][j]));
			}
		}
		al = tmp;
	}
	return al;
}

ll solve(vector<int> &v){
	vector<int> x, y;
	for(int i = 0; i < 4; i++){
		x.pb(v[i]);
		y.pb(v[4+i]);
	}
	
	vector<pair<ll,ll> > v1, v2;
	v1 = get(x);
	v2 = get(y);
	
	for(int i = 0; i < v1.size(); i++){
		swap(v1[i].fi, v1[i].se);
	}
	for(int i = 0; i < v2.size(); i++){
		swap(v2[i].fi, v2[i].se);
	}
	
	sort(v2.begin(), v2.end());
	for(int i = 1; i < v2.size(); i++){
		v2[i].se = max(v2[i].se, v2[i-1].se);
	}
	
	ll ret = 0;
	const ll INF = 1ll << 60;
	for(int i = 0; i < v1.size(); i++){
		ll cost = v1[i].fi, atk = v1[i].se;
		int j = upper_bound(v2.begin(), v2.end(), mp(m-cost, INF)) - v2.begin();
		j--;
		if(j >= 0){
			ret = max(ret, atk + v2[j].se);
		}
	}
	return ret;
}

void solve(){
	scanf("%lld%lld", &m, &n);
	for(int i = 1; i <= n; i++){
		sd2(k[i],l[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%lld", &a[i][j]);
		}
		for(int j = 2; j <= k[i]; j++){
			scanf("%lld", &c[i][j]);
		}
	
		c[i][l[i]] = 0;
		for(int j = l[i]+1; j <= k[i]; j++){
			c[i][j] += c[i][j-1];
		}
		
	}
	
	ll ans = 0;
	
	for(int i = 0; i < (1 << n); i++){
		int sz = __builtin_popcount(i);
		if(sz != 8) continue;
		
		vector<int> v;
		for(int j = 0; j < n; j++){
			if((i&(1<<j))) v.pb(j+1);
		}
		ans = max(ans, solve(v));
	}

	printf("%lld\n", ans);
	
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
