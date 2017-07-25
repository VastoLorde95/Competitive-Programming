#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, cnt;
string s[100];

bool isface(int i, int j){
    int c[26];
    
    memset(c, 0, sizeof c);
    
    //tr4(s[i][j], s[i+1][j], s[i][j+1], s[i+1][j+1]);
    
    c[s[i][j]-'a']++;
    c[s[i][j+1]-'a']++;
    c[s[i+1][j]-'a']++;
    c[s[i+1][j+1]-'a']++;
    
    if(c[0] == 1 and c[2] == 1 and c[4] == 1 and c[5] == 1) return true;
    
    return false;
}

int main(){
    sd2(n,m);
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            if(isface(i,j) == true){
                cnt++;
            }
        }
    }
        
    cout << cnt << endl;
    return 0;
}
