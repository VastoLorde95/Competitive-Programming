#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, m, t[100001], u, v, tim, cities[100001], res;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    sd2(n,m);
    int dp[n+1][n+1];
    
    for(int i = 1; i <= n; i++){
        sd(t[i]);
    }
    
    for(int i = 0; i < m; i++){
        sd3(u,v,tim);
        dp[u][v] = dp[v][u] = tim;
    }
    
    for(int i = 0; i < m; i++){
        sd(cities[i]);
    }
    
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][k] > 0 and dp[k][j] > 0){
                    if(dp[i][j] == 0){
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                    else{
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
    }
    
    res = t[cities[0]];
    
    for(int i = 1; i < m; i++){
        res += dp[cities[i]][cities[i-1]] + t[cities[i]];
    }
    
    cout << res << endl;
    
    return 0;
}

