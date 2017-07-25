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

struct point{
	ll x, y;
};

ostream& operator<<(ostream& out, point& p){
	cout << p.x << ' ' << p.y;
}

bool cmp(const point &a, const point &b){
	return a.x < b.x or (a.x == b.x and a.y < b.y);
}

bool cw(point &a, point &b, point &c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(point &a, point &b, point &c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void computeConvexHull(vector<point> &v){
	if(v.size() == 1) return;

	int sz = v.size();
	
	sort(v.begin(), v.end(), cmp);
	point a = v[0], b = v[sz-1];
	
	vector<point> up, down;
	
	up.pb(a);
	down.pb(a);
	
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
	
	v.clear();
	for (int i = 0; i < up.size(); ++i)
        v.pb(up[i]);
    for (int i = down.size() - 2; i > 0; --i)
        v.pb(down[i]);
}

double getArea(point &a, point &b, point &c){
	point u = {b.x - a.x, b.y - a.y};
	point v = {c.x - a.x, c.y - a.y};
	
	return (double) abs(u.x * v.y - u.y * v.x) / 2.0;
}

int n;
ll S;

void inc(int &x){
	if(++x >= n) x -= n;	
}

void dec(int &x){
	if(--x < 0) x += n;	
}

int main(){ _
	cin >> n >> S;
	
	vector<point> p(n);
	
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;	
	}
	
	computeConvexHull(p);
	
	n = p.size();
	
	double mx = 0;
	
	point ma, mb, mc;
	
	for(int i = 0; i < n; i++){
		int j = i; inc(j);
		int k = j; inc(k);
		
		double cur = getArea(p[i], p[j], p[k]);
		
		while(j != i){
			while(k != i){
				double tmp = getArea(p[i], p[j], p[k]);
				if(tmp < cur){
					dec(k);
					break;
				}
				
				cur = tmp;
				inc(k);
			}
			
			if(k == i) dec(k);
			
			inc(j);
			double tmp = getArea(p[i], p[j], p[k]);
			if(tmp < cur){
				dec(j);
				break;
			}
			
			cur = tmp;
		}
		
		if(j == i) dec(j);
		
		if(cur > mx){
			mx = cur;
			ma = p[i], mb = p[j], mc = p[k];
		}
	}
	
	assert(mx <= S);

	point A = {ma.x + mb.x - mc.x, ma.y + mb.y - mc.y};
	point B = {ma.x + mc.x - mb.x, ma.y + mc.y - mb.y};
	point C = {mc.x + mb.x - ma.x, mc.y + mb.y - ma.y};
	
	ll area = getArea(A,B,C);
	assert(area <= S*4);
	
	tr(A);
	tr(B);
	tr(C);
	
	return 0;
}
