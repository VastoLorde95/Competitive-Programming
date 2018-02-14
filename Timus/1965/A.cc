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

bool inc(vector<int> &v){
  for(int i = 1; i < v.size(); i++){
    if(v[i] <= v[i-1]) return false;
  }
  return true;
}

bool dec(vector<int> &v){
  for(int i = 1; i < v.size(); i++){
    if(v[i] >= v[i-1]) return false;
  }
  return true;
}

bool monotonic(vector<int> &v){
  return inc(v) or dec(v);
}

void print(vector<int> &p1, vector<int> &p2, bool rev){
  if(p2.empty()){
    p2.push_back(p1.back());
    p1.pop_back();
  }
  
  if(rev){
    reverse(p1.begin(), p1.end());
    reverse(p2.begin(), p2.end());
  }
  
  cout << p1.size() << ' ' << p2.size() << endl;
  for(int x : p1) cout << x << ' '; cout << endl;
  for(int x : p2) cout << x << ' '; cout << endl;
  exit(0);
}

bool ok(vector<int> &p, vector<int> &to_add, bool norm = true){
  if(norm){
    if(p.empty() or to_add.empty() or to_add.back() < p.back()) return true;
  }
  else{
    if(p.empty() or to_add.empty() or to_add.back() > p.back()) return true;
  }
    
  return false;
}

void add(vector<int> &v, vector<int> &to_add){
  reverse(to_add.begin(), to_add.end());
  v.insert(v.end(), to_add.begin(), to_add.end());
  return;
}

void same(vector<int> a, bool rev = false){
  if(rev) reverse(a.begin(), a.end());
  
  int n = a.size();
  
  set<pii> nums;
  for(int i = 0; i < n; i++){
    nums.insert(mp(a[i], i));
  }
  
  vector<int> p1, p2;
  
  while(!nums.empty()){
    auto p = *nums.rbegin();
    nums.erase(p);
    
    int start = p.se;
    vector<int> v1 = {p.fi};
    vector<int> v2;
    
    for(int i = start + 1; i < n; i++){
      v2.pb(a[i]);
      nums.erase(mp(a[i], i));
    }
    
    if(!inc(v2)){
      return;
    }
    
    if(ok(p1, v1) and ok(p2, v2)){
      add(p1, v1);
      add(p2, v2);
    }
    else if(ok(p1, v2) and ok(p2, v1)){
      add(p1, v2);
      add(p2, v1);
    }
    else return;
   
    n = start;
  }
  
  reverse(p1.begin(), p1.end());
  reverse(p2.begin(), p2.end());
  
  assert(monotonic(p1));
  assert(monotonic(p2));
  
  print(p1, p2, rev);
  
}

void opp(vector<int> a, bool rev = false){
  if(rev) reverse(a.begin(), a.end());
  
  int n = a.size();
  
  set<pii> nums;
  for(int i = 0; i < n; i++){
    nums.insert(mp(a[i], i));
  }
  
  vector<int> p1, p2;
  
  while(!nums.empty()){
    auto p = *nums.rbegin();
    nums.erase(p);
    
    int start = p.se;
    vector<int> v1 = {p.fi};
    vector<int> v2;
    
    for(int i = start + 1; i < n; i++){
      v2.pb(a[i]);
      nums.erase(mp(a[i], i));
    }
    
    if(!dec(v2)){
      return;
    }
    
    if(ok(p1, v1) and ok(p2, v2, false)){
      add(p1, v1);
      add(p2, v2);
    }
    else if(ok(p1, v2) and ok(p2, v1)){
      add(p1, v2);
      add(p2, v1);
    }
    else return;
   
    n = start;
  }
  
  reverse(p1.begin(), p1.end());
  reverse(p2.begin(), p2.end());
  
  assert(monotonic(p1));
  assert(monotonic(p2));
  
  print(p1, p2, rev);
  
}

int main(){ _
  int n;
  cin >> n;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  opp(a);
  opp(a, true);
  
  same(a);
  same(a, true);
  
  
  cout << "Fail" << endl;
  
  return 0;
}
