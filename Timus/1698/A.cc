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

const int N = 2020;

vector<int> num1;
vector<int> num2;

int n;

int main(){ _
  cin >> n;
  
  if(n == 1){
    cout << 3 << endl;
    return 0;
  }
  
  num1.resize(n, 0);
  num1[0] = 5;
  num1[1] = 2;
  
  for(int i = 1; i < n; i++){
    int nd = num1[i] % 10;
    
    for(int j = 0; j < i and i + j < n; j++){
      num1[i+j] += nd * num1[j] * 2;
    }
        
    if(i + i < n) num1[i+i] += nd * nd;
    
    
    assert(num1[i] % 10 == nd);
    
    if(i + 1 < n) num1[i+1] += num1[i] / 10;
    num1[i] = nd;
  }
  
  num2.resize(n, 0);  
  num2[0] = 6;
  num2[1] = 3;
  
  for(int i = 1; i < n; i++){
    int nd = (10 - (num2[i] % 10)) % 10;
    
    for(int j = 0; j < i and i + j < n; j++){
      num2[i+j] += nd * num2[j] * 2;
    }
        
    if(i + i < n) num2[i+i] += nd * nd;
    
    
    assert(num2[i] % 10 == nd);
    
    if(i + 1 < n) num2[i+1] += num2[i] / 10;
    num2[i] = nd;
  }
  
  int ans = 3;
  for(int i = 1; i < n; i++){
    ans += (num1[i] > 0);
    ans += (num2[i] > 0);
  }
  
  cout << ans << endl;
  
  
  return 0;
}
