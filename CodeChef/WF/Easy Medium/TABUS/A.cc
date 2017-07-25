#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 50100;

int n, t, m;

bool cmp(const pair<pii, pii> &p1, const pair<pii, pii> &p2){
	return p1.se.se < p2.se.se;	
}

vector<pair<pii, pii> > bus;

vector<int> events[N];

bool f(int T){
	for(int i = 0; i <= n; i++){
		events[i].clear();
	}
	
	events[1].pb(0);

	for(int i = 0; i < m; i++){
		int u = bus[i].fi.fi, v = bus[i].fi.se;
		int tt = bus[i].se.fi;
		
		vector<int>::iterator it = lower_bound(events[u].begin(), events[u].end(), tt - T);
		if(it != events[u].end() and *it <= tt){
			if(v == n and bus[i].se.se <= t) return true;
			events[v].pb(bus[i].se.se);
		}
	}
	
	return false;

}

int main(){ _
	cin >> n >> t >> m;
	
	for(int i = 0; i < m; i++){
		int u, v, s, e;
		cin >> u >> v >> s >> e;
		
		bus.pb(mp(mp(u,v), mp(s,e)));
	}

	sort(bus.begin(), bus.end(), cmp);

	int lo = -1, hi = t+1, mid;	
	
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		
		if(f(mid)) hi = mid;
		else lo = mid;
	}	
	
	if(hi == t+1) hi = -1;
	
	cout << hi << endl;
	
	return 0;
}
