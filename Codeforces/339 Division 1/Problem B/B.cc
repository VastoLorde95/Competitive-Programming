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

typedef long long ll;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
ll l = v.size(); for(ll i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const ll N = 100100;

ll n, A, cf, cm, m;
vector<pair<ll, ll> > u, v;

ll ans[N], sum[N];

int main(){ _
	cin >> n >> A >> cf >> cm >> m;
	
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		u.pb(mp(x,i));
	}
 
	sort(u.begin(), u.end());
	
	for(int i = 0; i < n; i++){
		sum[i+1] = sum[i] + u[i].fi;
	}
	
	v = u;	
	ll force = -1, ansi = -1, ansm = -1;
	for(int i = 0, j = 0; i <= n; i++){
		ll cost = 0, tmp = 0;
		cost = A*(n-i) - (sum[n] - sum[i]);
		
		if(cost > m) continue;
		
		tmp += (n-i)*cf;
		ll rem = m - cost;
	
		while(j < i and j*v[j].fi - sum[j] <= rem){
			j++;
		}
		
		ll mn;
		if(j > 0){
			mn = min(A, (rem + sum[j])/j);	
		}
		else{
			mn = A;
		}
		
		tmp += mn*cm;
		
		if(tmp > force){
			force = tmp;
			ansi = i;
			ansm = mn;
		}
	}

	cout << force << endl;
	for(int i = 0; i < n; i++){
		if(i < ansi){
			v[i].fi = max(v[i].fi, ansm);
		}
		else v[i].fi = A;
		
		ans[v[i].se] = v[i].fi;
	}
	
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
