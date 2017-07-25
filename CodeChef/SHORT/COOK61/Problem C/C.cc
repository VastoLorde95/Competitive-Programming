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

int t, n, k, l, a[16];
long long MOD = 1e9 + 7;

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	sd(t);
	while(t--){
		sd3(n,k,l);
		for(int i = 0; i < n; i++) sd(a[i]);
		
		vector<int> v;
		long long ans = 0;
		
		for(int i = 0; i < (1<<n); i++){
			if(__builtin_popcount(i) == l){
				v.pb(i);
			}
		}
		
		for(int i = 0; i < v.size(); i++){
			set<int> tmp;
			vector<int> d;
			
			tr2("$",v[i]);
			
			for(int j = 0; j < n; j++){
				if((v[i]&(1<<j)) > 0){
					tmp.insert(a[j]);
					d.pb(k-tmp.size());
					tmp.clear();
					tmp.insert(a[j]);
				}
				else{
					tmp.insert(a[j]);
					d.pb(k-tmp.size());
				}
			}			
			d.pb(k-tmp.size());
			
			foreach(it, d){
				cout << *it << " ";
			}
			cout << endl;
			
			for(int j = 0; j < v.size(); j++){
				tr2("#",v[j]);
				int cnt = 0;
				long long tmpp = 1;
				for(int k = 0; k < n; k++){
					if((v[j]&(1<<k)) > 0){
						if(cnt > 0){
							tmpp = (tmpp * fast(d[k],cnt))%MOD;
							cnt = 0;
						}
					}
					else{
						cnt++;
					}
				}
				tmpp = (tmpp * fast(d[n],cnt))%MOD;
				ans = (ans + tmpp)%MOD;
			}
		}
		
		printf("%lld\n", ans);
		
	}
	return 0;
}
