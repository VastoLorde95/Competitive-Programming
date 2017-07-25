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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, s, m;
int a[100100];
vector<int> sets[100100];
int MOD = 1e9 + 9;

int main(){
    sd3(n,s,m);
    for(int i = 1; i <= s; i++){
        int x, y;
        sd(x);
        for(int j = 0; j < x; j++){
            sd(y); sets[i].pb(y);
        }
    }
    while(m--){
        int t; sd(t);
        if(t == 1){
            int aa, val; sd2(aa,val);
            foreach(it, sets[aa]){
//            	tr2(aa, *it);
                a[*it] += val;
                if(a[*it] >= MOD) a[*it] -= MOD;
            }
        }
        else if(t == 2){
            int aa, sum = 0; sd(aa);
            foreach(it, sets[aa]){
                sum += a[*it];
                if(sum >= MOD) sum -= MOD;
            }
            printf("%d\n",sum);
        }
        else if(t == 3){
            int l, r, val; sd3(l,r,val);
            for(int i = l; i <= r; i++){
                a[i] += val;
                if(a[i] >= MOD) a[i] -= MOD;
            }
        }
        else{
            int l, r, sum = 0; sd2(l,r);
            for(int i = l; i <= r; i++){
                sum += a[i];
                if(sum >= MOD) sum -= MOD;
            }
            printf("%d\n",sum);
        }
        
//        for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
    }
    
	return 0;
}
