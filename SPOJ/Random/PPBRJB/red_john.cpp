#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int l;

bool is_prime (const int& n, int (&primes)[20000]){
	double root = sqrt (n);
	for(int i = 0; i < l and i <= root; i++){
		if(n % primes[i] == 0)
			return 0;
	}
	return 1;
}

long long fill_dp(long long (&dp)[41], int empty){
    if(empty < 4)
        return 1;
    else if(dp[empty] != 0)  
        return dp[empty];
    else
        dp[empty] = fill_dp(dp, empty - 4) + fill_dp(dp, empty - 1);
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
    int primes[20000];
    l = 1;
    primes[0] = 2; 
    //vector<int> primes;    
    //primes.push_back(2);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for(int i = 5; i < 41; i++)
        dp[i] = 0;
    
    
    fill_dp(dp, 40);
    int flag;
    double root;
    for (int i=3; i<=217286; i+=2){
    	if(is_prime(i,&primes[20000])){
       		primes[l] = i;
                l++;
       	}
	}
    ans[40] = l;
    
    int j = 5, count=0;
    int k = 0;
    //vector<int>::iterator it = primes.begin();
    while ( k < l){
        if (primes[k] > dp[j]){
        	ans[j] = count;
        	j++;
        }
        else if(primes[k] == dp[j]){
        	count++;
        	ans[j] = count;
        	j++;
        	k++;
        }
        else{
        	k++;
        	count++;
        }
	}    
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cout<<ans[n]<<endl;
    }
    return 0;
}


