#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

bool is_prime (const int& n, vector<int>& v) {
  double root = sqrt (n);
  vector<int>::iterator it = v.begin();
  while ( it != v.end() && *it <= root ) {
    if (!( n % *it)) return 0;
    it++;
  }
  return 1;
}

long long fill_dp(long long (&dp)[41], int empty){
    if(empty < 4)
        return 1;
    else if(dp[empty] != 0)  
        return dp[empty];
    else{
        dp[empty] = fill_dp(dp, empty - 4) + fill_dp(dp, empty - 1);
    }
    return dp[empty];
        
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    long long dp[41];
    int ans[41];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 0;
    ans[4] = 1;
    vector<int> primes;    
    primes.push_back(2);
    
    for(int i = 0; i<41; i++)
        dp[i] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    
    fill_dp(dp, 40);
    
    for (int i=3; i<=217286; i+=2)
        if ( is_prime( i, primes ) ){ 
                primes.push_back( i );
            }
    ans[40] = primes.size();
    int j = 5, count=0;
    vector<int>::iterator it = primes.begin();
    while ( it != primes.end()) {
        if (*it > dp[j]){
        	ans[j] = count;
        	j++;
        }
        else if(*it == dp[j]){
        	count++;
        	ans[j] = count;
        	j++;
        	it++;
        }
        else{
        	it++;
        	count++;
        }
        }
    
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}


