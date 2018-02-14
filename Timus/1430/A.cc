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

const int MAGIC = 1000;

void solve(ll a, ll b, ll n){
  if(gcd(a,b) == 1){
    
  }
}

int main(){ _
  ll a, b, n;
  cin >> a >> b >> n;
  
  solve(a, b, n);
  return 0;
  
  bool swapped = false;
  if(a < b){
    swap(a, b);
    swapped = true;
  }
  
  if(a >= MAGIC){
    ll ans = 0, x = 0, y = 0;
    for(int i = 0; a * i <= n; i++){
      int j = (n - a * i) / b;
      ll val = a * i + j * b;
      if(val > ans){
        ans = val; x = i; y = j;
      }
    }
    if(swapped) swap(x, y);
    cout << x << ' ' << y << endl;
  }
  else{
    vector<int> done(b, 0);
    ll ans = (n / b) * b, x = 0, y = n / b;
    
    ll lim = n % b;
    ll mx = 0;
    for(int i = 1; a * i <= n; i++){
      ll num = a * i % b;
      if(done[num]) break;
      done[num] = 1;
      if(mx < num and num <= lim){
        mx = num;
        x = i;
        y = (n - a * i) / b;
        ans = a * x + b * y;
      }
    }
    if(n % a == 0){
      x = n /a, y = 0;
    }
    if(swapped) swap(x, y);
    cout << x << ' ' << y << endl;
  }
  
  return 0;
}
