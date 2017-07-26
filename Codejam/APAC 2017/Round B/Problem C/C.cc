#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

typedef long long ll;
typedef pair<ll,ll> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const ll N = 500500;

bool cmp(const pair<ll, ll> p1, const pair<ll, ll> p2){
	if(p1.fi != p2.fi)
		return p1.fi < p2.fi;
	return p1.se > p2.se;
}

set<ll> active;
map<ll, vector<pii> > events;
vector<pair<ll, ll> > seg;
ll val[N];

void solve(){
	ll n, l1, r1, a, b, c1, c2, m;
	cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m;
	
	for(ll i = 0; i <= n; i++) val[i] = 0;
	
	seg.clear();
	events.clear();
	active.clear();
	
	seg.pb(mp(l1,r1));
	
	for(ll i = 2; i <= n; i++){
		ll x = ((l1 * a % m) + (r1 * b % m) + c1) % m;
		ll y = ((l1 * b % m) + (r1 * a % m) + c2) % m;
		seg.pb(mp(min(x, y),max(x, y)));
		l1 = x, r1 = y;
	}
	
	for(ll i = 0; i < n; i++){
		events[seg[i].fi].pb(mp(1, i));
		events[seg[i].se+1].pb(mp(-1, i));
	}

	ll cnt = 0, start = -1;
	
	foreach(it, events){
		ll x = it->fi;
		sort(it->se.begin(), it->se.end());
		
		vector<pii> &v = it->se;

		ll orig = active.size();
		foreach(jt, v){
			ll t = jt->fi, id = jt->se;
			if(t == 1){
				active.insert(id);
				if(active.size() == 2 and start != -1){
					for(auto y : active){
						if(y != id){
							val[y] += x - start;
							break;
						}
					}
					start = -1;
				}
			}
			else{
				active.erase(id);
				if(active.size() == 0 and start != -1 and orig == 1){
					val[id] += x - start;
					start = -1;
				}
			}
		}
		
		if(active.size() == 1){
			start = x;
		}
	}
	
	sort(seg.begin(), seg.end(), cmp);
	
	ll tot = 0;	
	for(ll i = 0; i < n; i++){
		ll x = seg[i].fi;
		ll y = seg[i].se;
		i++;
		while(i < n and seg[i].fi <= y){
			y = max(y, seg[i].se);
			i++;
		}
		tot += y - x + 1;
		i--;
	}
	
	ll mx = 0;
	for(ll i = 0; i < n; i++){
		mx = max(mx, val[i]);
	}
	
	cout << tot - mx << endl;
}

int main(){ _
	ll t;
	cin >> t;
	for(ll i = 1; i <= t; i++){
		cout << "Case #"<< i << ": ";
		solve();
	}
	return 0;
}
