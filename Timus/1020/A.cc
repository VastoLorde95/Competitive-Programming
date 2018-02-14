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

const int N = 110;

double sqr(double x){
  return x * x;
}

double get(double x1, double y1, double x2, double y2){
  return sqrt(sqr(x1-x2) + sqr(y1-y2));
}

double x[N], y[N];

int main(){ _
  int n;
  double r;
  
  cin >> n >> r;
  
  for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];  
  x[n+1] = x[1]; y[n+1] = y[1];
  
  double ans = acos(-1) * r * 2;
  
  for(int i = 1; i <= n; i++) ans += get(x[i], y[i], x[i+1], y[i+1]);
  
  cout << fixed << setprecision(2) << ans << endl;
  
  return 0;
}
