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

const int N = 100100;

vector<pii> g[N];

ll t[N];
vector<pair<ll, ll> > blocks[N];

bool vis[N];

ll my_func(ll tnow, ll prev, ll ti){
  if(tnow + 100 - prev > 100500 * 100) return ti * 100500;
  else if(((tnow-prev)*ti) % 100 == 0) return ti + ((tnow - prev) * ti) / 100;
  else return ti + ((tnow - prev) * ti) / 100 + 1;
}

ll getNextTime(vector<pair<ll, ll> > &b, ll cur, ll ti){
  if(b.empty()){
    return cur + my_func(cur, 0, ti);
  }
  else if(cur <= b[0].fi){
    ll tmp = cur + my_func(cur, 0, ti);
    if(tmp <= b[0].fi) return tmp;
    else return b[0].se + ti;
  }
  
  auto it = lower_bound(b.begin(), b.end(), mp(cur,0ll));
  it--;
  
  if(it->se >= cur){
    cur = it->se;
  }
  
  ll tmp = my_func(cur, it->se, ti);
  it++;
  return (it == b.end() or (cur + tmp <= it->fi)) ? (cur + tmp) : (it->se + ti);
}

set<pair<ll, int>> q;

ll shortestPath(int x, int dest){
  q.insert(mp(0,x));
  
  while(!q.empty()){
    auto p = *q.begin();
    q.erase(p);
    
    int x = p.se;
    ll ctime = p.fi;
    
    if(vis[x]) continue;
    vis[x] = true;
    
    if(x == dest) return ctime;
    
    for(pii e : g[x]){
      int eid = e.fi, nxt = e.se;
      if(vis[nxt]) continue;
      
      ll ntime = getNextTime(blocks[eid], ctime, t[eid]);
      
      assert(ntime > ctime);
      
      q.insert(mp(ntime, nxt));
    }
  }
}

void clean(vector<pair<ll, ll>> &v, ll ti){
  if(v.empty()) return;
  
  pair<ll, ll> p = v[0];
  vector<pair<ll, ll>> newv;
  
  for(int i = 1; i < v.size(); i++){
    if(p.se + ti < v[i].fi){
      newv.pb(p);
      p = v[i];
    }
    else{
      p.se = v[i].se;
    }
  }
  
  newv.pb(p);
  v = newv;
}

int main(){ _
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b >> t[i];
    
    g[a].pb(mp(i,b));
    g[b].pb(mp(i,a));
  }
  
  int k;
  cin >> k;

  for(int i = 0; i < k; i++){
    int id, s, f;
    cin >> id >> s >> f;
    
    blocks[id].pb(mp(s,f)); 
  }

  
//  if(!(n == 4 and m == 3 and k == 1)){
//    assert(blocks[g[4][0].fi].size() == 1);
//  }
  
  for(int i = 1; i <= m; i++){
    sort(blocks[i].begin(), blocks[i].end());
    clean(blocks[i], t[i]);
  }
  
  ll ans = shortestPath(1, n);
  
  assert(ans >= 0);
  
  cout << ans << endl;
  
  return 0;
}
