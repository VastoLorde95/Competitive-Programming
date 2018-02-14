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

const int N = 200100;
const int M = 200100;

vector<int> a[N];
vector<int> d[N];

map<pii, int> node;
vector<pii> g[N];
int rid[N];

int x[M], y[M], u[M], v[M];

bool cmp1(const int &i, const int &j){
  return u[i] < u[j];
}

bool cmp2(const int &i, const int &j){
  return v[i] < v[j];
}

int tstamp;
int vis[N];
int used[N];

bool cmp3(const int &i, const int &j){
  return used[i] > used[j];
}

bool dfs(int x, int end){
  if(x == end){
    return true;
  }
  
  if(vis[x]) return false;
  vis[x] = true;
  
  for(pii p : g[x]){
    int y = p.fi, type = p.se;
    if(dfs(y, end)){
      if(type) used[rid[x]] = ++tstamp;
      return true;
    }
  }
  return false;
}

int main(){ _
  int n, m;
  cin >> n >> m;
  
  for(int i = 1; i <= m; i++){
    cin >> x[i] >> y[i] >> u[i] >> v[i];
    d[x[i]].pb(i);
    a[y[i]].pb(i);
  }
  
  int you, he, now, then;
  cin >> you >> he >> now >> then;

  if(you == he and now <= then){
    cout << 0 << endl;
    return 0;
  }

  for(int i = 1; i <= n; i++){
    sort(d[i].begin(), d[i].end(), cmp1);
    sort(a[i].begin(), a[i].end(), cmp2);
  }
  
  int ncnt = 0;  
  for(int i = 1; i <= n; i++){
    for(int j : a[i]){
      node[mp(i, j)] = ++ncnt;
      rid[ncnt] = j;
    }
    for(int j : d[i]){
      node[mp(i, -j)] = ++ncnt;
      rid[ncnt] = j;
    }
  }
  
  int start = ++ncnt;
  int end = ++ncnt;
  
  for(int i = 1; i <= n; i++){
    for(int j = 0, k = 0; j < a[i].size(); j++){
      while(k < d[i].size() and u[d[i][k]] < v[a[i][j]]) k++;
      
      if(k < d[i].size()){
        if(i ==  he and v[a[i][j]] <= then){
          g[node[mp(i, a[i][j])]].pb(mp(end, 0));
        }
        else{
          g[node[mp(i, a[i][j])]].pb(mp(node[mp(i, -d[i][k])], 0));
        }
      }
      else if(i == he and v[a[i][j]] <= then){
        g[node[mp(i, a[i][j])]].pb(mp(end, 0));
      }
    }
    
    for(int k = 0; k+1 < d[i].size(); k++){
      g[node[mp(i, -d[i][k])]].pb(mp(node[mp(i, -d[i][k+1])], 0));
    }
    
    for(int k = 0; k < d[i].size(); k++){
      int edge = d[i][k];
      g[node[mp(i, -edge)]].pb(mp(node[mp(y[edge], edge)], 1));
    }
  }
  
  
  {
    int k = 0;
    while(k < d[you].size() and u[d[you][k]] < now){
      k++;
    }  
    
    if(k < d[you].size()){
      g[start].pb(mp(node[mp(you, -d[you][k])], 0));
    }
    else{
      cout << "Impossible" << endl;
      return 0;
    }
  }
  
//  {
//    int k = 0;
//    while(k < a[he].size() and v[a[he][k]] <= then){
//      g[node[mp(he, a[he][k])]].pb(mp(end, 0));
//      k++;
//    }
//        
//  }
  
  if(!dfs(start, end)){
    cout << "Impossible" << endl;
    return 0;
  }
  else{
    vector<int> vv;
    for(int i = 1; i <= m; i++){
      if(used[i])
        vv.pb(i);
    }
    
    cout << vv.size() << endl;    
        
    sort(vv.begin(), vv.end(), cmp3);

    for(int x : vv){
      cout << x << ' ';
    }
    cout << endl;
  }
  
  return 0;
}
