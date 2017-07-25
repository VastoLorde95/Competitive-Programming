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

int n, k, a[100100], ok[100100];
vector<int> f[100100];
vector<int> ind[100100];
vector<int>::iterator it, jt;
int prev = -1, last = -1;
long long ans;

int main(){
	sd2(n,k);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		if(a[i] >= k){
			f[a[i]-k].pb(i);
		}
		ok[a[i]] = 1;
	}
	
	for(int i = 1; i <= 100000; i++){
		if(ok[i])
			for(int j = i; j <= 100000; j += i){
				ind[i].insert(ind[i].end(), f[j].begin(), f[j].end());
			}
	}
	
	for(int i = 1; i <= 100000; i++){
		sort(ind[i].begin(), ind[i].end());
		f[i].clear();
	}
	
	ans = 1;
	
	for(int i = 1; i < n; i++){
		
		if(a[i] <= k or (ind[a[i]].size() == 0 and f[0].size() == 0)){
			ans += (i-prev);
			continue;
		}
		
		it = lower_bound(ind[a[i]].begin(), ind[a[i]].end(), i);
		jt = lower_bound(f[0].begin(), f[0].end(), i);
		if(it == ind[a[i]].begin() and jt == f[0].begin()){
			ans += (i-prev);
		}
		else{
			if(it != ind[a[i]].begin()){
				it--;
				if(*it < i) prev = max(prev, *it);
			}
			if(jt != f[0].begin()){
				jt--;
				if(*jt < i) prev = max(prev, *jt);
			}
			ans += (i-prev);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
