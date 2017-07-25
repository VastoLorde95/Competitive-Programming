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

int n, q;
long long a[100100];
long long MOD = 1e9 + 7;

int main(){
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	while(q--){
		int t, l, r, v;
		cin >> t;
		if(t == 1){
			cin >> l >> r >> v;
			l--, r--;
			for(int i = l; i <= r; i++) a[i] = (a[i]+v)%MOD;
		}
		else if(t == 2){
			cin >> l >> r >> v;
			l--, r--;
			for(int i = l; i <= r; i++) a[i] = (a[i]*v)%MOD;
		}
		else if(t == 3){
			cin >> l >> r >> v;
			l--, r--;
			for(int i = l; i <= r; i++) a[i] = v;
		}		
		else{
			cin >> l >> r; long long vv = 0;
			l--, r--;
			for(int i = l; i <= r; i++){
//				tr2(i, a[i]);
				vv = (vv + a[i])%MOD;
			}
			printf("%lld\n", vv);
		}
		
//		for(int i = 0; i < n; i++){
//			tr3("check",i, a[i]);
//		}
//		cout << endl;
	}
	return 0;
}
