#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).e(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<ll,ll> pii;

const int N = 200100;

int n;
vector<pii> p;

ll strt[N];
ll e[N];
ll T;
int group[N];

bool cmp(const pii &p1, const pii &p2){
	if(p1.fi * p2.se == p2.fi * p1.se) return p1.fi < p2.fi;
	else return p1.fi * p2.se > p2.fi * p1.se;
}

bool f(long double c){
	vector<pair<ll, pair<long double, long double> > > v;
	for(int i = 0; i < n; i++){
		ll x = strt[group[i]] + p[i].se;
		ll y = e[group[i]];
		long double mx = (1.0f - c * ((long double) x / (long double) T)) * p[i].fi;
		long double mn = (1.0f - c * ((long double) y / (long double) T)) * p[i].fi;
		v.pb(mp(p[i].fi, mp(mx, mn)));
	}
	
	sort(v.begin(), v.end());
	
	long double mx = -1, tmn;
	for(int i = 0; i < n; i++){
		int j = i;
		tmn = v[i].se.se;
		i++;
		while(i < n and v[i].fi == v[i-1].fi){
			tmn = min(tmn, v[i].se.se);
			i++;
		}
		
		if(tmn < mx) return false;
		while(j < i){
			mx = max(mx, v[j].se.fi);
			j++;
		}
		i--;
	}
	return true;
}

int main(){
	sd(n);
	
	p.resize(n);
	
	int x;
	for(int i = 0; i < n; i++){
		sd(x); p[i].fi = x;
	}
	
	for(int i = 0; i < n; i++){
		sd(x); p[i].se = x;
		T += x;
	}
	
	sort(p.begin(), p.end(), cmp);

	group[0] = 1;
	for(int i = 1; i < n; i++){
		if(p[i].fi * p[i-1].se == p[i-1].fi * p[i].se) group[i] = group[i-1];
		else group[i] = group[i-1] + 1;
	}
	
	strt[1] = 0;
	e[1] = p[0].se;
	for(int i = 1; i < n; i++){
		if(group[i] == group[i-1]){
			e[group[i]] += p[i].se;
		}
		else{
			strt[group[i]] = e[group[i]-1];
			e[group[i]] = strt[group[i]] + p[i].se;
		}
	}
	
	long double lo = 0, hi = 1, mid;
	for(int i = 0; i < 30; i++){
		mid = (lo + hi) / 2;
		
		if(f(mid)) lo = mid;
		else hi = mid;
	}

	printf("%.9lf\n", (double) lo);
	
	return 0;
}

