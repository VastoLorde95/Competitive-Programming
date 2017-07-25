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

typedef long long ll;
typedef pair<ll,ll> pii;

ll n;
vector<pii> v;

ll sqr(ll x){
	return x*x;
}

ll dist(pii p, ll x, ll y){
	ll x1 = p.fi, y1 = p.se;
	return sqr(x1-x) + sqr(y-y1);
}

int main(){ _
	cin >> n;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	ll res = 1e18;
		
	ll x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		
		v.pb(mp(x,y));
	}
	
	for(int i = 0; i < n; i++){
		ll d1 = dist(v[i], x1, y1);
		ll tmp = 0;
		for(int j = 0; j < n; j++){
			ll d2 = dist(v[j], x1, y1);
			if(d2 > d1){
				tmp = max(tmp, dist(v[j], x2, y2));
			}
		}
		
		res = min(res, d1+tmp);
	}
	
	swap(x1,x2);
	swap(y1,y2);
	
	for(int i = 0; i < n; i++){
		ll d1 = dist(v[i], x1, y1);
		ll tmp = 0;
		for(int j = 0; j < n; j++){
			ll d2 = dist(v[j], x1, y1);
			if(d2 > d1){
				tmp = max(tmp, dist(v[j], x2, y2));
			}
		}
		
		res = min(res, d1+tmp);
	}
	
	cout << res << endl;
	
	return 0;
}
