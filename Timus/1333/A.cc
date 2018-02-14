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

const int N = 11;

double x[N], y[N], r[N];

double sqr(double x){
  return x * x;
}

int main(){ _
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
  
  double ans = 0;
  const double step = 1e-2;
  const double eps = 1e-9;
  
  for(double i = 0; i <= 1; i += step){
    for(double j = 0; j <= 1; j += step){
      for(int k = 0; k < n; k++){
        if(sqr(i-x[k]) + sqr(j-y[k]) <= sqr(r[k])){
          ans += step;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}
