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
const double eps = 1e-9;

struct Point{
  double x, y;
  Point(){}
  Point(double xx, double yy){
    x = xx, y = yy;
  }
  
  double norm(){
    return x*x + y*y;
  }
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

double dot(const Point &a, const Point &b){
  return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b){
  return a.x * b.y - a.y * b.x;
}

double distance(const Point &a, const Point &b){
  return sqrt((a-b).norm());
}

// ax + by  = c
struct Line{
  double a, b, c;
  
  Line(const Point &p1, const Point &p2){
    assert(p1 != p2);
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = a * p1.x + b * p1.y;
  }
  
  Line(double aa, double bb, double cc){
    a = aa, b = bb, c = cc;
  }
  
  bool on(Point p){
    return fabs(a * p.x + b * p.y - c) < eps;
  }
};

Point p[4];

int main(){
  for(int i = 0; i < 4; i++){
    cin >> p[i].x >> p[i].y;
  } 

  int cnt = 0;  
  
  // check perpendicular bisector of each side
  for(int i = 0; i < 4; i++){
    Point p1 = p[i];
    Point p2 = p[(i+1)%4];
    Point mid = (p1 + p2) * 0.5;
    
    Line l = Line(p1, p2);
    // find perpendicular bisector of this side
    Line b = Line(-l.b, l.a, -l.b * mid.x + l.a * mid.y);
    
    // check if this bisects the side  p[i+2], p[i+3]
    Point p3 = p[(i+2)%4];
    Point p4 = p[(i+3)%4];
    Point mid2 = (p3 + p4) / 2;
    
    Line l2 = Line(p3, p4);    
        
    if(b.on(mid2) and fabs(b.a * l2.a + b.b * l2.b) < eps){
      cnt++;
    }
  }
  
  // check angle biscetor of each angle  
  for(int i = 0; i < 4; i++){
    Point p0 = p[(i+3)%4];
    Point p1 = p[i];
    Point p2 = p[(i+1)%4];
    Point p3 = p[(i+2)%4];
    
    // check if line p1 p3 bisects the the angles at p1 and p3 using SSS test for congruency
    if(fabs(distance(p0, p1) - distance(p1, p2)) < eps and fabs(distance(p2, p3) - distance(p3, p0)) < eps) cnt++;
  }
  
  cout << cnt << endl; 
  
  return 0;
}
