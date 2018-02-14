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

const ld PI = 3.1415926535;

/*
  hv = v cos a
  vv = v sin a
  
  after every bounce it becomes hv/K and vv/K
  
  time in air before the ith bounce = t = vv/5
  
  vv/5 + vv/5K + vv/5K^2 ...  
  
  d = hv * vv/5 + hv/K * vv/5K + hv/K^2 + vv/5K^2 ...
  
  d = hv * vv / 5 ( 1 + 1/k^2 + 1/k^4 + ...)
  
*/

int main(){ _
  double V, a, K;
  cin >> V >> a >> K;
//  K *= K;
  
//  tr(K);
  
  a *= PI;
  a /= 180;
  
  double hor_V = V * cos(a);
  double ver_V = V * sin(a);
  
  double dis = (hor_V * ver_V) / 5.0;
  
//  tr(dis);
  
  dis = dis * K / (K - 1.0);
  
//  tr(dis);
  
  cout << fixed << setprecision(2) << dis << endl;
  
  
  return 0;
}
