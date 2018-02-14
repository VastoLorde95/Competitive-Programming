#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const double PI = 3.1415926535897932384626433832795;

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

double dot(const Point &a, const Point &b){
  return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b){
  return a.x * b.y - a.y * b.x;
}

double distance(const Point &a, const Point &b){
  return sqrt((a-b).norm());
}



int main(){ _
  int x1, y1, x2, y2;
  
  const double inf = 1e9;
  
  double mxx = -inf, mnx = inf;
  double mxy = -inf, mny = inf;
  
  int cnt = 0;
  
  while(cin >> x1 >> y1 >> x2 >> y2){
    
    cnt++;
    
    mxx = max(mxx, (double) max(x1, x2));
    mnx = min(mnx, (double) min(x1, x2));
    
    mxy = max(mxy, (double) max(y1, y2));
    mny = min(mny, (double) min(y1, y2));
    
    
    Point A = Point(x1, y1);
    Point B = Point(x2, y2);
    
    Point v = Point(x2 - x1, y2 - y1) / 2;
    Point rv = Point(-v.y, v.x);
    
    Point C = ((A + B) * 0.5) + rv;
    
    mxx = max(mxx, C.x);
    mnx = min(mnx, C.x);
    
    mxy = max(mxy, C.y);
    mny = min(mny, C.y);   
    
  }
  
  if(!cnt){
    cout << fixed << setprecision(4) << 0 << ' ' << 0 << endl;  
    return 0;
  }
  
  double w = mxx - mnx;
  double h = mxy - mny;
  
  cout << fixed << setprecision(4) << w << ' ' << h << endl;
  
  return 0;
}
