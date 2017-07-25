#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<unordered_set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, m, l, flag;
char c;
unordered_set<long long> x;
long long h, MOD = 10000000009, p;
char temp[7000000];
int main(){
    cin>>n>>m;
    scanf("%c",&c);
    for(int i = 0; i < n; i++){
    	h = 0;
    	scanf("%s",temp);
    	int j = 0;
        while(temp[j] != '\0'){
       		h = (h*11 + temp[j])%MOD;
       		j++;
        }
        x.insert(h);
        //cout<<h<<endl;
    }
    for(int i = 0; i < m; i++){
        h = 0;
       	scanf("%s",temp);
    	int k = 0;
    	l = 0;
        while(temp[k] != '\0'){
       		h = (h*11 + temp[k])%MOD;
       		k++;
       		l++;
        }
        //cout<<h<<endl;
        p = 1;
        flag = 0;
        for(int j = l-1; j >= 0; j--){
            if(temp[j] == 'a'){
                if(x.find( (h + p)%MOD  ) != x.end()){
                    cout<<"YES\n";
                    flag = 1;
                    j = -1;
                }
                else{
                    if(x.find( (h + p + p)%MOD ) != x.end()){
                        cout<<"YES\n";
                        flag = 1;
                        j = -1;
                    }
                }
            }
            else if(temp[j] == 'b'){
                if(x.find( (h - p + MOD)%MOD ) != x.end()){
                    cout<<"YES\n";
                    flag = 1;
                    j = -1;
                }
                else{
                    if(x.find( (h + p + MOD)%MOD ) != x.end()){
                        cout<<"YES\n";
                        flag = 1;
                        j = -1;
                    }
                }
            }
            else{
                if(x.find( (h - p + MOD)%MOD ) != x.end()){
                    cout<<"YES\n";
                    flag = 1;
                    j = -1;
                }
                else{
                    if(x.find( (h - p - p + MOD + MOD)%MOD ) != x.end()){
                        cout<<"YES\n";
                        flag = 1;
                        j = -1;
                    }
                }
            }
            
            p = (p*11)%MOD;
            
        }
        
        if(flag == 0) cout<<"NO\n";
    }
    return 0;
}
