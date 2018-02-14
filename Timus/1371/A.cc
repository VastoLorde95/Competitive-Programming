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

const int N = 50100;

int sz[N];
vector<int> g[N];
vector<pair<pii, int> > edges;

void dfs(int x, int prev){
  sz[x] = 1;
  for(int y : g[x]){
    if(y == prev) continue;
    dfs(y, x);
    sz[x] += sz[y];
  }
}

int main(){ _
  int n;
  cin >> n;
  
  for(int i = 1; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    g[a].pb(b);
    g[b].pb(a);
    edges.pb(mp(mp(a,b), c));
  }
  
  dfs(1, -1);
  
  double ans = 0;
  double mul = (double) (1.0 / n) / double (n-1);
 
  for(auto p : edges){
    int a = p.fi.fi, b = p.fi.se, c = p.se;
    
    ans += (mul * c) *  (min(sz[a], sz[b]) * (n - min(sz[a], sz[b]))) * 2;
  }
  
  cout << fixed << setprecision(4) << ans << endl;
  
  return 0;
}
