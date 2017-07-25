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

using namespace std;

int n, a[5000];
vector<pair<int, int> > inv;
vector<int> cnt[5000];

long long res;

int main(){
    sd(n);
    for(int i = 0; i < n; i++){
        sd(a[i]);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] > a[i]){
                inv.pb(mp(i,j));
            }
            else if(a[j] < a[i]){
                cnt[i].pb(j);
            }
        }
    }
    for(int i = 0; i < inv.size(); i++){
        //cout << inv[i].fi << " " << inv[i].se << endl;
        vector<int>::iterator it = upper_bound(cnt[inv[i].fi].begin(), cnt[inv[i].fi].end(), inv[i].se);
        res += (cnt[inv[i].fi].end() -it);
        //cout << res << endl;
    }
    
    cout << res << endl;
    
	return 0;
}
