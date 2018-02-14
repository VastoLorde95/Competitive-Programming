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
const ld eps = 1e-9;

struct Point{
  ld x, y, z;
  Point(ld xx, ld yy, ld zz){
    x = xx, y = yy, z = zz;
  }
  
  ld norm(){
    return x*x + y*y + z*z;
  }
  
  bool iszero(){
    return fabs(x) < eps and fabs(y) < eps and fabs(z) < eps;
  }
};

Point operator-(const Point &a, const Point &b){
  return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

Point operator+(const Point &a, const Point &b){
  return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point operator*(const Point &a, ld t){
  return Point(a.x * t, a.y * t, a.z * t);
}

Point cross(const Point &a, const Point &b){
  return Point(a.y * b.z - a.z * b.y, a.x * b.z - a.z * b.x, a.x * b.y - a.y * b.x);
}

ld dot(const Point &a, const Point &b){
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

ld distance(const Point &a, const Point &b){
  return sqrt((a-b).norm());
}

int main(){
  int n; ld d;
  cin >> n >> d;
  
  vector<pair<pair<Point, Point>, int> > v;
  for(int i = 0; i < n; i++){
    ld x, y, z;
    cin >> x >> y >> z;
    
    ld vx, vy, vz;
    cin >> vx >> vy >> vz;
    
    v.pb(mp(mp(Point(x,y,z), Point(vx, vy, vz)), i));
  }
  
  ld t = -1;
  int ansx = -1, ansy = -1;
  
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      Point v1 = v[i].fi.se;
      Point v2 = v[j].fi.se;
      
      Point vv = v2 - v1;
      
      if(vv.iszero()) continue;
      
      Point x0 = v[i].fi.fi;
      
      // find distance of p[i] from line x1-x2
      Point x1 = v[j].fi.fi;
      Point x2 = x1 + vv;
      
      ld dis = sqrt(max((ld) fabs(cross(x0 - x1, x0 - x2).norm()) / (x2 - x1).norm(), (ld) 0.0));
      
      if(dis <= d + eps){
        ld moment = - dot(x1 - x0, x2 - x1) / (x2 - x1).norm();
        
        if(moment <= 0) continue;
        
        ld lo = 0, hi = moment, mid;
        
        while(hi - lo > eps){
          mid = (lo + hi) / 2.0;
          
          Point p = x1 + vv * mid;
          ld dis = distance(p, x0);
          if(dis <= d + eps) hi = mid;
          else lo = mid;
        }
        
        if(ansx == -1 or hi < t) t = hi, ansx = i, ansy = j;
      }
    }
  }
  
  if(ansx == -1){
    cout << "OK" << endl;
  }
  else{
    cout << "ALARM!" << endl;
    cout << fixed << setprecision(3) << t << ' ' << ansx+1 << ' ' << ansy+1 << endl;
  }
  
  return 0;
}
