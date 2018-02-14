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

const int N = 10100;

struct Point{
  int x, y;
  Point(int xx, int yy){
    x = xx;
    y = yy;
  }
  
};

bool cmp(const pair<Point, int> &p1, const pair<Point, int> &p2){
  return mp(p1.fi.x, p1.fi.y) < mp(p2.fi.x, p2.fi.y);
}

bool cmp2(const pair<Point, int> &p1, const pair<Point, int> &p2){
  if(p1.fi.x == 0){
    return p1.fi.y < 0;
  }
  if(p2.fi.x == 0){
    return p2.fi.y > 0;
  }
  
  return (ll) p1.fi.y * (ll) p2.fi.x <= (ll) p2.fi.y * (ll) p1.fi.x;
}

vector<Point> v;

int main(){ _
  int n;
  cin >> n;
  
  vector<pair<Point, int> > v;
  
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    v.pb(mp(Point(x,y), i));
  }
  
  sort(v.begin(), v.end(), cmp);
  
  vector<pair<Point, int> > u;
  
  for(int i = 1; i < n; i++){
    int dx = v[i].fi.x - v[0].fi.x;
    int dy = v[i].fi.y - v[0].fi.y;
    
    u.pb(mp(Point(dx, dy), v[i].se));
  }
  
  sort(u.begin(), u.end(), cmp2);
  
  cout << v[0].se + 1 << ' ' << u[(n-2)/2].se + 1 << endl;
  
  
  return 0;
}
