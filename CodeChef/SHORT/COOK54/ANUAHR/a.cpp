#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int t, n, m, l, b;
multiset<int> mymap;
vector<pair<int, int> > a;
long long ans;
int main(){
	sd(t);
	while(t--){
		sd2(n,m);
		
		if(m == n) m--;
		
		mymap.clear();
		a.clear();
		
		for(int i = 0; i < n; i++){
			sd2(l,b);
			a.push_back(make_pair(l,b));
			mymap.insert(b);
		}
		
		sort(a.begin(), a.end());
		
		for(int i = 0; i < m; i++){
			mymap.erase(mymap.find(a[i].se));
		}
		
		ans = 0;
		
		for(int i = m-1; ; i--){
			//cout<<a[i+1].fi<<" "<<mymap.begin()->first<<endl;
			ans = max(ans, (long long)a[i+1].fi * (*(mymap.begin())));
			
			if(i == -1) break;
			
			mymap.insert(a[i].se);
			mymap.erase(mymap.begin());
		}
		
		printf("%lld\n",ans);
		
	}
	return 0;
}
