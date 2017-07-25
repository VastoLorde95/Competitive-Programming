#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, d, last = -1, p, ans, dp[30002][500], gem[30002];

int main()
{
    sd2(n,d);
    memset(dp, -1 , sizeof dp);

    for(int i = 1,p = 0;i <= n; i++){
        sd(p);
        gem[p]++;
        last = max(last,p);
    }

    ans = dp[d][250] = gem[d];
    
    for(int i = d; i <= last; i++){
        for(int j = 0; j <= 499; j++){
            if(dp[i][j] >= 0){
                ans=max(ans, dp[i][j]);
                if(i+d-1+j-250 <= last){
                    dp[i+d+j-250-1][j-1] = max(dp[i+d+j-250-1][j-1], dp[i][j] + gem[i+d+j-250-1]);
                }
                if(i+d+j-250 <= last){
                    dp[i+d+j-250][j] = max(dp[i+d+j-250][j], dp[i][j] + gem[i+d+j-250]);
                }
                if(i+d+j-250+1 <= last){
                    dp[i+d+j-250+1][j+1] = max(dp[i+d+j-250+1][j+1], dp[i][j] + gem[i+d+j-250+1]);
                }
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}
