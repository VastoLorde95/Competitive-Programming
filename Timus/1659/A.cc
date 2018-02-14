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

struct P {
  double x, y;
  P(){}
  P(double xx, double yy){
    x = xx, y = yy;
  }
};

P operator+(const P &a, const P &b){
  return P(a.x + b.x, a.y + b.y);
}

P operator-(const P &a, const P &b){
  return P(a.x - b.x, a.y - b.y);
}

P operator*(const P &a, double t){
  return P(a.x * t, a.y * t);
}

P pts[3];
P mid[3];
P out[3];

int main(){ _
  
  for(int i = 0; i < 3; i++) cin >> pts[i].x >> pts[i].y;
  
  for(int i = 0; i < 3; i++) mid[i] = (pts[i] + pts[(i+1)%3]) * 0.5;
  
  P C = (pts[0] + pts[1] + pts[2]) * (1/3.0);
  
  for(int i = 0; i < 3; i++) out[i] = C + (mid[i] - C) * 2.0;
  
  P in1 = C + P(1, 0);
  P in2 = C + P(0.5, sqrt(3)/2.0);
  
  cout << fixed << setprecision(10) << C.x << ' ' << C.y << endl;
  cout << fixed << setprecision(10) << in1.x << ' ' << in1.y << endl;
  cout << fixed << setprecision(10) << in2.x << ' ' << in2.y << endl;
  for(int i = 0; i < 3; i++){
    cout << fixed << setprecision(10) << out[i].x << ' ' << out[i].y << endl;
  }
  
  return 0;
}
