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

int n, m, x, used[101];
vector<int> a, d, c;
string s;

int notall(){
    int aa = min((int)a.size(), m), ret = 0;
    for(int i = 0; i < aa; i++){
//        tr3(i,c[i],a[i]);
        if(c[i] > a[i]) ret += c[i] - a[i];
    }
//    tr(ret);
    return ret;
}

int find(int x){
    for(int i = m-1; i >= 0; i--){
        if(!used[i] and c[i] >= x){
            used[i] = 1;
            return i;
        }
    }
    return -1;
}

int all(){
    int aa = a.size(), dd = d.size();
    int ret = 0;
    
    for(int i = 0; i < dd; i++){
        if(find(d[i]+1) == -1)
            return 0;
    }
    
    for(int i = 0; i < aa; i++){
        x = find(a[i]);
        if(x == -1) return 0;
        
        ret += c[x] - a[i];
    }
    
    for(int i = 0; i < m; i++){
        if(!used[i]) ret += c[i];
    }
    
    return ret;
    
}

int main(){ _
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> s >> x;
        if(s[0] == 'A') a.pb(x); else d.pb(x);
    }
    
    for(int i = 0; i < m; i++){
        cin >> x; c.pb(x);
//        tr(x);
    }
    
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    sort(c.begin(), c.end(), greater<int>());
    
//    tr2(notall(), all());
    
    cout << max(notall(), all()) << "\n";
        
    return 0;
}
