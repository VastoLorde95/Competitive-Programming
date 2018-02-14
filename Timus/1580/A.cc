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

const int N = 1100;
const int M = 100100;

int a[M], b[M], c[M];

ll val[N];
vector<int> g[N];

int visv[N];
int vise[M];

vector<int> cycle;

int getCycle(int x, int col){
  visv[x] = col;
  
  for(int i : g[x]){
    if(vise[i]) continue;
    vise[i] = 1;
    
    int y = a[i] == x ? b[i] : a[i];
    int ncol = 3 - col;
    
    if(visv[y]){
      if(visv[y] != ncol){
        cycle.pb(i);
        return y;
      }
      continue;
    }
    
    int ret = getCycle(y, ncol);
    if(ret == -1) return -1;
    if(ret){
      cycle.pb(i);
      if(x == ret) return -1; else return ret;
    }
  }
  
  return 0;
}

bool done[N];

void propagate(int x){
  if(done[x]) return;
  done[x] = true;
  
  for(int i : g[x]){
    int y = a[i] == x ? b[i] : a[i];
    if(done[y]) continue;
    int z = c[i];
    
    val[y] = z + z - val[x];
    propagate(y);
  }
}

int main(){ _
  int n, m;
  cin >> n >> m;
  
  if(m < n){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  
  for(int i = 1; i <= n; i++){
    done[i] = false;
  }
  
  for(int i = 1; i <= m; i++){
    cin >> a[i] >> b[i] >> c[i];
    g[a[i]].pb(i);
    g[b[i]].pb(i);
  }
  
  for(int i = 1; i <= n; i++){
    if(done[i]) continue;
    
    cycle.clear();
    getCycle(i, 1);
    
    if(cycle.empty()){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
   
    assert(cycle.size() > 2);

    reverse(cycle.begin(), cycle.end());
    
    int x;
    int e1 = cycle[0], e2 = cycle.back();
    if(a[e1] == a[e2] or a[e1] == b[e2]) x = a[e1];
    else x = b[e1];
                
    for(int j = 0; j < cycle.size(); j++){
      if(j % 2 == 0) val[x] += c[cycle[j]];
      else val[x] -= c[cycle[j]];
    }
    
    propagate(x);
  }
  
  for(int i = 1; i <= m; i++){
    if(val[a[i]] + val[b[i]] != (ll) c[i] * 2){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  
  for(int i = 1; i <= n; i++){
    printf("%.1lf\n", (double) (val[i]) / 2.0);
  }
  
  
  
  return 0;
}
