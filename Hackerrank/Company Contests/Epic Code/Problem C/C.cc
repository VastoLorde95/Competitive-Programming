#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, cnt1, cnt2;
int b[100100], g[100100];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> g[i];
    
    sort(b, b+n);
    sort(g, g+n);
    
    for(int i = 0, j = 0; i < n and j < n;){
        if(abs(b[i]-g[j]) <= k){
            cnt1++; i++; j++;
        }
        else{
            if(b[i] > g[j]) j++;
            else i++;
        }
    } 
    
    cout << cnt1 << endl;
    return 0;
}

