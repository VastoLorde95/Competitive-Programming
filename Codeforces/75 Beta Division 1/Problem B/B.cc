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

int n, x, res[100001];
vector<pair<int, int> > a, in;
set<int> pos;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(x);
		a.pb(mp(x,-i));
	}
	
	sort(a.begin(), a.end());
	
	res[-a[0].se] = -1;
	
	for(int i = 1; i < n; i++){
		if(a[i].fi != a[i-1].fi){
			in.pb(a[i-1]);
			for(int j = 0; j < in.size(); j++)
				pos.insert(in[j].se);
			in.clear();
		}
		else{
			in.pb(a[i-1]);
		}
		
		if(pos.size() == 0){
			res[-a[i].se] = -1;
		}
		else{
			x = -(*(pos.begin()));
			if(x < -a[i].se)
				res[-a[i].se] = -1;
			else
				res[-a[i].se] = x + a[i].se-1;
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", res[i]);
	}
	printf("\n");
		
	return 0;
}
