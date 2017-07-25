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

int main(){
    int t;
    long long l, r, num, mx, temp, k, last, MOD = 1000000007, ind, cnt;
    t = 1;
    while(t--){
        cin>>l>>r;
        //scanf("%lld%lld",&l,&r);
        mx = 1, temp = l;
        if(temp%2 == 1){
            temp++;
        }
        
        for(long long i = 1; (1LL<<i) < r and (1LL<<i) > 0; i++){ //see how much of this length can fit. Then from the right, check log(N) number columns for the max chain length
            if( (temp&(1LL<<i)) == 0)
                num = (temp | (1LL<<i));
            else{
                temp = (temp ^ (1LL<<i));
                num = (temp | (1LL<<i));
            }
            
            //cout<<num<<endl;
            
            if( l <= num  and num <= r ){
                last = (1LL<<i) - 1;
                if( 0 <= num + last and num + last <= r){
                    //the number completely fits
                    if(num == l){
                        mx = max(mx, (1LL<<i) - 1);
                    }
                    else{
                        mx = max(mx, (1LL<<(i+1))-1);
                        //flag = mx;
                    }
                }
                else{
                    //the number doesn't completely fit
                    mx = max(mx, r-num);
                    for(int j = i-1; j >= 1; j--){
                        last = num + (1LL<<j);
                        if( l <= last and r >= last ){
                            mx = max(mx, (1LL<<j) + min(r - num, (1LL<<j)-1));
                        }
                    }
                }
            }
        }
        
        cout<<mx<<endl;//" "<<1<<endl;  
        
    }
    
    return 0;
}
