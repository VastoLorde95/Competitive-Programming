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

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

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

typedef long long ll;

ll n, k, a[200100], ans[200100], inf = 100000000;

int aux[200100];
vector<pair<long long, int> > p;
vector<int> cnt;
vector<pair<int, int> > res[200100];

int main(){
	sd2(k,n);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(a[i]%k == 0) ans[i] = i; else ans[i] = inf;
	}
	
	ll tmp = k;
	int cc = 0;
	
	while(tmp%2 == 0){
		tmp /= 2;
		cc++;
	}
	if(cc){
		p.pb(mp(2,cc));
	}
	
	
	cc = 0;
	while(tmp%3 == 0){
		tmp /= 3;
		cc++;
	}
	if(cc){
		p.pb(mp(3,cc));
	}
	
	for(ll i = 5; i*i <= tmp; i += 6){
		if(tmp%i == 0){
			cc = 0;
			while(tmp%i == 0){
				tmp /= i;
				cc++;
			}
			p.pb(mp(i,cc));
		}
		
		
		i += 2;
		
		if(tmp%i == 0){
			cc = 0;
			while(tmp%i == 0){
				tmp /= i;
				cc++;
			}
			p.pb(mp(i,cc));
		}
		i -= 2;
		
	}
	if(tmp > 1){
		if(tmp == k and k > (ll)1e15){
			cout << "None\n";
			return 0;
		}
		p.pb(mp(tmp,1));
	}	
		
	ll l;
	cnt.resize(n+1);	
	for(int i = 0; i < p.size(); i++){
		cnt[0] = 0;
		for(int j = 1; j <= n; j++){
			cnt[j] = cnt[j-1];
			while(a[j]%p[i].fi == 0){
				a[j] /= p[i].fi;
				cnt[j]++;
			}
		}
		
		for(int j = 1; j <= n; j++){
			if(cnt[j] >= p[i].se){
				l = lower_bound(cnt.begin(), cnt.end(), cnt[j] - p[i].se+1) - cnt.begin();
				ans[j] = min(ans[j], l);
				aux[j]++;
			}
		}

	}
	
	for(int i = 1; i <= n; i++){
		if(aux[i] == p.size()){
			res[i-ans[i]+1].pb(mp(ans[i], i));
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(res[i].size() > 0){
			sort(res[i].begin(), res[i].end());
			printf("Minimum interval length: %d\n",i);
			printf("Found intervals:\n");
			foreach(it, res[i]){
				printf("[%d, %d]\n", it->fi, it->se);
			}
			return 0;
		}
	}
	
	cout << "NONE\n";
	
	return 0;
}
