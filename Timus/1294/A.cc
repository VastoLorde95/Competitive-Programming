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

int get_sign(ll x){
  return x < 0;
}

int main(){
  ll b, d, p, q;
  cin >> d >> p >> q >> b;
  
  ll term1 = (b * p - d * q);
  ll term2 = (p * q - b * d);
  ll term3 = (b * q - d * p);
  
  if(term3 == 0 or (get_sign(term1) ^ get_sign(term2) ^ get_sign(term3) > 0)){
    cout << "Impossible." << endl;
    return 0;
  }
 
  ld res = (ld) term1 / (ld) term3;
  res *= (ld) term2;
  res = sqrt(res);
  res *= 1000.0;
  
  cout << "Distance is ";
  cout << fixed << setprecision(0) << res;
  cout << " km." << endl; 
  
  return 0;
}
