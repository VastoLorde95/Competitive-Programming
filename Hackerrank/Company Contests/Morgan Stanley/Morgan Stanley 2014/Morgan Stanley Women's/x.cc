#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, s, x, temp, INF = -1000000000;
int buy[10000][10];
int selling[10000][10];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>> n >> s >> x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s; j++){
            cin>> buy[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s; j++){
            cin>> selling[i][j];
        }
    }
    
    for(int i = 0; i < s; i++){
        temp = INF;
        for(int j = 0; j < n; j++){
            if(buy[j][i] <= x){ // can be bought
                temp = max(temp, -buy[j][i] + selling[j][i]);
            }
        }
        if(temp != INF) x = x + temp;
    }
    
    cout<< x <<"\n";
    return 0;
}

