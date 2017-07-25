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

const int N = 100100;

struct point{
	ll x, y;
	point(ll xx, ll yy){
		x = xx, y = yy;
	}
	
	bool operator<(const point &b) const {
		return y < b.y;
	}
};

ll sqr(ll x){
	return x * x;
}

ll dis(point &a, point &b){
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int a[N];

bool cmp(const point &a, const point &b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

set<point> s;

int main(){ _
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	
	vector<point> p;
	
	for(int i = 1; i <= n; i++){
		p.pb(point(i, a[i]));
	}

	ll ans = dis(p[0], p[1]);

	int j = 0;
	s.insert(p[0]);
	for(int i = 1; i < n; i++){
		ll curx = p[i].x;
		
		while(j < i and sqr(curx - p[j].x) >= ans){
			s.erase(p[j]);
			j++;
		}
		
		int sz = 0;
		auto it = s.lower_bound(point(0, p[i].y - sqrt(ans)));
		while(it != s.end() and sqr(abs(it->y - p[i].y)) < ans){
			point tp = *it;
			ans = min(ans, dis(tp, p[i]));
			it++;
			sz++;
		}
		
		
		s.insert(p[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
