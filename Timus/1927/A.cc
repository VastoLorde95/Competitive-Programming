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
double eps = 1e-11;

struct Point{
  double x, y;
  Point(){}
  Point(double xx, double yy){ x = xx, y = yy; }
  double norm(){ return x*x + y*y; }
};

ostream& operator<<(ostream& out, const Point &p){
  out << '(' << p.x << ' ' << p.y << ')'; return out;
}

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

struct Line{
  Point a, ab;
  Line(Point x, Point xy){
    a = x, ab = xy;
  }
};

double pointLineDistance(Point p, Line l){
  Point v1 = p - l.a;
  Point v2 = l.ab;
  
  return abs(cross(v1, v2)) / (sqrt(l.ab.norm()) * 2.0);
}

bool checkSameLine(Line l1, Line l2){
  return abs(cross((l1.a - l2.a), l1.ab)) < eps;
}

int main(){ _
  Point A, B, C, D;
  
  cin >> A.x >> A.y;
  cin >> B.x >> B.y;
  
  cin >> C.x >> C.y;
  cin >> D.x >> D.y;
  
  Point d1 = B - A;
  Point d2 = D - C;
  
  d1 = Point(-d1.y, d1.x);
  d2 = Point(-d2.y, d2.x);
  
  // we have four lines
  
  // a1 || a2
  Line a1 = Line(A, d1);
  Line a2 = Line(B, d1);
  
  // b1 || b2
  Line b1 = Line(C, d2);
  Line b2 = Line(D, d2);
  
  // if a1 || b1 then area can be infinity or 0
  // else there are four points of intersection, find them
  
  if(abs(cross(a1.ab, b1.ab)) < eps){
    // parallel
    
    // check for infinity case
    if(abs(pointLineDistance(C, a1) + pointLineDistance(C, a2) - pointLineDistance(B, a1)) < eps){
      cout << ((checkSameLine(b1, b2))? 0 : -1) << endl;
    }
    else if(abs(pointLineDistance(D, a1) + pointLineDistance(D, a2) - pointLineDistance(B, a1)) < eps){
      cout << ((checkSameLine(b1, b2))? 0 : -1) << endl;
    }
    else if(abs(pointLineDistance(A, b1) + pointLineDistance(A, b2) - pointLineDistance(D, b1)) < eps){
      cout << ((checkSameLine(a1, a2))? 0 : -1) << endl;
    }
    else if(abs(pointLineDistance(B, b1) + pointLineDistance(B, b2) - pointLineDistance(D, b1)) < eps){
      cout << ((checkSameLine(a1, a2))? 0 : -1) << endl;
    }
    else{
      cout << 0 << endl;
    }
  }
  else{
    // find the points of intersecftion
    double i1 = cross((b1.a - a1.a), b1.ab) / cross(a1.ab, b1.ab);
    double i2 = cross((b1.a - a2.a), b1.ab) / cross(a2.ab, b1.ab);
    
    double j1 = cross((b2.a - a1.a), b2.ab) / cross(a1.ab, b2.ab);
    double j2 = cross((b2.a - a2.a), b2.ab) / cross(a2.ab, b2.ab);
    
    Point p1 = a1.a + a1.ab * i1;
    Point p2 = a2.a + a2.ab * i2;
    
    Point p3 = a2.a + a2.ab * j2;
    Point p4 = a1.a + a1.ab * j1;
    
    vector<Point> v = {p1, p2, p3, p4, p1};
    
    double ans = 0;
    for(int i = 0; i < 4; i++){
      ans += cross(v[i], v[i+1]);
    }
    
    ans = abs(ans) / 2.0;
    
    cout << fixed << setprecision(10) << ans << endl;
  }
  
  return 0;
}
