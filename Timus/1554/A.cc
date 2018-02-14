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

const int M = 2007;
const int N = 10010;

int f[N];
int g[N];
int p[N];

void get(int n){
  for(int i = 2; i <= n; i++){
    p[i] = 1;
  }
  
  for(int i = 2; i <= n; i++){
    if(!p[i]) continue;
    for(int j = i*i; j <= n; j += i) p[j] = 0;
  }
}

int main(){ _
  int n;
  cin >> n;
  
  get(n);
  
  for(int i = 1; i <= n; i++){
    cin >> f[i];
  }
  g[1] = 1;
  
  for(int i = 2; i <= n; i++){
    for(int d = 1; d * d <= i; d++){
      if(i % d) continue;
      int a = d, b = i / d;
      if(a > 1){
        g[i] -= f[a] * g[b] % M;
        if(g[i] < 0) g[i] += M;
      }
      if(b > 1 and b != a){
        g[i] -= f[b] * g[a] % M;
        if(g[i] < 0) g[i] += M;
      }
    }
  }
  
  for(int i = 1; i <= n; i++){
    cout << g[i] << ' ';
  }
  cout << endl;
  
  
  
  return 0;
}
