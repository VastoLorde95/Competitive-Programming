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

const int N = 1001;
const int K = 202;

int n, k, p;

void add(int &x, int y){
  x += y;
  if(x >= p) x -= p;
}

// number of ways for (num of robots, min val in state1, min val in state 2)
int dp[2][K][K];
int s1[2][K][K];
int s2[2][K][K];

int main(){ _
  cin >> n >> k >> p;
  
  dp[0][k+1][k+1] = 1;
  int id = 0;
  for(int i = 1; i <= n; i++){
    id ^= 1;
    for(int j = k+1; j >= 1; j--){
      for(int l = k+1; l >= 1; l--){
        s1[id^1][j][l] = s2[id^1][j][l] = dp[id^1][j][l];
        dp[id][j][l] = 0;
      } 
    }
    
    for(int j = k+1; j >= 1; j--){
      for(int l = k; l > j; l--){
        add(s1[id^1][j][l], s1[id^1][j][l+1]);
      }
    }
    
    for(int l = k+1; l > 1; l--){
      for(int j = k; j >= 1; j--){
        add(s2[id^1][j][l], s2[id^1][j+1][l]);
//        tr(i, j, l, s2[id^1][j][l]);
      }
    }
  
    for(int j = 1; j <= k; j++){
      for(int l = j+1; l <= k+1; l++){
        /*
          x > l          => 0
          x == l allowed => dp[id^1][j][l ... k+1]
          j < x < l      => 0
          x == j allowed => dp[id^1][j...l-1][l]
          x < j          => 0
        */
        
        if(l < k+1){
          add(dp[id][j][l], s1[id^1][j][l]);
          add(dp[id][j][l], (s2[id^1][j][l] - s2[id^1][l][l] + p) % p);
        }
        else{ 
          add(dp[id][j][l], s2[id^1][j][l]);
        }
        
//        tr(i, j, l, dp[id][j][l]);
      }
    }
  }
  
  int ans = 0;
  for(int x = 1; x <= k+1; x++){
    for(int y = x+1; y <= k+1; y++){
      add(ans, dp[id][x][y]);
    }
  }
  
  cout << (ans+1) << endl;
  
  
  return 0;
}
