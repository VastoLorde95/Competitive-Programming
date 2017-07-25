#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans;
int no_of_1, no_of_0;
int input[100000];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>input[i];
    }
    for(int j = 0; j < 30; j++){	//check all bits
        no_of_1 = 0; no_of_0 = 0;
        for(int i = 0; i < n; i++){
            if((input[i]&(1<<j)) > 0) no_of_1++;
            else no_of_0++;
        }
        if(no_of_1 < no_of_0){
            ans |= (1<<j);
        }
    }
    cout<< ans <<"\n";
    return 0;
}

