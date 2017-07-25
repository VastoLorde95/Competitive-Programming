#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%I64d",&x)
#define sd2(x,y) scanf("%I64d%I64d",&x,&y)
#define sd3(x,y,z) scanf("%I64d%I64d%I64d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

long long n, m, w[101][101];
long long a[101], b[101];

int main(){
    sd2(n,m);
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            sd(w[i][j]);
        }
    }
    
    if(n == 1){
        puts("YES");
        long long k = 0;
        for(long long i = 0; i < m; i++) k = max(k, w[0][i]);
        printf("%I64d\n", k+1);
        printf("0\n");
        for(long long i = 0; i < m; i++){
            printf("%I64d ", w[0][i]);
        }
        printf("\n");
        return 0;
    }   
    
    
    long long k = -1;
    bool flag1 = false, flag2 = false;
    for(long long i = 1; i < n; i++){
        long long x = 0, y = 0;
        for(long long j = 0; j < m; j++){
            if(w[i][j] > w[i-1][j]){
                flag2 = true;
                if(!x) x = w[i][j] - w[i-1][j];
                else{
                    if(x != w[i][j] - w[i-1][j]){
                        puts("NO"); return 0;
                    }
                }   
            }
            else if(w[i][j] < w[i-1][j]){
                flag1 = true;
                if(!y) y = w[i-1][j] - w[i][j];
                else{
                    if(y != w[i-1][j] - w[i][j]){
                        puts("NO"); return 0;   
                    }
                }
            }
        }
        if(x > 0 and y > 0){
            if(k == -1){
                k = x+y;
            }
            else if(k != x+y){
                puts("NO"); return 0;
            }
        }
        
    }
    if(k == -1){
        if(!flag1 and !flag2){
            k = 1e9 + 7;
            puts("YES");
            printf("%I64d\n", k);
            for(long long i = 0; i < n; i++){
                printf("0 ");
            }
            puts("");
            for(long long i = 0; i < m; i++){
                printf("%I64d ", w[0][i]);
            }
            puts("");
            return 0;
        }
        else
            k = 1e9 + 7;
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            if(k <= w[i][j]){
                puts("NO"); return 0;
            }
        }
    }
    
    for(long long i = 0; i < m; i++){
        a[i] = w[0][i];
    }
    
    for(long long i = 1; i < n; i++){
        b[i] = (w[i][0] - a[0] + k)%k;
        for(long long j = 1; j < m; j++){
            if(b[i] != (w[i][j] - a[j] + k)%k){
                puts("NO"); return 0;
            }
        }
    }
    
    puts("YES");
    printf("%I64d\n", k);
    for(long long i = 0; i < n; i++){
        printf("%I64d ", b[i]);
    }
    puts("");
    for(long long i = 0; i < m; i++){
        printf("%I64d ", a[i]);
    }
    puts("");
    
    return 0;
}
