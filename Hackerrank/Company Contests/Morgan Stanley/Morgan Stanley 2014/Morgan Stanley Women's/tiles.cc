#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, values[2001], __GCDS[101][101];
long long ans[2001], MOD_IT=1000000007;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        cin>>values[i];
    }
    
    for(int i = 1; i <= 100; i++){
        for(int j = i; j <= 100; j++){
            __GCDS[j][i] = __GCDS[i][j] = __gcd(i,j);
        }
    }
    
    ans[1] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(__GCDS[values[i]][values[j]] == 1){
                (ans[i] += ans[j]) %= MOD_IT;
            }
        }
    }
    
    cout<< ans[n] << endl;
    
    
    return 0;
}

