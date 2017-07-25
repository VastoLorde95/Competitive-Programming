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

long long t, n, l, r, a, cnt, tot;

int main(){ _
    cin >> t;
	while(t--){ 
		cin >> n >> l >> r;
        
		cnt = 0, tot = 0;		// cnt is the number of good elements, tot is the total number of operations performed till now
        vector<long long> d, o; // d are the differences, o is the vector which has all the outputs
        
		for(int i = 0; i < n; i++){
			cin >> a;
			if(l <= a and a <= r) cnt++;
            else d.pb(min(abs(a-l),abs(a-r)));
		}	
		
        
        sort(d.begin(), d.end());
        
		for(long long i = n, j = 0; i >= 1; i--){
			if(cnt >= n-i+1) o.pb(tot);
            else{
                while(cnt < n-i+1){
                    tot += d[j];
                    j++;
                    cnt++;
                }
                o.pb(tot);
            }
		}
        
        for(long long i = o.size()-1; i >= 0; i--){
            cout << o[i] << " ";
        }
		cout << endl;
	}
	return 0;
}
