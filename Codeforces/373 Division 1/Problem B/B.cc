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

const int N = 200100;
const int M = 1100;

int n;

int t[N];
int f[N];
int cnt[M];

ld c = 0;

bool ok(ll tm, ll cnt){
	ld tot = 0;
	for(int i = 1; i < M; i++){
		tot += ((ld) tm / (ld) i) * cnt[i];
	}
	
	return tot - c >= cnt;
}

int main(){
	int m; sd2(n,m);
	for(int i = 0; i < n; i++){
		sd(t[i]);
	}
	
	sort(t, t+n);
	
	set<pii> s;
	s.insert(mp(t[0], 0));
	for(int i = 1; i < n; i++){
		pii cur = *s.begin();
		s.erase(cur);
		f[i] = cur.fi;
		s.insert(mp(f[i] + t[i], i));
		s.insert(mp(cur.fi + t[cur.se], cur.se));
	}
	
	for(int i = 0; i < n; i++){
		c += (ld) f[i] / (ld) t[i];
	}
	
	for(int i = 1; i < M; i++){
		cnt[t[i]]++;
	}
	
	while(m--){
		ll a;
		scanf("%lld", &a);
		ll lo = 0, hi = a * t[0], mid;
		while(lo+1 < hi){
			mid = (lo + hi) >> 1;
			if(ok(mid, a)) hi = mid;
			else lo = mid;
		}
		
		printf("%lld\n", hi);
	}
	
	return 0;
}
