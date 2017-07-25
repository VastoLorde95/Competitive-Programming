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

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ld xp, yp, vp;
ld x, y, v, r;
ld R, w;
const ld PI = 3.1415926535897932384626433832795;

ld eps = 1e-9;

ld dist(ld x1, ld y1, ld x2, ld y2){
	ld dx = x1 - x2, dy = y1 - y2;
	return (ld) sqrt(dx*dx + dy*dy);
}

ld distPointFromLine(ld x0, ld y0, ld x1, ld y1, ld x2, ld y2){
	return abs((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1);
}

ld angleBetweenVectors(ld u1, ld u2, ld v1, ld v2){
	return acos((u1*v1 + u2*v2) / dist(0,0,u1,u2) / dist(0,0,v1,v2));
}

bool isAcute(ld u1, ld u2, ld v1, ld v2){
	return (u1*v1 + u2*v2 > 0);
}

ld distWithCircle(ld x1, ld y1, ld x2, ld y2){
	if(dist(x1,y1,x2,y2) < eps) return 0;
	
	ld d = distPointFromLine(0, 0, x1, y1, x2, y2);
	
	if(d >= r * dist(x1, y1, x2, y2)) return dist(x1,y1,x2,y2);
	
	if(!isAcute(-x1, -y1, x2 - x1, y2 - y1) or !isAcute(-x2, -y2, x1 - x2, y1 - y2)) return dist(x1,y1,x2,y2);
	
	
	ld d1 = dist(0, 0, x1, y1);
	ld d2 = dist(0, 0, x2, y2);
	
	ld d3 = sqrt(d1*d1 - r*r);
	ld d4 = sqrt(d2*d2 - r*r);
	
	ld ang1 = angleBetweenVectors(-x1, -y1, x2 - x1, y2 - y1);
	ld ang2 = angleBetweenVectors(-x2, -y2, x1 - x2, y1 - y2);
	ld ang3 = acos((ld)r / d1);
	ld ang4 = acos((ld)r / d2);
	
	ld ang = PI - ang1 - ang2 - ang3 - ang4;
	
	return d3 + d4 + r * ang;
	
}

int main(){ _
	
	cin >> xp >> yp >> vp;
	cin >> x >> y >> v >> r;
	
	R = dist(0, 0, xp, yp);
	w = vp / R;
	
	if(dist(xp,yp,x,y) < eps){
		cout << setprecision(11) << fixed << 0 << endl;
		return 0;
	}
	
	ld lo = 0, hi = 1e9, t;
	for(int i = 0; i < 100; i++){
		t = (lo + hi) / 2;
		
		ld wt = w*t;
		ld nx = xp * cos(wt) - yp * sin(wt);
		ld ny = yp * cos(wt) + xp * sin(wt);
		
		ld d = distWithCircle(x, y, nx, ny);
		if(d <= v * t) hi = t;
		else lo = t;
	}

	cout << setprecision(11) << fixed << lo << endl;
	
	return 0;
}
