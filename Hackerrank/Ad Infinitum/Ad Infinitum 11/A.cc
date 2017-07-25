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

int t, n, k, num[100000], check[100000], tmp, cur, flag;

vector<pair<int, int> > primes;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    sd(t);
    
    while(t--){
        sd2(n,k);
        tmp = k;
        primes.clear();
            
        for(int i = 2; i*i <= k; i++){
            if(k%i == 0){
                int cnt = 0;
                while(k%i == 0){
                    k /= i;
                    cnt++;
                }
                primes.push_back(make_pair(i, cnt));
            }
        }
        
        if(k > 1) primes.push_back(make_pair(k,1));
            
        k = tmp;
        flag = 0;
        
        for(int i = 0; i < n; i++){
            sd(num[i]);  
            check[i] = 0;
            if(num[i] == k){
                flag = 1;
            }
        }
        
        if(flag == 1){
            printf("YES\n");
            continue;
        }
        
        if(k == 1){
            for(int i = 1; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(__gcd(num[i], num[j]) == 1){
                        flag = 1;
                        i = n; j = n;
                        break;
                    }
                }
            }
            
            if(flag == 1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            continue;
        }
        
        for(int i = 0; i < primes.size(); i++){
            int p = primes[i].first, cnt;
            for(int j = 0; j < n; j++){
                if(check[i] == 0){
                    cnt = 0;
                    while(num[j]%p == 0){
                        num[j] /= p;
                        cnt++;
                    }
                
                    if(cnt == primes[i].second){
                        check[i] = 1;
                    }
                }
            }
        }
            
        int g = 0;
        for(int i = 0; i < n; i++){
            if(check[i] == 1){
                if(g == 0) g = num[i];
                else g = __gcd(g, num[i]);
            }
        }
        
        if(g == k){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
            
    }    
    return 0;
}

