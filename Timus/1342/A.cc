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
typedef double ld;
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

const ld INF = 1e9;
const int N = 1010;

ld get_cost(int x, ld k, ld p, ld q){
  if(k == 1) return p;
  return ((k * p - q) * x + (q - p) * ((x * (x + 1))/2)) / (k - 1);
}

int pos[2][N];
ld dp[2][N];
int k[N];
ld p[N], q[N];

// O(N M log M)
void solve(int id, int i, int x, int y, int lft, int rgt){
  int mid = (x + y) / 2;
  if(y < x or rgt < lft) return;

  for(int j = 1; j <= k[i]; j++){
    if(mid - j + 1 < lft or mid - j + 1 > rgt) continue;
    
    ld val = dp[id^1][mid-j] + get_cost(j, k[i], p[i], q[i]);
    
    if(val <= dp[id][mid]){
      dp[id][mid] = val;
      pos[id][mid] = mid - j;
    }
  }
  
  solve(id, i, x, mid-1, lft, pos[id][mid]);
  solve(id, i, mid+1, y, pos[id][mid], rgt);
}

int main(){ _
  int n, m;
  cin >> n >> m;
  
  int tot = 0;
  for(int i = 1; i <= n; i++){
    cin >> k[i] >> p[i] >> q[i];
    tot += k[i];
  }
  
  if(tot < m){
    ld ans = 0;
    for(int i = 1; i <= n; i++){
      ans += get_cost(k[i], k[i], p[i], q[i]);
    }
    cout << "Maximum possible amount: " << tot << endl;
    cout << fixed << setprecision(2) << "Minimum possible cost: " << ans << endl;
    return 0;
  }
  
  for(int id = 0; id < 2; id++){      
    for(int i = 1; i <= m; i++){
      dp[id][i] = INF;
      pos[id][i] = m+1;
    }
    dp[id][0] = 0;
  }
  
  for(int i = 1; i <= k[1]; i++){
    dp[0][i] = get_cost(i, k[1], p[1], q[1]);
    pos[0][i] = 0;
  }

  int done = k[1];
  
  int id = 0;
  for(int i = 2; i <= n; i++){
    id ^= 1;
    for(int j = 1; j <= m; j++) dp[id][j] = dp[id^1][j], pos[id][j] = pos[id^1][j];
    solve(id, i, 1, m, 1, m);
    done += k[i];
  }
  
  cout << fixed << setprecision(2) << "Minimum possible cost: " << dp[id][m] << endl;
  
  return 0;
}
