#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int t, n, k, cnt[28];

int main(){ _
	cin >> t;
	while(t--){
		cin >> n >> k;
		memset(cnt, 0, sizeof cnt);
		int mn = 0;
		for(int i = 1; i <= k; i++){
			if(i%2) mn += 1, cnt[i] = 1;
			else mn += 2, cnt[i] = 2;
		}
		
		if(mn > n){
			cout << "No such string.\n";
			continue;
		}
		
		else{
			if((n-mn)%2 == 0){
				cnt[1] += n-mn;
			}
			else{
				cout << "No such string.\n";
				continue;
			}
		}

		string res;		
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < cnt[i]; j++){
				res += char(i+'a'-1);
			}
		}
		cout << res << "\n";
		
	}
	return 0;
}
