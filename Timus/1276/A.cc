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

const ld PI = 3.1415926535897932384626433832795;

const int N = 40;

int n, K;

map<vector<int>, ll> dp;

string loco;

int ok(int a, int b, int c, int d, int prev){
  if(a == 1 and loco[0] == 'A' and (prev == 0 or prev == 1)) return 1;
  if(b == 1 and loco[0] == 'A' and (prev == 2 or prev == 3)) return 1;
  if(c == 1 and loco[0] == 'B' and (prev == 0 or prev == 1)) return 1;
  if(d == 1 and loco[0] == 'B' and (prev == 2 or prev == 3)) return 1;
  return 0;
}

ll solve(int a, int b, int c, int d, int prev){
  if(dp.count({a,b,c,d,prev})) return dp[{a, b, c, d, prev}];
  ll &ret = dp[{a,b,c,d,prev}];
  
  if(a+b+c+d == 1){
    return ret = ok(a, b, c, d, prev);
  }
  
  if(a and (prev == 0 or prev == 1)) ret += solve(a-1, b, c, d, 0);
  if(b and (prev == 2 or prev == 3)) ret += solve(a, b-1, c, d, 1);
  if(c and (prev == 0 or prev == 1)) ret += solve(a, b, c-1, d, 2);
  if(d and (prev == 2 or prev == 3)) ret += solve(a, b, c, d-1, 3);
  
  return ret;
}

int cnt[4];

void solve(ll &ans){
  dp.clear();
  for(int i = 0; i <= cnt[0]; i++){
    for(int j = 0; j <= cnt[1]; j++){
      for(int k = 0; k <= cnt[2]; k++){
        for(int l = 0; l <= cnt[3]; l++){
          if(i + j + k + l == K){
            if(loco[1] == 'A'){
              if(i > 0)
                ans += solve(i-1, j, k, l, 0);
              if(k > 0)
                ans += solve(i, j, k-1, l, 2);
            }
            else{
              if(j > 0)
                ans += solve(i, j-1, k, l, 1);
              if(l > 0)
                ans += solve(i, j, k, l-1, 3);
            }
          }
        }
      }
    }
  }
}

int main(){ _
  cin >> n >> K;
  cin >> loco;
  
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    if(s == "AA") cnt[0]++;
    else if(s == "AB") cnt[1]++;
    else if(s == "BA") cnt[2]++;
    else if(s == "BB") cnt[3]++;
  }
  
  ll ans = 0;
  
  swap(loco[0], loco[1]);
  
  if(K > 1){
    solve(ans);
  }
  else{
    if(loco == "AA") ans = cnt[0] > 0;
    if(loco == "AB") ans = cnt[1] > 0;
    if(loco == "BA") ans = cnt[2] > 0;
    if(loco == "BB") ans = cnt[3] > 0;
  }
  
  if(!ans){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
    cout << ans << endl;
  }
  
  return 0;
}
