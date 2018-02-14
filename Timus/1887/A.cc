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

const int N = 30;
const int M = 10;

int a[N], b[N], c[N];
double dp[N][M+1];
double p[M];

double dp2[1 << M];

double compute(int mask){
  if(dp2[mask] >= 0) return dp2[mask];
  
  double a = 0, b = 1;
  for(int d = 0; d < M; d++){
    if(mask & (1 << d)) a += p[d];
    else b += p[d] * compute(mask | (1 << d));
  }
  
  return dp2[mask] = b / (1.0 - a);
}

int main(){ _
  int n;
  cin >> n;
  
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  
  for(int i = 1; i <= n; i++){
    cin >> c[i];
  }
  
  for(int d = 0; d < M; d++){
    dp[1][(a[1] * d * d + b[1] * d + c[1]) % 11] += 0.1;
  }
  
  for(int i = 1; i < n; i++){
    for(int d = 0; d <= M; d++){
      for(int nd = 0; nd < M; nd++){
        dp[i+1][d * (a[i+1] * nd * nd + b[i+1] * nd + c[i+1]) % 11] += dp[i][d] * 0.1;
      }
    }
  }
  
  for(int d = 0; d <= M; d++){
    p[d % 10] += dp[n][d];
  }
  
  for(int d = 0; d < M; d++){
    if(p[d] == 0){
      cout << -1 << endl;
      return 0;
    }
  }
  
  for(int i = 0; i < (1 << M); i++) dp2[i] = -1;
  dp2[(1<<M)-1] = 0;
  
  compute(0);
  
  cout << fixed << setprecision(10) << dp2[0] << endl;
  
  
  return 0;
}
