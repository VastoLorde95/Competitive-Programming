#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t;
string n, m, res, suff;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        if(n.length() < m.length()) swap(n,m);
        else if(n.length() == m.length()){
            if(n < m) swap(n,m);
        }
        
        res = "";
        suff = "";
        
        int l1 = n.length(), l2 = m.length();
        
        int i = 0, j = 0;
        for(; i < l1-l2; i++) res += n[i];
        
        for(; i < l1 and j < l2; i++, j++){
            int u = n[i]-'0', v = m[j]-'0';
            if(u+v-1 >= 9){
                for(;j < l2; j++){
                    res += '9';
                }
                break;
            }
            else{
                res += char(u+v+'0');
            }
        }
        cout << res << endl;
        
        
    }
    return 0;
}

