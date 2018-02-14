//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

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

double sqr(double x){
  return x * x;
}

struct Point{
  double x, y;
  Point(){}
  Point(double xx, double yy){ x = xx, y = yy; }
  double norm(){ return x*x + y*y; }
};

bool operator==(const Point &a, const Point &b){
  return a.x == b.x and a.y == b.y;
}

bool operator!=(const Point &a, const Point &b){
  return !(a == b);
}

Point operator+(const Point &a, const Point &b){
  return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point &a, const Point &b){
  return Point(a.x - b.x, a.y - b.y);
}

Point operator*(const Point &p, double t){
  return Point(p.x * t, p.y * t);
}

Point operator/(const Point &p, double t){
  return Point(p.x / t, p.y / t);
}

Point rotate(const Point &p, double theta){
  return Point(p.x * cos(theta) + p.y * sin(theta), -p.x * sin(theta) + p.y * cos(theta));
}

double dot(const Point &a, const Point &b){
  return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b){
  return a.x * b.y - a.y * b.x;
}

double distance(const Point &a, const Point &b){
  return sqrt((a-b).norm());
}

double R;

double get(Point C, Point D, Point A, double x, double ang, double v){
  Point B = rotate(A, x);
  
  double tan_dist = sqrt(C.norm() - A.norm());
  double CB_dist = distance(C, B);

  if(CB_dist <= tan_dist){
    return CB_dist / v;
  }
  else{
    return (tan_dist + (ang - x - acos(R / sqrt(C.norm()))) * R) / v;
  }
}

int main(){
  double x1, y1, z1;
  double x2, y2, z2;

  cin >> x1 >> y1 >> z1;
  cin >> x2 >> y2 >> z2;
  
  double v;
  cin >> v;
  
  R = sqrt(sqr(x1) + sqr(y1) + sqr(z1));
  double D = sqrt(sqr(x2) + sqr(y2) + sqr(z2));
  
  double ang = acos((x1 * x2 + y1 * y2 + z1 * z2) / (R * D));
  
  Point A = Point(0, R);  // carrier
  Point B = rotate(A, ang);
  Point C = B / sqrt(B.norm()) * D; // spaceship
  
  double lo = 0, hi = ang, mid;
  
  double tt;
  
  for(int i = 0; i < 20; i++){
    mid = (lo + hi) * 0.5;
    
    double t1 = R * mid;
    double t2 = get(C, B, A, mid, ang, v);
    tt = t2;
    
    
    if(t1 < t2) lo = mid;
    else hi = mid;
  }
  
  cout << fixed << setprecision(10) << tt << endl;
  
  return 0;
}
