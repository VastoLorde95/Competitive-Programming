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

const ld PI = acos(-1);//3.1415926535897932384626433832795;

vector<ld> get_vector(ld x, ld y){
  return {cos(y) * cos(x), cos(y) * sin(x), sin(y)};
}

void normalize(vector<ld> &v){
  ld tot = 0;
  for(ld x : v) tot += x * x;
  tot = sqrt(tot);
  for(int i = 0; i < v.size(); i++) v[i] /= tot;
}

ld dot(vector<ld> &v1, vector<ld> &v2){
  ld tot = 0;
  for(int i = 0; i < v1.size(); i++){
    tot += v1[i] * v2[i];
  }
  return tot;
}

ld get_distance(ld x1, ld y1, ld x2, ld y2){
  vector<ld> v1 = get_vector(x1, y1);
  vector<ld> v2 = get_vector(x2, y2);
  normalize(v1);
  normalize(v2);
  
  ld ang = acos(dot(v1, v2));
 
  return ang * 3437.5; 
}

int main(){
  int lat1, lat2, lat3, lon1, lon2, lon3, trash;
  char latc, lonc;
  
  scanf("Message #%d.\nReceived at %d:%d:%d.\nCurrent ship's coordinates are\n%d^%d'%d\" %cL\nand %d^%d'%d\" %cL.\n",
        &trash, &trash, &trash, &trash, &lat1, &lat2, &lat3, &latc, &lon1, &lon2, &lon3, &lonc);
  
  ld lat_ship = (latc == 'N'? 1 : -1) * (lat1 + (lat2 + lat3/60.0)/60.0) * PI / 180.0;
  ld lon_ship = (lonc == 'E'? 1 : -1) * (lon1 + (lon2 + lon3/60.0)/60.0) * PI / 180.0;
    
  scanf("An iceberg was noticed at\n%d^%d'%d\" %cL\nand %d^%d'%d\" %cL.",
        &lat1, &lat2, &lat3, &latc, &lon1, &lon2, &lon3, &lonc);
  
  ld lat_ice = (latc == 'N'? 1 : -1) * (lat1 + (lat2 + lat3/60.0)/60.0) * PI / 180.0;
  ld lon_ice = (lonc == 'E'? 1 : -1) * (lon1 + (lon2 + lon3/60.0)/60.0) * PI / 180.0;
  
  ld d = get_distance(lon_ship, lat_ship, lon_ice, lat_ice);
  
  printf("The distance to the iceberg: %.2lf miles.\n", (double)  d);  
 
  if(100.0 - d > 0.005){
    printf("DANGER!\n");
  }
  
  return 0;
}
