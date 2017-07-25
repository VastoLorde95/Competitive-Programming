#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n, q, l, r, x, type;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>s>>q;
    n = s.length();
   	for(int i = 0; i < q; i++){
        cin>>t;
        if(type == 1){
            cin>> l >> r >> x;
            l--, r--;
            for(int i = l; i <= r; i++){
                s[i] = (char)((((s[i]-'a')+x)%26) + 'a');
            }
        }
        else{
            cout<< s << endl;
        }
    }
    return 0;
}

