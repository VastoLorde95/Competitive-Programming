#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    map<char, int> dp[100];
    int t, l;
    char c;
    long long ans;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        l = s.length();
        ans = 0;
        for(int i = 0; i < l; i++){
        	dp[i].clear();
        }
        for(int j = 0; j < l; j++){
        	for(int i = 0; i+j < l; i++){
        		c = s[i+j];
        		if(dp[i].find(c) == dp[i].end()){
        			dp[i][c] = 1;
        		}
        		else{
        			dp[i][c]++;
        		}
        		for(int k = 0; k < i; k++){
        			if(dp[i] == dp[k]){
        				ans++;
        			}
        		}
        	}	
        }
        cout<<ans<<endl;
    }
    return 0;
}
