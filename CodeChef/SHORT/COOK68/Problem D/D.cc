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

struct point{
	ll x, y; int id;
	point(ll x1, ll y1, int id1){ x = x1, y = y1, id = id1; }
};

bool cmp(const point &a, const point &b){ return a.x < b.x or (a.x == b.x and a.y < b.y); }

bool cw(point &a, point &b, point &c){ return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; }

bool ccw(point &a, point &b, point &c){ return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0; }

ll getTriangleArea(point &p1, point &p2, point &p3){
	return abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

// monotone chain O(nlogn)
void computeConvexHull(vector<point> &v, vector<point> &hull){
	if(v.size() <= 2){
		hull = v;
		return;
	}

	int sz = v.size();
	
	sort(v.begin(), v.end(), cmp);
	point a = v[0], b = v[sz-1];
	
	vector<point> up, down;
	
	up.pb(a), down.pb(a);
	
	for(int i = 1; i < sz; i++){
		if(i == sz-1  or cw(a, v[i], b)){
			int k = up.size();
			while(k >= 2 and !cw(up[k-2], up[k-1], v[i])) up.pop_back(), k--;
			up.pb(v[i]);
		}
		
		if(i == sz-1 or ccw(a, v[i], b)){
			int k = down.size();
			while(k >= 2 and !ccw(down[k-2], down[k-1], v[i])) down.pop_back(), k--;
			down.pb(v[i]);
		}
	}
	
	for(int i = 0; i < up.size(); ++i) hull.pb(up[i]);
	for(int i = (int) down.size() - 2; i > 0; --i) hull.pb(down[i]);
}

vector<point> pts, pts2, outHull, inHull;

ll solve(){
	int n; sd(n);
	
	pts.clear(), pts2.clear(), outHull.clear(), inHull.clear();
	
	for(int i = 0; i < n; i++){
		int x, y; sd2(x,y);
		pts.pb(point(x,y,i));	
	}
	computeConvexHull(pts, outHull);
	if(outHull.size() == n) return -1;
	
	set<int> outside;
	foreach(it, outHull) outside.insert(it->id);
	
	for(int i = 0; i < n; i++) if(!outside.count(pts[i].id)) pts2.pb(pts[i]);
	computeConvexHull(pts2, inHull);
	
	outHull.pb(outHull[0]);
	
	ll parea = 0;
	for(int i = 0; i < outHull.size() - 1; i++) parea += outHull[i].x * outHull[i+1].y - outHull[i+1].x * outHull[i].y;
	parea = abs(parea);
	
	ll mn = 1e18;
	int j = 0, sz = inHull.size();
	
	for(int i = 1; i < outHull.size(); i++){
		ll aa = getTriangleArea(outHull[i-1], outHull[i], inHull[j]);
		while(true){
			ll a = getTriangleArea(outHull[i-1], outHull[i], inHull[(j+1) % sz]);
			if(a < aa)
				aa = a, j = (j+1) % sz;
			else break;
		}
		mn = min(mn, aa);
	}
	return parea - mn;
}

int main(){
	int t; sd(t);
	while(t--) printf("%lld\n", solve());
	return 0;
}
