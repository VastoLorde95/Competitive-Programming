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
const long double eps = 1e-11;

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

const int N = 101;

struct point{
	long double x, y;
};

long double square(long double x){
	return x*x;
}

long double squareDist(point &a, point &b){
	return square(a.x - b.x) + square(a.y - b.y);
}

long double distFromOrigin(long double x, long double y){
	return sqrt(square(x) + square(y));
}

long double getAngle(point &a, point &b, point &c){
	long double i1 = b.x - a.x;
	long double j1 = b.y - a.y;
	
	long double i2 = b.x - c.x;
	long double j2 = b.y - c.y;
	
	long double u = distFromOrigin(i1,j1);
	long double v = distFromOrigin(i2,j2);
	
	assert(u != 0 and v != 0);
	
	return (long double) acos((long double) (i1*i2 + j1*j2) / (long double) (u*v));
}

point circumcenter(point P, point Q, point R){
    long double x1 = Q.x - P.x, y1 = Q.y - P.y, x2 = R.x - P.x, y2 = R.y - P.y;
    long double x = (y2 * (x1*x1 + y1*y1) - y1 * (x2*x2 + y2*y2)) / 2.0 / (x1*y2 - x2*y1);
    long double y = -(x2 * (x1*x1 + y1*y1) - x1 * (x2*x2 + y2*y2)) / 2.0 / (x1*y2 - x2*y1);
    point ans = {P.x + x, P.y + y};
    return ans;
}

int n;

point p[N];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
	}
	
	long double ans = 0, s1, s2, s3, ang, r, s;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				if((p[j].y - p[i].y) * (p[k].x - p[j].x) == (p[k].y - p[j].y) * (p[j].x - p[i].x)) continue;
				
				bool acute = true;
				bool right_angled = false;
				point a, b, c;
				
				long double ang = getAngle(p[i],p[j],p[k]);
				
				if(ang * 2.0 > PI+eps){
					acute = false;
				}
				else if(abs(ang*2.0-PI) < eps){
					right_angled = true;
					a = p[i], b = p[j], c = p[k];
				}
				
				ang = getAngle(p[j],p[k],p[i]);
				if(ang * 2 > PI+eps) acute = false;
				else if(abs(ang*2-PI) < eps){
					right_angled = true;
					a = p[j], b = p[k], c = p[i];
				}
				
				ang = getAngle(p[k],p[i],p[j]);
				if(ang * 2 > PI+eps) acute = false;
				else if(abs(ang*2-PI) < eps){
					right_angled = true;
					a = p[k], b = p[i], c = p[j];
				}
				
				if(!acute and !right_angled) continue;
				
				if(right_angled){
					for(int t = 0; t < n; t++){
						if(t == i or t == j or t == k) continue;
						ang = getAngle(a,p[t],c);
						if(abs(ang*2-PI) < eps){
							if(squareDist(a,p[t]) != squareDist(c,b)) continue;
							if(squareDist(c,p[t]) != squareDist(a,b)) continue;
							
							point cc = {(b.x + p[t].x) / 2.0, (b.y + p[t].y) / 2.0};
							long double r = squareDist(b, cc);
							
							bool ok = true;
							for(int z = 0; z < n; z++){
								if(squareDist(p[z], cc) < r){
									ok = false;
									break;
								}
							}						
							
							if(ok) ans = max(ans, sqrt(r));
							
							break;
						}
					}
					continue;
				}
				
				a = p[i], b = p[j], c = p[k];
				s1 = sqrt(squareDist(a,b));
				s2 = sqrt(squareDist(b,c));
				s3 = sqrt(squareDist(a,c));
				
				point cc = circumcenter(a,b,c);
				r = squareDist(a, cc);
				
				bool ok = true;
				
				for(int t = 0; t < n; t++){
					if(t == i or t == j or t == k) continue;
					s = squareDist(p[t], cc);
					if(s < r){
						ok = false;
						break;
					}
				}
				if(ok) ans = max(ans, sqrt(r));
			}
		}
	}
	if(ans == 0){
		puts("-1"); return 0;
	}
	printf("%.11lf\n", (double) ans);
	
	return 0;
}
