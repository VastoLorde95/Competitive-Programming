#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t, cnt, l, r, b, x, y, res;
char c;
string s;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>t;
    while(t--){
        cin>>s;
        cnt = 1;
        r = 0;
        b = 0;
        x = 0;
        y = 0;
        l = s.length();
        c = s[0];
        res = 100000000;
        
        if(c == 'R') r++;
        else b++;
        
        for(int i = 1; i < l; i++){
            if(s[i] == 'R')
                r++;
            else
                b++;
            
            if(s[i] != c ){
                c = s[i];
                cnt++;
            }
            
        }
        
        for(int i = 1; i < l-1; i++){
            if(s[i-1] != s[i] and s[i] != s[i+1]){
                if(s[i] == 'R')
                    x++;
                else
                    y++;
            }
        }
        
        if(l > 1){
            if(s[0] != s[1]){
                if(s[0] == 'R') x++;
                else y++;
            }
            
            if(s[l-1] != s[l-2]){
                if(s[l-1] == 'R') x++;
                else y++;
            }
        }
        
        if(l == 1){
            cout<<1<<endl;
        }
        else if(l == 2){
            if(r == b){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else{
            if(x == 2){
                if(s[0] == 'R' and s[l-1] == 'R')
                    res = min(res, cnt-1);
                else{
                    res = min(res, cnt-2);
                }
            }
            if(x > 2){
                res = min(res, cnt-2);
            }
            
            if(x == 1){
                if(s[0] != 'R' and s[l-1] != 'R')
                    if(r > 1)
                        res = min(res, cnt-2);
                    else
                        res = min(res, cnt-1);
                else{
                    if(r > 1)
                        res = min(res, cnt-1);
                }
            }
            
            if(y == 2){
                if(s[0] == 'B' and s[l-1] == 'B')
                    res = min(res, cnt-1);
                else{
                    res = min(res, cnt-2);
                }
            }
            if(y > 2){
                res = min(res, cnt-2);
            }
            
            if(y == 1){
                if(s[0] != 'B' and s[l-1] != 'B')
                    if(b > 1)
                        res = min(res, cnt-2);
                    else
                        res = min(res, cnt-1);
                else{
                    if(b > 1)
                        res = min(res, cnt-1);
                }
            }
            
            res = min(res, cnt);
            
            cout<< res << endl;
            
        }
        
    }
    return 0;
}

